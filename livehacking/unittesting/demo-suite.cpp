#include <gtest/gtest.h>

TEST(demo_suite, basic_ok)
{
    // nothing happens -> passed
}

TEST(demo_suite, basic_failure)
{
    FAIL();
}

TEST(demo_suite, verify_algebra)
{
    ASSERT_EQ(1, 1);
}

TEST(demo_suite, verify_algebra_negated)
{
    ASSERT_NE(1, 2);
}

