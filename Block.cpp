#include "Block.hpp"
#include "sha256.hpp"
#include <vector>
#include <ctime>
#include <sstream>

// Block implementation
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

// Returns hash of current block
string Block::GetHash() {
    return _sHash;
}

// Block mining implementation (PoW : Proof of work)
void Block::MineBlock(uint32_t nDifficulty) {
    vector<char> cstr(nDifficulty, '0');

    string str(cstr.begin(), cstr.end());

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block Mined: " << _sHash << endl;
}

// Creates and returns hash
inline string Block::_CalculateHash() const {
    stringstream raw;
    raw << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(raw.str());
}