#include <sensor-w1.h>

#include <iostream>
#include <string>
#include <iostream>


int main(int argc, char** argv)
{
    if (! (argc == 3 || argc == 4)) {
        std::cerr << argv[0] <<  " <filename> <interval>" << std::endl;
        return 42;
    }
    
    std::string filename = argv[1];
    std::string interval_str = argv[2];
    int niterations = -1;

    if (argc == 4)
        niterations = std::stoi(argv[3]);

    W1Sensor the_sensor(filename);

    int interval = std::stoi(interval_str.c_str());
    unsigned int time_remaining;

    int iteration = 0;
    while (niterations == -1 || iteration++ < niterations) {
        double temperature = the_sensor.get_temperature();
        std::cout << temperature << std::endl;

        time_remaining = sleep(interval);
        if (time_remaining != 0)
            std::cerr << "did not sleep " << interval << " seconds, " << time_remaining << " remaining" << std::endl;
    }

    return 0;
}
