#include <string>
#include <vector>
#include <iostream>
#include "Vertex.h"
#include <iostream>
using namespace std;

bool Vertex::hasNonUsedEdge(){//false if outgoing edges queue empty
    return !outGoingEdges.empty();
}


int Vertex::getFirstNonUsedEdge(){//look front of queue, pop it from queue
    int endVertexID = outGoingEdges.top();
    outGoingEdges.pop();
    return endVertexID;
}
void Vertex::printV(){
    for (int i = 0; i < outGoingEdges.size(); ++i){
        cout << this->outGoingEdges.top();
        outGoingEdges.pop();
    }
}

void Vertex::addEdge(int endVertexID){//ID of the end vertex
    this->outGoingEdges.push(endVertexID);
}


/*
	Constructor
*/
Vertex::Vertex(int _vertexID) {
    this->vertexID = _vertexID;
}
/*
	Copy constructor
*/
Vertex::Vertex(const Vertex& vertex) {
    //cout << "Copy constructor is called." << endl;
    this->vertexID = vertex.vertexID;

}
/*
	Overloading assignment operator
*/
Vertex& Vertex::operator=(const Vertex& Vertex) {

    //cout << "Assinment operator called" << endl;

    return *this;
}
/*
	Destructor
*/
Vertex::~Vertex() {
    //cout << "Destructing"<< this->name << endl;

}
