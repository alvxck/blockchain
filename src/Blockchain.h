#ifndef BLOCKCHAIN_BLOCKCHAIN_HPP
#define BLOCKCHAIN_BLOCKCHAIN_HPP

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
    private:
        Block* _bGenesisBlock;
        Block* _bLast;
        uint32_t _nDifficulty;

    public:
        Blockchain();
        void AddBlock(Block bNew);
};

#endif