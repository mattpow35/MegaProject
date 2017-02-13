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
    Node<Type>* nodePointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type>* nextPointer);
    
    Type getNodeData();
    Node<Type>* getNodePointer();
    void setNodeData(Type value);
    void setNodePointer(Node<Type>* nextPointer);
};

/*
 Implementation section of hte templated class!
 */

//Constructors
template <class Type>
Node<Type> :: Node()
{
    nodePointer = nullptr;
    //Explicityly NOT initializing nodeData
    //Because the type is unknown to me. It could be anything.
}

template <class Type>
Node<Type> :: Node(Type value)
{
    this->nodeData = value;
    this->nodePointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type>* nextNode)
{
    this->nodeData = value;
    this->nodePointer = nextNode;
}


//Accesors aka getters/setters
template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
Node<Type>* Node<Type> :: getNodePointer()
{
    return nodePointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type value)
{
    this->NodeData = value;
}

template <class Type>
void Node<Type> :: setNodePointer(Node<Type>* nextPointer)
{
    this->nodePointer = nextPointer;
}

#endif /* Node_hpp */


