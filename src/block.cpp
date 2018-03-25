#include "chain.hpp"
#include "utils.hpp"

std::string Blockchain::serialize(struct Blockchain::Block &block, bool withoutHash) {
  std::string ret = ""
    + (withoutHash ? "" :(block.hash + ","))
    + block.previous + ","
    + std::to_string(block.index) + ","
    + std::to_string(block.timestamp) + ","
    + block.owner + ","
    + block.signature + ","
    + block.data;
  return ret;
}

std::string Blockchain::generateHash(struct Blockchain::Block &block) {
  return Crypto::sha256(Blockchain::serialize(block, true));
}

bool Blockchain::checkIntegrity(struct Blockchain::Block &block) {
  return (block.hash.c_str() && Blockchain::generateHash(block) == block.hash);
}

bool Blockchain::checkOwnership(struct Blockchain::Block &block) {
  return (Crypto::RSA::check(block.signature, block.data.c_str(), block.owner.c_str()));
}

