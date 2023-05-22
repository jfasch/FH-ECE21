#include <vector>

#include <gtest/gtest.h>


TEST(vector_comprehension, basic)
{
    std::vector<int> v;
    ASSERT_EQ(v.size(), 0);

    v.push_back(42);
    v.push_back(666);

    ASSERT_EQ(v.size(), 2);
}
