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

templat <class Type>
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
List<Type> :: List<Type>()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}
    
template <class Type>
List<Type> :: List<Type>(const List<Type> & source)
{
        
}

template <class Type>
List<Type> :: ~List<Type>()
{
        
}
    
tempalate <class Type>
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
        //newFirst->setNodePointer(front);
        
        //front now will point to the new node.
        front = newFirst;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addEnd(Type value)
{
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setNodePointer(added);
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
            current = current->getNodePointer();
        }
        
        previous->setNodePointer(insertedNode);
        insertedNode->setNodePointer(current);
    
        size++;
    }
}

#endif /* List_h */
