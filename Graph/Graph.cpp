#include <iostream>
#include <algorithm>
#include <vector>
#include "Graph.h"

using namespace std;

Graph::Graph() {
    this->vertices = vector<Vertice*>();
}

void Graph::addVertice(Vertice* v) {
    this->vertices.push_back(v);
}

void Graph::addEdge(Vertice* v1, Vertice* v2) {
    v1->addNeighbor(v2);
    v2->addNeighbor(v1);
}

void Graph::DFS(Vertice* v) {
    vector<Vertice*> visited;
    vector<Vertice*> stack;
    stack.push_back(v);
    while (!stack.empty()) {
        Vertice* current = stack.back();
        stack.pop_back();
        if (find(visited.begin(), visited.end(), current) == visited.end()) {
            visited.push_back(current);
            current->print();
            vector<Vertice*> neighbors = current->getNeighbors();
            for (int i = 0; i < neighbors.size(); i++)
                stack.push_back(neighbors[i]);
        }
    }
}

void Graph::BFS(Vertice* v) {
    vector<Vertice*> visited;
    vector<Vertice*> queue;
    queue.push_back(v);
    while (!queue.empty()) {
        Vertice* current = queue.front();
        queue.erase(queue.begin());
        if (find(visited.begin(), visited.end(), current) == visited.end()) {
            visited.push_back(current);
            current->print();
            vector<Vertice*> neighbors = current->getNeighbors();
            for (int i = 0; i < neighbors.size(); i++)
                queue.push_back(neighbors[i]);
        }
    }
}

int main(){
    Graph* g = new Graph();
    Vertice* v1 = new Vertice(1);
    Vertice* v2 = new Vertice(2);
    Vertice* v3 = new Vertice(3);
    Vertice* v4 = new Vertice(4);
    Vertice* v5 = new Vertice(5);
    Vertice* v6 = new Vertice(6);
    g->addVertice(v1);
    g->addVertice(v2);
    g->addVertice(v3);
    g->addVertice(v4);
    g->addVertice(v5);
    g->addVertice(v6);
    g->addEdge(v1, v2);
    g->addEdge(v1, v3);
    g->addEdge(v2, v4);
    g->addEdge(v3, v4);
    g->addEdge(v3, v5);
    g->addEdge(v4, v5);
    g->addEdge(v5, v6);

    g->DFS(v1);
    cout << endl;
    g->BFS(v1);
    return 0;
}