
#include "../src/lib.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_TRUE(version() > 0);
}

//BOOST_AUTO_TEST_SUITE(test_version)

//BOOST_AUTO_TEST_CASE(test_valid_version)
//{
//    BOOST_CHECK(version() > 0);
//}

//BOOST_AUTO_TEST_SUITE_END()
