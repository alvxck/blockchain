# Blockchain

A simple blockchain implementation with C++.

## Overview

The blockchain is a linked list composed of blocks, with each new block containing: 

- user data 
- timestamp 
- previous block hash

Each new block is validated by a proof of work algorithm using sha256. The hash difficulty can vary based on the  `_nDifficulty` parameter within `Blockchain.h`.

## Functionality

The following is the process of adding a new block to the blockchain:

1. Genesis block is created with a default value of 0.
2. User passes data to uninitialized block.
3. New hashs are generated based on user data, timestamp, and previous block hash.
4. Once a valid hash is found (based on `_nDifficulty`), the block is added to the blockchain.
