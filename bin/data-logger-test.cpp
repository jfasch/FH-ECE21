#include <sensor-config.h>
#include <sensor-const.h>
#include <sensor-random.h>
#include <data-logger.h>

#include <sink-terminal.h>
#include <iostream>


int main()
{
    // ...
    RandomSensor rd1(1, 10);
    RandomSensor rd2(1 ,10);
    SensorConfig cfg;
    cfg.addSensor("Random1", &rd1);
    cfg.addSensor("Random2", &rd2);
    cfg.addSensor("Random3", &rd2);
    SinkTerminal sink;

    DataLogger logger(&cfg, &sink, 1000);

    logger.startLogging();

    return 0;
}
