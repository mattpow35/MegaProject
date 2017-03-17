//
//  List.h
//  MegaProject
//
//  Created by Powley, Matthew on 2/21/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>
#include "Node.hpp"

template <class Type>
class List
{
private:
    int size;
    Node<Type>* front;
    Node<Type>* end;
public:
    //constructor
    List<Type>();
    //copy constructor
    List<Type>(const List<Type> & source);
    //destructor
    ~List<Type>();
    
    //Methods
    void addAtIndex(int index, Type value);
    void addFront(Type value);
    void addEnd(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
    
    int getSize() const;
    Node<Type>* getFront() const;
    Node<Type>* getEnd() const;
};
    

    
template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}
    
template <class Type>
List<Type> :: List(const List<Type> & source)
{
        
}

template <class Type>
List<Type> :: ~List<Type>()
{
    Node<Type> * destruction = front;
    while(front != nullptr)
    {
        front = front->getNextPointer();
        delete destruction;
        destruction = front;
    }
}

template <class Type>
int List<Type> :: getSize() const
{
    return this->size;
}

    
template <class Type>
void List<Type> :: addFront(Type value)
{
    //default case when adding to an empty list.
    if(size == 0)
    {
        //create thew new node giving it value from method parameter.
        Node<Type> * first = new Node<Type>(value);
        //front and end now point to the new/first/only node in the list.
        this->front = first;
        this->end = first;
    }
    //done when the list is not empty
    else
    {
        //creates the new node to be added with the value from method parameter
        //and makes it point to front.
        Node<Type> * newFirst = new Node<Type>(value, front);
        //or
        //Node<Type> * newFirst = new Node<Type>();
        //newFirst->setNodeData(value);
        //newFirst->setNextPointer(front);
        
        //front now will point to the new node.
        front = newFirst;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addEnd(Type value)
{
    Node<Type> * added = new Node<Type>(value);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setNextPointer(added);
        this->end = added;
    }
    size++;
}

//This method will add a node at an index with a certain value both passed as a parameter.
//if the size is the same as the index add to end is called.
//if the size is 0 add to front is called.
//if the index is neither at the front or end then a new node is created with the value passed in parameter.
//two more nodes are created to keep track of position in the list to find out where to add the new node.
//the node before the index is now pointing to the new node and the new node will then point to the
//next node in the list.
template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if(size == index)
    {
        addEnd(value);
    }
    else if(size == 0)
    {
        addFront(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position ++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        previous->setNextPointer(insertedNode);
        insertedNode->setNextPointer(current);
    
        size++;
    }
}

template <class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    
    if(index == 0)
    {
        toBeRemoved = front;
        front = front->getNextPointer();
        
    }
    else if(index == size - 1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        toBeRemoved = current;
        previous->setNextPointer(nullptr);
        this->end = previous;
    }
    else
    {
    
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        toBeRemoved = current;
        current = toBeRemoved->getNextPointer();
        previous->setNextPointer(current);
        
    }
    removed = toBeRemoved->getNodeData();
    
    delete toBeRemoved;
    
    size--;
    return removed;
}

template <class Type>
Type List<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    Type removedData;
    
    Node<Type> * current = front;
    
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getNextPointer();
    }
    
    removedData = current->getNodeData();
    current->setNodeData(data);
    
    return removedData;
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type information;
    
    Node<Type> * current = front;
    for (int position = 0; position < index; position ++ )
    {
        current = current->getNextPointer();
    }
    
    information = current->getNodeData();
    
    return information;
}

template <class Type>
Node<Type> * List<Type> :: getFront() const
{
    return front;
}

template <class Type>
Node<Type> * List<Type> :: getEnd() const
{
    return end;
}

template <class Type>
bool List<Type> :: contains(Type data)
{
    bool containsData = false;
    Node<Type> * current = front;
    for(int position = 0; position < size; position ++)
    {
        if(current->getNodeData() == data)
        {
            containsData = true;
            return containsData;
        }
        else
        {
            current = current->getNextPointer();
        }
            
    }
   
    return containsData;
}

#endif /* List_h */
