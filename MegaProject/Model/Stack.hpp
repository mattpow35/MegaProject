//
//  Stack.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 3/1/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "DoublyLinkedList.hpp"

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:
public:
    Stack();
    void add(Type value);
    
};
/**
 The add method on a stack only adds to the end
 never at an index.
 */
template <class Type>
void Stack<Type> :: add(Type value) : DoublyLinkedList<Type> :: add(value)
{
    
}

#endif /* Stack_h */
