#include <sensor-avg.h>
#include <sensor-const.h>
#include <sensor-random.h>
#include <sensor-w1.h>

#include <iostream>


int main()
{
    // RandomSensor rs1(10, 20);
    // RandomSensor rs2(20, 30);
    // ConstantSensor cs1(37.5);
    // ConstantSensor cs2(-273.15);

    W1Sensor w1("/sys/class/hwmon/hwmon5/temp1_input");
    W1Sensor w2("/sys/class/hwmon/hwmon5/temp2_input");
    W1Sensor w3("/sys/class/hwmon/hwmon5/temp3_input");
    W1Sensor w4("/sys/class/hwmon/hwmon5/temp4_input");
    W1Sensor w5("/sys/class/hwmon/hwmon5/temp5_input");

    
    AveragingSensor as;
    // as.add(&rs1);
    // as.add(&rs2);
    // as.add(&cs1);
    // as.add(&cs2);
    as.add(&w1);
    as.add(&w2);
    as.add(&w3);
    as.add(&w4);
    as.add(&w5);
    
    std::cout << as.get_temperature() << std::endl;
    std::cout << as.get_temperature() << std::endl;

    return 0;
}
