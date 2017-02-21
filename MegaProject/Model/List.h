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
    Node<Type.* front;
public:
    //constructor
    List<Type>();
    //copy constructor
    List<Type>(const List<Type> & source);
    //destructor
    ~List<Type>();
    
    //Methods
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
    int getSize() const;
    Node<Type>* getFront() const;
};

#endif /* List_h */
