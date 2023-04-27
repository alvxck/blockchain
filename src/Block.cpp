#include "Block.h"
#include "sha256.h"
#include <vector>
#include <ctime>
#include <sstream>

// Block implementation
Block::Block(uint32_t nIndexIn, const std::string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
    _bNext = nullptr;
    _bPrev = nullptr;
}

// Returns hash of current block
std::string Block::GetHash() {
    std::cout << "-> Getting hash" << std::endl;

    return _sHash;
}

// Block mining implementation (PoW : Proof of work)
void Block::MineBlock(uint32_t nDifficulty) {
    std::cout << "-> Mining block" << std::endl;

    std::vector<char> cstr(nDifficulty, '0');

    std::string str(cstr.begin(), cstr.end());

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    std::cout << "-> Block Mined: " << _sHash << std::endl;
}

// Creates and returns hash
inline std::string Block::_CalculateHash() const {
    std::stringstream raw;
    raw << _nIndex << _tTime << _sData << _nNonce << sPrevHash << _bPrev;

    return sha256(raw.str());
}