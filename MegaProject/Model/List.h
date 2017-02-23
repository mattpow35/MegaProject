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
    

#endif /* List_h */
