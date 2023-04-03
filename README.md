# Blockchain

## Overview

This is a simple blockchain implementation in C++. The chain is a linked list of blocks, with each new block composed of: 

- user data
- timestamp
- previous block hash
- new block hash

Each new block is validated by a proof of work algorithm, which is a simple sha256 hash. The hash difficulty can vary based on the  `_nDifficulty` parameter within `Blockchain.h`.