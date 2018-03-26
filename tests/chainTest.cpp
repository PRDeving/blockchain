#include "gtest/gtest.h"
#include "chain.hpp"

using namespace Blockchain;
class chainTest : public ::testing::Test {
  protected:
    virtual void SetUp() { }
    virtual void TearDown() { }
    Chain blockchain;
    struct Block GenesisBlock = {
      0,
      "20f29bda67e3c9b8ece15e0aff49196a9e054b977fe1a5cc552eb744066b9cce",
      "1234",
      0,
      "owner",
      "signature",
      "Genesis"
    };
};


TEST_F(chainTest, constructor) {
  ASSERT_EQ(blockchain.getLength(), 1);
}

TEST_F(chainTest, GenesisBlock) {
  struct Block genesis = blockchain.getGenesis();
  ASSERT_EQ(genesis.timestamp, 0);
  ASSERT_EQ(atoi(genesis.hash.c_str()), 0);
  ASSERT_STREQ(genesis.previous.c_str(), GenesisBlock.previous.c_str());
  ASSERT_STREQ(genesis.data.c_str(), GenesisBlock.data.c_str());
}

TEST_F(chainTest, add) {
  struct Block genesis = blockchain.getGenesis();
  struct Blockchain::Block block = {
    0,
    "",
    "",
    0,
    "owner",
    "signature",
    "second"
  };
  blockchain.add(block);
  struct Block *last = blockchain.getLast();

  ASSERT_EQ(last -> index, 1);
  ASSERT_TRUE(last -> hash.c_str());
  ASSERT_STREQ(last -> previous.c_str(), genesis.hash.c_str());
  ASSERT_EQ(blockchain.getLength(), 2);
}

TEST_F(chainTest, resize) {
  struct Block genesis = blockchain.getGenesis();
  ASSERT_EQ(blockchain.getLength(), 1);
  blockchain.add(GenesisBlock);
  blockchain.add(GenesisBlock);
  blockchain.add(GenesisBlock);
  blockchain.add(GenesisBlock);
  ASSERT_EQ(blockchain.getLength(), 5);
}
