#include "Blockchain.h"

// Initialize blockchain with genesis block
Blockchain::Blockchain() {
    cout << "-> Initialize blockchain" << endl;

    _bGenesisBlock = new Block(0, "Genesis Block");
    _bLast = _bGenesisBlock;
    _nDifficulty = 2;
}

// Add block to blockchain
void Blockchain::AddBlock(Block bNew) {
    cout << "-> Adding block" << endl;

    _bLast->_bNext = &bNew;
    bNew._bPrev = _bLast;

    bNew.sPrevHash = _bLast->GetHash();
    bNew.MineBlock(_nDifficulty);

    _bLast = &bNew;
}