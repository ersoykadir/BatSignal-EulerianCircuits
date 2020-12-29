#include <iostream>
#include "Vertex.h"
#include <list>
#include <unordered_map>
#include <fstream>
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
    int* vertexArr = new int[numOfVertices];// array of zeros
    int totalNumOfEdges=0;
    unordered_map<int,Vertex*> graph;
    for (int i = 0; i < numOfVertices; ++i)
    {
        int vertexID,outDegree;
        infile >> vertexID >> outDegree;
        totalNumOfEdges+=outDegree;
        vertexArr[vertexID]+=outDegree;// for easy calculation of indegree outdegree balance;
        Vertex* v = new Vertex(vertexID);
        for (int i = 0; i < outDegree; ++i)//add edges to vertices, creating graph
        {
            int endVertexID;
            infile >> endVertexID;
            vertexArr[endVertexID]--;// incoming edge
            v->addEdge(endVertexID);
        }
        graph[vertexID] = v;
    }
    int startVertexID;
    infile >> startVertexID;
//    for (int i = 0; i < numOfVertices; ++i)
//    {
//        cout <<graph[i]->outGoingEdges.size();
//    }
//    cout <<  endl;
    bool isDegreesBalanced = true;

    for (int i = 0; i < numOfVertices; ++i)
    {
        if(vertexArr[i]!=0){
            isDegreesBalanced = false;
            break;
        }
    }
    //cout << isDegreesBalanced << endl;

    //cout << graph.at(0)->outGoingEdges.top();
    if (isDegreesBalanced){
        list<int> eulerianCircuit;
        int currentV = startVertexID;
        //int startVindex=0;
        eulerianCircuit.push_back(currentV);
        auto startingViterator = eulerianCircuit.begin();
        for(auto vId : eulerianCircuit){
            if(vId==currentV){
                startingViterator++;
                break;
            }
            startingViterator++;
        }
        while(eulerianCircuit.size() <= totalNumOfEdges){
            list<int> tour;
            while(graph.at(currentV)->hasNonUsedEdge()){
                int endVertexID = graph.at(currentV)->getFirstNonUsedEdge();
                currentV = endVertexID;
                tour.push_back(currentV);
            }
            //auto it = eulerianCircuit.end();
            // for (auto x : tour)
            // {
            //     cout << x << " ";
            // }
            eulerianCircuit.splice(startingViterator,tour);// how this works ???
            auto it = eulerianCircuit.begin();
            //int newStartingVertex=currentV;
            bool found = false;
            //bool f2 = false;
            for(auto vertexID : eulerianCircuit){
                if(graph.at(vertexID)->hasNonUsedEdge()){
                    currentV = vertexID;
                    it++;
                    break;
                }
                it++;
            }
            startingViterator = it;
            //currentV = newStartingVertex;
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