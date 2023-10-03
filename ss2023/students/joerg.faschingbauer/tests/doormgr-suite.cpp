#include <gtest/gtest.h>

#include <switch-sysfs.h>   // <--- to be created
#include <doormgr.h>        // <--- to be created


TEST(doormgr_suite, open_sunny)
{
    // prepare closed door
    Switch SC(1, Switch::INPUT, Switch::ON); // input
    Switch SO(2, Switch::INPUT, Switch::OFF); // input
    Switch SU(3, Switch::INPUT, Switch::OFF); // input
    Switch SL(4, Switch::OUTPUT, Switch::OFF); // output
    Switch SR(5, Switch::OUTPUT, Switch::OFF); // output
    DoorManager door(SC, SO, SU, SL, SR);

    ASSERT_EQ(door.state() == DoorManager::CLOSED);

    SU.on();

    ASSERT_EQ(door.state(), DoorManager::OPENING);
    ASSERT_TRUE(SR.is_on());
    ASSERT_TRUE(SL.is_off());

    SU.off(); // user releases button
    SC.off(); // closed-switch released by opening door

    // ... door opening 10 secs ...
    
    SO.on(); // door physically open

    ASSERT_EQ(door.state() == DoorManager::OPEN);
    ASSERT_TRUE(SR.is_off());
    ASSERT_TRUE(SL.is_off());
}

TEST(doormgr_suite, close_sunny)
{
    // prepare open door
    Switch SC(1, Switch::INPUT, Switch::OFF); // input
    Switch SO(2, Switch::INPUT, Switch::ON); // input
    Switch SU(3, Switch::INPUT, Switch::OFF); // input
    Switch SL(4, Switch::OUTPUT, Switch::OFF); // output
    Switch SR(5, Switch::OUTPUT, Switch::OFF); // output
    DoorManager door(SC, SO, SU, SL, SR);

    ASSERT_EQ(door.state() == DoorManager::OPEN);

    SU.on();

    ASSERT_EQ(door.state(), DoorManager::CLOSING);
    ASSERT_TRUE(SR.is_off());
    ASSERT_TRUE(SL.is_on());

    SU.off(); // user releases button
    SO.off(); // closed-switch released by opening door

    // ... door closing 10 secs ...
    
    SC.on(); // door physically closed

    ASSERT_EQ(door.state() == DoorManager::CLOSED);
    ASSERT_TRUE(SR.is_off());
    ASSERT_TRUE(SL.is_off());
}
