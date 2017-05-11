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
    
    cout << "removing second spot" << endl;
    cout << "the removed data should be 2 and is " << sample.remove(1) << endl;
    cout << "size should be 2 and is " << sample.getSize() << endl;
    cout << "list should read 1 3" << endl;
    for (int index = 0; index < sample.getSize(); index ++ )
    {
        cout << sample.getFromIndex(index) << endl;
    }
    sample.addAtIndex(1,2);
    cout << "list should now be 1 2 3" << endl;
    for (int index = 0; index < sample.getSize(); index ++ )
    {
        cout << sample.getFromIndex(index) << endl;
    }
    sample.setAtIndex(1,4);
    cout <<  "set second spot to 4, list should now be 1 4 3" << endl;
    for (int index = 0; index < sample.getSize(); index ++ )
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    if (sample.contains(3))
    {
        cout << "the list contains the number 3" << endl;
    }
    else
    {
        cout << "the list does not contain the number 3" << endl;
    }
    cout << "the front should be 1 and is: " << sample.getFront()->getNodeData() << endl;
    cout << "the end should be 3 and is: " << sample.getEnd()->getNodeData() << endl;
    
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

void StructureController :: testDoubleList()
{
    DoubleList<int> tempList;
    
    tempList.add(3);
    tempList.add(4);
    tempList.add(5);
    
    cout << "added 3 items to the list, size should be 3 and is " << tempList.getSize() << endl;
    cout << "list should read: 3 4 5 " << endl;
    for (int index = 0; index < tempList.getSize(); index ++ )
    {
        cout << tempList.getFromIndex(index) << endl;
    }
    cout << "removing the second item from the list: number should be 4 and is " << tempList.remove(1) << endl;
    
    
    
    
}
void StructureController :: testDoubleListTiming()
{
    DoubleList<int> timingList;
    
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    cout << "added 10000 items to the list, size should be 10000 and is: " << timingList.getSize() << endl;
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000;
    averageFast = averageFast/1000;
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds." << endl;
    cout << "The average speed for the getFromIndexFast method was: " << averageFast << " microseconds." << endl;
    cout << "A time savings?? of: " << averageSlow - averageFast << " microseconds." << endl;
}

void StructureController :: testNumberStack()
{
    Stack<int> numberStack;
    
    numberStack.push(3);
    numberStack.add(6);
    numberStack.add(9);
    numberStack.add(10);
    numberStack.add(4);
    
    cout << "added 5 items to  stack, size should be 5 and is: " << numberStack.getSize() << endl;
    cout << "The top number on the stack should be 4 and is: " << numberStack.peek() << endl;
    numberStack.pop();
    cout << "took out first item size should now be 4 and is: " << numberStack.getSize() << endl;
    cout << "removing the next number in the stack, size should be 3 and number should be 10. " << "number is " << numberStack.remove(3) << " size is " << numberStack.getSize() << endl;
    cout << "adding the number 1 to the stack "<<  endl;
    numberStack.push(1);
    cout << "size should now be 4 and is " << numberStack.getSize() << " top number should be 1 and is " << numberStack.peek() << endl;
}

void StructureController :: testBinarySearchTree()
{
    BinarySearchTree<int> numbers;
    
    cout << "Tree has nothing in it, size should be 0 and is " << numbers.getSize() << endl;
    
    cout << "Adding values to the list" << endl;
    numbers.insert(9843);
    numbers.insert(10);
    numbers.insert(43);
    numbers.insert(-123);
    numbers.insert(23465);
    numbers.insert(10); // won't go in
    numbers.insert(43243);
    numbers.insert(-45677654);
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    cout << "The post order traversal is: " << endl;
    
    numbers.postOrderTraversal();
    
    cout << "The pre order traversal is: " << endl;
    
    numbers.preOrderTraversal();

    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
    cout << "Trying to remove the number 10 " << endl;
    numbers.remove(10);
    cout << "Size should be 7 and is " << numbers.getSize() << endl;
    
}

void StructureController :: testBinarySearchCrime()
{
    FileController fileData;
    
    Timer treeTimer;
    
    treeTimer.startTimer();
    
    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/mpow2231/Downloads/crimes.csv");
    
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    
    int height = crimeTree.getHeight();
    
    bool complete = crimeTree.isComplete();
    
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
}

//void StructureController :: testAVLTreeOperations()
//{
//    AVLTree<int> numbers;
//    
//    numbers.insert(9843);
//    numbers.insert(10);
//    numbers.insert(43);
//    numbers.insert(-123);
//    numbers.insert(23465);
//    numbers.insert(10); // won't go in
//    numbers.insert(43243);
//    numbers.insert(-45677654);
//    numbers.insert(92165);
//    
//    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
//    
//    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
//    
//    numbers.inOrderTraversal();
//    
//    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
//    
//    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
//}
//
//void StructureController :: testAVLCrimeData()
//{
//    FileController fileData;
//    
//    Timer treeTimer;
//    
//    treeTimer.startTimer();
//    
//    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/mpow2231/Downloads/crimes.csv");
//    
//    treeTimer.stopTimer();
//    
//    
//    int count = crimeTree.getSize();
//    int height = crimeTree.getHeight();
//    bool complete = crimeTree.isComplete();
//    bool balanced = crimeTree.isBalanced();
//    
//    
//    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
//    
//    cout << "The time to read in the tree was: " << endl;
//    
//    treeTimer.displayTimerInformation();
//}

void StructureController :: testGraph()
{
    Graph<string> myGraph;
    
    myGraph.addVertex("lacrosse");
    myGraph.addVertex("Brighton");
    myGraph.addVertex("computer science");
    myGraph.addVertex("Drone videos");
    myGraph.addVertex("Mavic Pro");
    myGraph.addEdge(0,1);
    myGraph.addEdge(0,2);
    myGraph.addEdge(0,4);
    myGraph.addEdgeUndirected(0,3);
    myGraph.addEdgeUndirected(2,3);
    myGraph.addEdgeUndirected(2,4);
    
    cout << "Breadth First Traversal: " << endl;
    myGraph.breadthFirstTraversal(myGraph, 0);
    cout << "Depth First Traversal: " << endl;
    myGraph.depthFirstTraversal(myGraph, 0);
    
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
    //testMemeQueue();
    //testList();
    //testDoubleList();
   // testDoubleListTiming();
    //testNumberStack();
    
    //testBinarySearchTree();
    testGraph();

}
