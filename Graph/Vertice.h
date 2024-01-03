#ifndef VERTICE_H
#define VERTICE_H

#include <vector>
using namespace std;

class Vertice {
private:
    int id;
    vector<Vertice> neighbors;

public:
    Vertice(int id);
    void addNeighbor(Vertice neighbor);
    vector<Vertice> getNeighbors();
    void print();
};

#endif // VERTICE_H
