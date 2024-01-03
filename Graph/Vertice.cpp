#include <iostream>
#include "Vertice.h"

using namespace std;

Vertice::Vertice(int id) {
    this->id = id;
    this->neighbors = vector<Vertice>();
}

void Vertice::addNeighbor(Vertice neighbor) {
    this->neighbors.push_back(neighbor);
}

void Vertice::print(){
    cout << this->id << endl;
}

int Vertice::getId() {
    return this->id;
}

vector<Vertice> Vertice::getNeighbors() {
    return this->neighbors;
}
