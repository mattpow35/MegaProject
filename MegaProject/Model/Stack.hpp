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
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type data);
    
};
template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}


template <class Type>
Stack<Type> :: ~Stack()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}
/**
 The add method on a stack only adds to the end, never at an index.
 */
template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}


/*
 1. creates a new node
 2. if the stack is empty sets front to the new node
 3. else setss the end's next to point to the new node and the new nodes previous to end.
 4. move end to the new node.
 5. increases the size by 1.
 */
template <class Type>
void Stack<Type> :: push(Type valueToAdd)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode<Type>(valueToAdd);
    
    if(this->getSize() == 0)
    {
        this->setFront(addToStack);
        
    }
    else
    {
        this->getEnd()->setNextPointer(addToStack);
        addToStack->setPreviousPointer(this->getEnd());
       
    }
    this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
}
/*
 used to avoid abstract status.
 asserts that the size is correct and calls the pop method.
 */
template <class Type>
Type Stack<Type> :: remove(int index)
{
    assert(index == this->getSize() - 1 && this->getSize() > 0);
    return pop();
}

template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->getSize() > 0);
    return this->getEnd()->getNodeData();
}
/*
 1. assert size > 0.
 2. get data from end node.
 3. move end to ends previous.
 4. delete old end node.
 5. decrease size.
 6. return data from old end.
 */
template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0 );
    Type removed = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type> * update = this->getEnd();
    update = update->getPreviousPointer();
    
    if(update != nullptr)
    {
        update->setNextPointer(nullptr);
    }
    else
    {
        this->setFront(nullptr);
    }
    
    delete this->getEnd();
    
    this->setEnd(update);
    
    this->setSize(this->getSize() - 1);
    
    return removed;
    
}









#endif /* Stack_h */
