#include <gtest/gtest.h>

#include <vector>


class NFCEventTracker
{
public:
    bool is_duplicate_event(unsigned long nfc_id, unsigned long timestamp)
    {
        std::map<unsigned long/*nfc id*/, unsigned long/*timestamp*/>::const_iterator last = _last_events.find(nfc_id);
        if (last != _last_events.end()) {
            unsigned long last_timestamp = last->second;
            if (timestamp - last_timestamp < 1000)
                return true;
        }
        _last_events[nfc_id] = timestamp;
        return false;
    }

    void clear() { _last_events.clear(); }

private:
    std::map<unsigned long/*nfc id*/, unsigned long/*timestamp*/> _last_events;
};

TEST(felber_suite, sunny)
{
    NFCEventTracker tracker;

    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 666, /*ts in ms seit boot*/1234567), 
              false);
    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 667, /*ts in ms seit boot*/1234580),
              false);
}

TEST(felber_suite, no_duplicates_for_same_id)
{
    NFCEventTracker tracker;

    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 666, /*ts in ms seit boot*/1000),
              false);
    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 666, /*ts in ms seit boot*/1100), // 100 ms later
              true);
}

TEST(felber_suite, no_duplicates_for_different_ids)
{
    NFCEventTracker tracker;

    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 666, /*ts in ms seit boot*/1000),
              false);
    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 667, /*ts in ms seit boot*/1000),
              false);

    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 666, /*ts in ms seit boot*/1100),
              true);
    ASSERT_EQ(tracker.is_duplicate_event(/*nfc-id*/ 667, /*ts in ms seit boot*/1100),
              true);
}

TEST(felber_suite, rate_limit)
{
    NFCEventTracker tracker;

    ASSERT_EQ(tracker.is_duplicate_event(666, 1000), false);
    ASSERT_EQ(tracker.is_duplicate_event(666, 1100), true);
    ASSERT_EQ(tracker.is_duplicate_event(666, 2000), false);
    ASSERT_EQ(tracker.is_duplicate_event(666, 2100), true);
}

TEST(felber_suite, clear)
{
    NFCEventTracker tracker;

    ASSERT_EQ(tracker.is_duplicate_event(666, 1000), false);
    ASSERT_EQ(tracker.is_duplicate_event(666, 1100), true);

    tracker.clear();
    ASSERT_EQ(tracker.is_duplicate_event(666, 1200), false);
}
