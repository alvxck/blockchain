#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

class Block {
    private:
        uint32_t _nIndex;
        int64_t _nNonce;
        std::string _sData;
        std::string _sHash;
        time_t _tTime;

        std::string _CalculateHash() const;

    public:
        Block* _bNext = nullptr;
        Block* _bPrev = nullptr;
        std::string sPrevHash;
        Block (uint32_t nIndexIn, const std::string &sDataIn);
        std::string GetHash();
        void MineBlock(uint32_t nDifficulty);

};

#endif
