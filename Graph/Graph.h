#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <algorithm>
#include <vector>
#include "Vertice.h"
using namespace std;

class Graph {
    public:
        vector<Vertice> vertices;
        Graph();
        void addVertice(Vertice &v);
        void addEdge(Vertice &v1, Vertice &v2);
        void DFS(Vertice v);
        void BFS(Vertice v);
};

#endif