#include "gtest/gtest.h"
#include "utils.hpp"

class utilsTest : public ::testing::Test {
  protected:
    virtual void SetUp() { }
    virtual void TearDown() { }
};


TEST_F(utilsTest, timestamp) {
  ASSERT_TRUE(Utils::timestamp() > 0);
}
