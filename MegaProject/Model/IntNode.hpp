//
//  IntNode.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 2/6/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nextPointer;
public:
    //constructors
    IntNode();
    IntNode(int value);
    /*
     Creates an IntNode with a specified value and reference to the next node.
     */
    IntNode(int value, IntNode* nextNode);
    
    //methods
    int getNodeData();
    IntNode* getNextPointer();
    
    void setNodeData(int value);
    void setNextPointer(IntNode* updatedNode);
    
};

#endif /* IntNode_hpp */
