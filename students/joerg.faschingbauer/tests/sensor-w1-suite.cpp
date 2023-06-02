#include <gtest/gtest.h>

#include <sensor-w1.h>

#include <cstdlib>
#include <unistd.h>

#include <stdexcept>

using namespace std;


// fixture class: supply a temporary file, plus a method
// write_temperature() thaht derived classes can call
struct w1_sensor_suite : public ::testing::Test
{
    void SetUp() override
    {
        char filename_pattern[] = "w1_sensor_suite-XXXXXX";
        
        fd = mkstemp(filename_pattern);
        if (fd == -1)
            throw runtime_error("nix mkstemp()");

        filename = filename_pattern;
    }

    void TearDown() override
    {
        if (fd != -1) {
            close(fd);
            unlink(filename.c_str());
        }
    }

    void change_temperature(double temperature)
    {
        unsigned temp_milli = temperature * 1000;

        string content = to_string(temp_milli);

        off_t pos = ::lseek(fd, 0, SEEK_SET);
        ASSERT_EQ(pos, 0);

        ssize_t nwritten = ::write(fd, content.c_str(), content.size());
        ASSERT_EQ(nwritten, content.size());
    }


    int fd;
    string filename;
};

TEST_F(w1_sensor_suite, test_read_sensor)
{
    W1Sensor sensor(filename);                 // <--- using filename from w1_sensor_suite fixture
    double temperature;

    change_temperature(42.666);                // <--- change temperature
    temperature = sensor.get_temperature();    // <--- read temperature
    ASSERT_FLOAT_EQ(temperature, 42.666);

    change_temperature(36.5);                  // <--- change temperature
    temperature = sensor.get_temperature();    // <--- read temperature
    ASSERT_FLOAT_EQ(temperature, 36.5);
}
