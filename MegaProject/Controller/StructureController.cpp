//
//  StructureController.cpp
//  MegaProject
//
//  Created by Powley, Matthew on 2/8/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#include "StructureController.hpp"
#include <iostream>
#include "IntNodeArray.hpp"
#include "Array.hpp"
#include "List.h"

using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
    numberArray = Array<int>(1);
}

void StructureController :: testNodeTypes()
{
    cout << "Here is a string node" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is an unitilialized int ndoe" << endl;
    cout << numberNode.getNodeData() << endl;
}

void StructureController :: testIntArray()
{
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(3);
    for(int spot =0; spot < 3; spot ++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
    
    for(int spot = 0; spot < 3; spot++)
    {
        temp.setAtIndex(spot, spot);
    }
    
    for (int spot = 0; spot < temp.getSize(); spot++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
}

void StructureController :: testArrayTemplate()
{
//    cout << "ArrayTemplate" << endl;
//    int test[9];
//    numberArray = Array<int>(9);
}

void StructureController:: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if (showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These shoud match:" << endl;
    cout << words.getFromIndex(0) << " shoud be the same as " << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
}

void StructureController :: testList()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should say 1 2 3" << endl;
    
    for (int index = 0; index < sample.getSize(); index ++ )
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
    
    
}

void StructureController :: start()
{
//    cout << "Going to test the IntNodeArray" << endl;
//    testIntArray();
//    cout << "Finished IntArrayNode testing" << endl;
//    
//    cout << "Testing generic nodes" << endl;
//    testNodeTypes();
//    cout << "done testing generic nodes" << endl;
    
//    cout << "testing advanced features." << endl;
//    testAdvancedFeatures();
//    cout << "done testing advanced features." << endl;
    
    testList();
}
