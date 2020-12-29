//
// Created by cmpe250student on 29.12.2020.
//

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;
#include <queue>

class Vertex {

public:
    vector<int> voutGoingEdges;//if an edge is traversed make it NULL in this list
    //bool hasNonUsedEdge();//Traverse outgoing edges and return false if there are non NULL values
    //int getFirstNonUsedEdge();//find the first non NUll value in outgoingedges list return its ID
    // class CompareVertices {// necessary if priority queue is composed of *Vertex
    //    public:
    //        bool operator() (Vertex const *v1,Vertex const *v2) {
    //            //comparison code here
    //            return (v1->vertexID >= v2->vertexID);
    //        }
    //    };
    int vertexID;
    //priority_queue<int,vector<int>,greater<int>> outGoingEdges;//if an edge is traversed delete min from list
    bool hasNonUsedEdge();//false if outgoing edges queue empty
    int getFirstNonUsedEdge();//look front of queue, pop it from queue
    void addEdge(int endVertexID);
    void printV();
    Vertex(int _vertexID);
    Vertex(const Vertex& vertex);
    Vertex& operator=(const Vertex& vertex);
    ~Vertex();
};


#endif //VERTEX_H
