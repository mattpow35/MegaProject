//
//  Array.hpp
//  MegaProject
//
//  Created by Matt Powley on 2/20/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <assert.h>
#include "Node.hpp"

template <class Type>
class Array
{
private:
    Node<Type> * front;
    int size;
public:
    //constructor
    Array<Type>();
    Array<Type>(int size);
    
    //Destructor
    ~Array<Type>();
    //Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    //Assignment Operator overload
    
    //Methods
    int getSize() const;
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
};

//Implementation section

//Creates an array of specified size by linking Node<Type> together
template <class Type>
Array<Type> :: Array()
{
    //DO NOT USE!!!!
    //implemented for compilation purposes
}


template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    this->front = new Node<Type>();
    
    for(int index = 1; index < size; index++)
    {
        Node<Type> * currentNode = new Node<Type>();
        currentNode->setNodePointer(front);
        front = currentNode;
    }
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    return value;
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int position =0; position < index; position ++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
}

template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}

template <class Type>
Node<Type> * Array<Type> :: getFront() const
{
    return front;
}










#endif /* Array_hpp */
