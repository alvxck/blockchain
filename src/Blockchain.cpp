#include "Blockchain.h"

// Initialize blockchain with genesis block
Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

// Add block to blockchain
void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

// Returns last block in blockchain
Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}