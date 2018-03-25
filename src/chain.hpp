#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <string>
#include <vector>
#include "crypto/crypto.hpp"


namespace Blockchain {
  struct Block {
    long long index;
    std::string hash;
    std::string previous;
    unsigned int timestamp;
    std::string owner;
    std::string signature;
    std::string data;
  };

  std::string serialize(struct Block &block, bool withoutHash = false);
  bool checkIntegrity(struct Block &block);
  bool checkOwnership(struct Block &block);
  std::string generateHash(struct Block &block);


  class Chain {
    public:
      Chain();
      bool add(struct Block block);
      void printLast();

      int getLength() { return list.size(); };
      struct Block *getLast() { return &list.back(); };
      struct Block getGenesis() { return list[0]; };

    private:
      void resize();
      bool insert(struct Block block);
      std::vector<struct Block> list;
  };
}

#endif
