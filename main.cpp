#include <iostream>
#include "Vertex.h"
#include <list>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// int findVertexID(list<int> *eulerianCircuit,unordered_map<int,*Vertex> *graph);

int main(int argc, char const *argv[]) {

    string infile_name = argv[1];//READ INPUT FILE NAME
    string outfile_name = argv[2];//READ OUTPUT FILE NAME

    //OPEN INPUT AND OUTPUT FILE STREAMS
    ifstream infile;
    infile.open(infile_name);
    ofstream outfile;
    outfile.open(outfile_name);

    int numOfVertices=0;
    infile >> numOfVertices;
    //cout << numOfVertices<<endl;
    //int* vertexArr = new int[numOfVertices];// array of zeros
    int totalNumOfEdges=0;
    int balance = 0;
    queue<int> * queArr = new queue<int>[numOfVertices];
    //vector<queue<int>> graphV(numOfVertices);

    //vector<Vertex*> graph;
    for (int i = 0; i < numOfVertices; ++i)
    {
        int vertexID,outDegree;
        infile >> vertexID >> outDegree;
        totalNumOfEdges+=outDegree;
        //vertexArr[vertexID]+=outDegree;// for easy calculation of indegree outdegree balance;
        //Vertex* v = new Vertex(vertexID);
        balance+=vertexID*outDegree;
        for (int j = 0; j < outDegree; ++j)//add edges to vertices, creating graph
        {
            int endVertexID;
            infile >> endVertexID;
            //vertexArr[endVertexID]--;// incoming edge
            //v->addEdge(endVertexID);
            balance-=endVertexID;
            queArr[i].push(endVertexID);
        }
        //graph.push_back(v);
    }
    cout << balance;
    int startVertexID;
    infile >> startVertexID;
//    for (int i = 0; i < numOfVertices; ++i)
//    {
//        cout <<graph[i]->outGoingEdges.size();
//    }
//    cout <<  endl;
    // for(auto v : graphV){
    //     for(auto e : v){
    //         cout << e <<  " ";
    //     }
    //     cout << endl;
    // }
    //cout << "heree" << endl;
    //bool isDegreesBalanced = true;

    // for (int i = 0; i < numOfVertices; ++i)
    // {
    //     if(vertexArr[i]!=0){
    //         isDegreesBalanced = false;
    //         break;
    //     }
    // }
    //cout << isDegreesBalanced << endl;

    //cout << graph.at(0)->outGoingEdges.top();
    if (balance ==0){
        // for (int i = 0; i < numOfVertices; ++i)
        // {
        //     sort(graph[i]->voutGoingEdges.begin(),graph[i]->voutGoingEdges.end());
        // }
        // for (int i = 0; i < numOfVertices; ++i)
        // {
        //     vector<int> v = graph.at(i)->voutGoingEdges;
        //     for(auto x : v){
        //         outfile << x << " ";
        //     }
        //     outfile << endl;
        // }
        list<int> eulerianCircuit;
        //int currentV = startVertexID;
        //int startVindex=0;
        eulerianCircuit.push_back(startVertexID);
        auto startingViterator = eulerianCircuit.begin();
        startingViterator++;
        // for(auto vId : eulerianCircuit){
        //     if(vId==currentV){
        //         startingViterator++;
        //         break;
        //     }
        //     startingViterator++;
        // }
        auto mockIterator = eulerianCircuit.begin();
        //mockIterator++;
        while(eulerianCircuit.size() <= totalNumOfEdges){
            list<int> tour;
            while(!queArr[startVertexID].empty()){
                int endVertexID = queArr[startVertexID].front();
                queArr[startVertexID].pop();
                startVertexID = endVertexID;
                tour.push_back(startVertexID);
            }

            //auto it = eulerianCircuit.end();
            // for (auto x : tour)
            // {
            //     cout << x << " ";
            // }
            eulerianCircuit.splice(startingViterator,tour);// how this works ???
            //auto it = eulerianCircuit.begin();
            //int newStartingVertex=currentV;
            //bool found = false;
            //bool f2 = false;
            while(mockIterator!=eulerianCircuit.end()){
                if(!queArr[*mockIterator].empty()){
                    startVertexID = *mockIterator;
                    mockIterator++;
                    break;
                }
                mockIterator++;
            }
            // for(auto vID : eulerianCircuit){
            //     if(graph[vID]->hasNonUsedEdge()){
            //         startVertexID = vID;
            //         it++;
            //         break;
            //     }
            //     it++;
            // }
            //currentV = newStartingVertex;
            startingViterator = mockIterator;
            mockIterator--;
            //cout << "heree" << endl;
            //startVertexID = findVertexID(&eulerianCircuit,&graph);
            //int index = 0;
            // for(auto vertexID : eulerianCircuit){
            //     if(graph.at(vertexID)->hasNonUsedEdge()){
            //         currentV = vertexID;
            //         break;
            //     }
            //         startVindex++;
            //     //index++;
            // }
        }
        //print euleriancircuit
        for(auto ID : eulerianCircuit){
            outfile << ID << " ";
        }
    }
    else{
        //print empty circuit
        outfile << "no path" << endl;
    }

    return 0;
}
// int findVertexID(list<int> *eulerianCircuit,unordered_map<int,*Vertex> *graph){//find first vertex in the circuit with unused edge
//  for(const auto& vertexID : *eulerianCircuit)
//  {
//          if(graph[startVertexID]->hasNonUsedEdge()){
//              return vertexID;
//          }

//  }

// }