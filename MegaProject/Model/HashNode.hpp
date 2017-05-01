//
//  HashNode.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 5/1/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_h

template <class Type>
class HashNode
{
private:
    Type data;
    long key;
    
public:
    HashNode();
    HashNode(Type data);
    
    Type getData();
    long getKey();
    void setData();
    
};

template <class Type>
HashNode<Type> :: HashNode()
{
    this->key = rand();
}

template <class Type>
HashNode<Type> :: HashNode(Type data)
{
    this->key = rand();
    this->data = data();
}

template <class Type>
long HashNode :: getKey()
{
    return this->key;
}

template <class Type>
Type HashNode<Type> :: getData()
{
    return this->data;
}

template <class Type>
void HashNode<Type> :: setData()
{
    this->data = data;
}



#endif /* HashNode_hpp */
