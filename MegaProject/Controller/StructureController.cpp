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

void StructureController :: testListIntro()
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
    
    cout << "removing second spot" << endl;
    cout << "the removed data should be 2 and is " << sample.remove(1) << endl;
    cout << "size should be 2 and is " << sample.getSize() << endl;
    cout << "list should read 1 3" << endl;
    for (int index = 0; index < sample.getSize(); index ++ )
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    
    
}

void StructureController :: testMemeQueue()
{
    Meme firstMeme("salt guy");
    Queue<Meme> memeQueue;
    memeQueue.add(firstMeme);
    cout << "Added first meme, size should be 1 and is: " << memeQueue.getSize() << endl;
    Meme secondMeme;
    secondMeme.setDankness(8435);
    memeQueue.enqueue(secondMeme);
    Meme thirdMeme("white guy blinking");
    thirdMeme.setDankness(10000);
    memeQueue.enqueue(thirdMeme);
    cout << "added second and third meme, size should be 3 and is: " << memeQueue.getSize() << endl;
    
    
    Meme temp = memeQueue.dequeue();
    cout << "Removed first meme, size should now be 2 and is: " << memeQueue.getSize() << " Meme title should be salt guy and is: " << temp.getTitle() << endl;
    
    
    Meme secondTemp = memeQueue.remove(0);
    cout << "this next meme is removed and its dankness should be 8435 and is: " << secondTemp.getDankness() << endl;
    
    Meme thirdTemp = memeQueue.peek();
    cout << "The last memes title should be white guy blinking with a dankness of 10000. Title: " << thirdTemp.getTitle() << " dankness: " << thirdTemp.getDankness() << endl;
    cout << "list size should now be 1 and is: " << memeQueue.getSize() << endl;
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
    testMemeQueue();

}
