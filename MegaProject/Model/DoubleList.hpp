//
//  DoubleList.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 3/3/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

#include "DoublyLinkedList.hpp"

tempplate <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
};



template <class Type>
Type DoubleList<Type> :: getFromIndex(int index)
{
    
}

#endif /* DoubleList_h */
