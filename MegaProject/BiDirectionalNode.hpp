//
//  BiDirectionalNode.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 2/27/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    Type data;
    BiDirectionalNode<Type> * next;
    BiDirectionalNode<Type> * previous;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
    
    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node()
{
    next = nullptr;
    previous = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node(data)
{
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next)
{
    this->data = data;
    this->previous = previous;
    this->next = next;
}

template <class Type>
Type BiDirectionalNode<Type> :: getNodeData();
{
    return data;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer();
{
    return next;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getPreviousPointer();
{
    return previous;
}

template <class Type>
void BiDirectionalNode<Type> :: setNodeData(Type value)
{
    this->data = value;
}

template <class Type>
void BiDirectionalNode<Type> :: setNextPointer(BiDirectionalNode<Type> * next)
{
    this->next = next;
}

template <class Type>
void BiDirectionalNode<Type> :: setPreviousPointer(BiDirectionalNode<Type> * previous)
{
    this->previous = previous;
}













#endif /* BiDirectionalNode_h */
