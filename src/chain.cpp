#include "utils.hpp"
#include "chain.hpp"
#include <stdio.h>

// class Chain {
//   public:
//     Chain();
//     bool insert(struct Block block);
//
//   private:
//     struct Block *list;
//     struct Block *last;
//     unsigned int length;
// };

Blockchain::Chain::Chain() {
  struct Block GenesisBlock = {
    0,
    Crypto::sha256("genesis"),
    "1234",
    0,
    "owner",
    "signature",
    "Genesis"
  };
  list.push_back(GenesisBlock);
}

bool Blockchain::Chain::add(struct Block block) {
  block.timestamp = Utils::timestamp();
  block.index = getLength();
  block.previous = list[getLength() - 1].hash;
  block.hash = generateHash(block);
  list.push_back(block);
  return true;
}

void Blockchain::Chain::printLast() {
  struct Block *last = getLast();
  printf("\n\nidx: %lld\nhash: %s\nprev: %s\nts: %d\nown: %s\nsig: %s\ndata: %s\n\n",
    last -> index,
    last -> hash.c_str(),
    last -> previous.c_str(),
    last -> timestamp,
    last -> owner.c_str(),
    last -> signature.c_str(),
    last -> data.c_str());

}

