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
    IntNode * nodePointer;
    
public:
    int getNodeData();
    IntNode* getNodePointer();
    void setNodeData(int);
    void setNodePointer(IntNode*);
    
    IntNode();
    IntNode(int);
    IntNode(int, IntNode*);
    
};

#endif /* IntNode_hpp */
