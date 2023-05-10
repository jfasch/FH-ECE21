#include <gtest/gtest.h>

#include <my-first-code.h>


TEST(test_suite, my_first_test)
{
    ASSERT_EQ(my_first_func(), 42);
}
