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
    Node<Type>(Type data, node<Type>* nextPointer);
    
    Type getNodeData();
    Node<Type>* getNodePointer(0);
    void setNodeData(Type value);
    void setNodePointer(Node<Type>* nextPointer);
};
#endif /* Node_hpp */
