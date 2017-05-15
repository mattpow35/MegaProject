//
//  Graph.hpp
//  MegaProject
//
//  Created by Matt Powley on 5/10/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set> 
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> graph, int vertex, bool markedVertices[]);
public:
    Graph();
    ~Graph();
    //Graph operations
    void addVertex(const Type& value);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    void addEdgeUndirected(int source, int target);
    void removeEdgeUndirected(int source, int target);
    //Accessors
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    //Check connections
    bool hasUndirectedConnection(int source, int target) const;
    bool areConnected(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    //Traversals
    void depthFirstTraversal(Graph<Type> graph, int vertex);
    void breadthFirstTraversal(Graph<Type> graph, int vertex);
};

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0;
}

template <class Type>
Graph<Type> :: ~Graph()
{
//    delete [] this->adjacencyMatrix;
//    delete [] this->graphData;
}

template <class Type>
int Graph<Type> :: size() const
{
    return vertexCount;
}

//Left hand side operator
template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert(vertex < size());
    return graphData[vertex];
}


//Right hand side operator (getter)
template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < size());
    return graphData[vertex];
}

//Adds a vertex, which is a data point on the graph
template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(size() < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
    
    graphData[newVertexNumber] = value;
}

//Removes edge, edges of connections
template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
    assert(source < size() && target < size());
    adjacencyMatrix[source][target] = false;
}

//Adds a connection between two vertices, from one to the next
//One way
template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source < size() && target < size());
    adjacencyMatrix[source][target] = true;
}

//Removes a connection going in both directions
template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source < size() && target < size());
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][source] = false;
}
//Adds a connection in both directions to the node and back to the first node.
template <class Type>
void Graph<Type> :: addEdgeUndirected(int source, int target)
{
    assert(source < size() && target < size());
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}
//Checks to see if the edge goes both ways
template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
    assert(source < size() && target < size());
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}
//Check to see if two vertices are connected by an edge
template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source < size() && target < size());
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target];
    
    return isAnEdge;
}

//Checks to see who a vertex is connected to and returns all the values that are connected to it in a set
template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < size());
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < size(); index ++)
    {
        if(adjacencyMatrix[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    
    return vertexNeighbors;
}
//Recursive traverasal that goes as far down the graph as possible first.
template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> currentGraph, int vertex)
{
    bool visitedVertices[MAXIMUM];
    assert(vertex < currentGraph.size());
    std::fill_n(visitedVertices, currentGraph.size(), false);
    depthFirstTraversal(currentGraph, vertex, visitedVertices);
}
//Depth first traversal recursive helper method
template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> currentGraph, int vertex, bool * visited)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
    
    visited[vertex] = true;
    cout << currentGraph[vertex] << ", " << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!visited[*setIterator])
        {
            depthFirstTraversal(currentGraph, *setIterator, visited);
        }
    }
    
}
//iterative traversal that goes as wide as possible on the graph first.
template <class Type>
void Graph<Type> :: breadthFirstTraversal(Graph<Type> currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited,currentGraph.size(),false);
    visited[vertex] = true;
    cout << currentGraph[vertex] << endl;
    vertexQueue.push(vertex);
    
    while(!vertexQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                visited[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator);
            }
        }
    }
}







#endif /* Graph_h */
