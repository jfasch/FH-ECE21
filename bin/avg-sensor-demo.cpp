#include <sensor-avg.h>
#include <sensor-const.h>
#include <sensor-random.h>

#include <iostream>


int main()
{
    RandomSensor rs1(10, 20);
    RandomSensor rs2(20, 30);
    ConstantSensor cs1(37.5);
    ConstantSensor cs2(-273.15);

    AveragingSensor as;
    as.add(&rs1);
    as.add(&rs2);
    as.add(&cs1);
    as.add(&cs2);
    
    std::cout << as.get_temperature() << std::endl;
    std::cout << as.get_temperature() << std::endl;

    return 0;
}
