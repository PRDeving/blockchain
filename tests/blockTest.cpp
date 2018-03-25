#include "gtest/gtest.h"
#include "chain.hpp"

using namespace Blockchain;
class blockTest : public ::testing::Test {
  protected:
    virtual void SetUp() { }
    virtual void TearDown() { }
  public:
    struct Block block {
      100,
        "hash",
        "previous",
        200,
        "owner",
        "signature",
        "data"
    };
    const char *ser = "hash,previous,100,200,owner,signature,data";
    const char *ser_nohash = "previous,100,200,owner,signature,data";
};


TEST_F(blockTest, serialize) {
  ASSERT_STREQ(serialize(block).c_str(), ser);
}

TEST_F(blockTest, serializeNoHash) {
  ASSERT_STREQ(serialize(block, true).c_str(), ser_nohash);
}
