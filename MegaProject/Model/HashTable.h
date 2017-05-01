//
//  HashTable.h
//  MegaProject
//
//  Created by Powley, Matthew on 5/1/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <cmath>
#include <assert.h>
#include "HashNode.hpp"

using namespace std;
template <class Type>
class HashTable
{
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    HashNode<Type> * * hashTableStorage;
    
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(Type data);
    long handleCollision(Type data, long currentPosition);
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
    
};

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->hashTableStorage = HashNode<Type> * [capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
    delete [] hashTableStorage;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (this->capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(long candidateNumber)
{
    if(candidateNumber <= 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3 || candidateNumber == 5 || candidateNumber == 7)
    {
        return false;
    }
    else if(candidateNumber % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                return false;
            }
        }
        return true;
    }
}








#endif /* HashTable_h */
