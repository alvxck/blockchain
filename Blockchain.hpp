#ifndef BLOCKCHAIN_BLOCKCHAIN_HPP
#define BLOCKCHAIN_BLOCKCHAIN_HPP

#include <cstdint>
#include <vector>
#include "Block.hpp"

using namespace std;

class Blockchain {
    private:
        uint32_t _nDifficulty;
        vector<Block> _vChain;
        Block _GetLastBlock() const;

    public:
        Blockchain();
        void AddBlock(Block bNew);
};

#endif