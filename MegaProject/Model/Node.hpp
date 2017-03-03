//
//  Node.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 2/13/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type>* nextPointer;
public:
    Node();
    Node(Type data);
    Node(Type data, Node<Type> * nextPointer);
    
    Type getNodeData();
    Node<Type>* getNextPointer();
    void setNodeData(Type value);
    void setNextPointer(Node<Type>* nextPointer);
};

/*
 Implementation section of the templated class!
 */

//Constructors
template <class Type>
Node<Type> :: Node()
{
    nextPointer = nullptr;
    //Explicityly NOT initializing nodeData
    //Because the type is unknown to me. It could be anything.
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type>* nextNode)
{
    this->nodeData = value;
    this->nextPointer = nextNode;
}


//Accesors aka getters/setters
template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
Node<Type>* Node<Type> :: getNextPointer()
{
    return nextPointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type value)
{
    this->nodeData = value;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type>* nextPointer)
{
    this->nextPointer = nextPointer;
}

#endif /* Node_hpp */


