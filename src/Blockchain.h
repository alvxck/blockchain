#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

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