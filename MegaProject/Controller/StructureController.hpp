//
//  StructureController.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 2/8/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef StructureController_hpp
#define StructureController_hpp

#include "../Model/Node.hpp"
#include "Array.hpp"
#include "../Model/Queue.hpp"
#include "../Model/Meme.hpp"
#include <string>
#include "List.h"
#include "Timer.hpp"
#include "DoubleList.hpp"
#include "Stack.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

class StructureController
{
private:
    Node<int> numberNode;
    Node<string> wordNode;
    Array<int> numberArray;
    List<int> sample;
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testAdvancedFeatures();
    void testList();
    void testDoubleList();
    void testMemeQueue();
    void testNumberStack();
    void testDoubleListTiming();
    void testBinarySearchTree();
public:
    StructureController();
    void start();
    
};

#endif /* StructureController_hpp */
