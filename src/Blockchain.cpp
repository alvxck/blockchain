#include "Blockchain.h"

// Initialize blockchain with genesis block
Blockchain::Blockchain() {
    cout << "-> Initialize blockchain" << endl;

    _bGenesisBlock = new Block(0, "Genesis Block");

    // _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 1;
}

// Add block to blockchain
void Blockchain::AddBlock(Block bNew) {
    cout << "-> Adding block" << endl;

    Block* _bTemp = _bGenesisBlock;
    while (_bTemp->_bNext != nullptr) {
        _bTemp = _bTemp->_bNext;
    }
    _bTemp->_bNext = &bNew;
    bNew._bPrev = _bTemp;
    
    bNew.sPrevHash = _bTemp->GetHash();
    bNew.MineBlock(_nDifficulty);
    
    // _vChain.push_back(bNew);
}