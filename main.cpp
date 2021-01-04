#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char const *argv[]) {

    const char* infile_name = argv[1];//READ INPUT FILE NAME
    const char* outfile_name = argv[2];//READ OUTPUT FILE NAME

    //OPEN INPUT AND OUTPUT FILE STREAMS
    FILE * infile;
    FILE * outfile;
    infile = fopen(infile_name,"r");
    outfile = fopen(outfile_name,"w");


    int numOfVertices=0;
    fscanf(infile,"%i", &numOfVertices);
    int totalNumOfEdges=0;
    int balance = 0;
    queue<int> * queArr = new queue<int>[numOfVertices];
    for (int i = 0; i < numOfVertices; ++i)
    {
        int vertexID,outDegree;
        fscanf(infile,"%i",&vertexID);
        fscanf(infile,"%i",&outDegree);
        totalNumOfEdges+=outDegree;
        balance+=vertexID*outDegree;
        for (int j = 0; j < outDegree; ++j)//add edges to vertices, creating graph
        {
            int endVertexID;
            fscanf(infile,"%i",&endVertexID);
            balance-=endVertexID;
            queArr[i].push(endVertexID);
        }
    }
    //cout << balance;
    int startVertexID;
    fscanf(infile,"%i",&startVertexID);

    if (balance !=0){
        fprintf(outfile, "no path");
    }
    else{
        list<int> eulerianCircuit;
        eulerianCircuit.push_back(startVertexID);
        auto startingViterator = eulerianCircuit.begin();
        startingViterator++;
        auto mockIterator = eulerianCircuit.begin();
        while(eulerianCircuit.size() <= totalNumOfEdges){
            list<int> tour;
            while(!queArr[startVertexID].empty()){
                int endVertexID = queArr[startVertexID].front();
                queArr[startVertexID].pop();
                startVertexID = endVertexID;
                tour.push_back(startVertexID);
            }
            eulerianCircuit.splice(startingViterator,tour);// how this works ???
            while(mockIterator!=eulerianCircuit.end()){
                if(!queArr[*mockIterator].empty()){
                    startVertexID = *mockIterator;
                    mockIterator++;
                    break;
                }
                mockIterator++;
            }
            startingViterator = mockIterator;
            mockIterator--;
        }
        //print euleriancircuit
        for(auto ID : eulerianCircuit){
            fprintf(outfile,"%i ",ID);
        }
    }
    

    return 0;
}
