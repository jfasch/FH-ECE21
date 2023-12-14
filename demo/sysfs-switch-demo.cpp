#include <sysfs-switch.h>
#include <unistd.h>

int main()
{
    SysFS_GPIO_Switch sw(20);

    sw.configure();

    bool state = false;
    while (true) {
        sw.set_state(state);
        sleep(1);
        state != state;
    }

    return 0;
}
