#include <iostream>
#include <algorithm>
#include "Graph.h"

using namespace std;

Graph::Graph() {
    this->vertices = vector<Vertice>();
}

void Graph::addVertice(Vertice v) {
    this->vertices.push_back(v);
}

void Graph::addEdge(Vertice v1, Vertice v2) {
    v1.addNeighbor(v2);
    v2.addNeighbor(v1);
}

void Graph::DFS(Vertice v) {
    // TODO
    vector<Vertice> visited;
    vector<Vertice> stack;
    stack.push_back(v);
    while (!stack.empty()) {
        Vertice current = stack.back();
        stack.pop_back();
        if (find(visited.begin(), visited.end(), current) == visited.end()) {
            current.print();
            visited.push_back(current);
            vector<Vertice> neighbors = current.getNeighbors();
            for (int i = 0; i < neighbors.size(); i++) {
                stack.push_back(neighbors[i]);
            }
        }
    }
}

void Graph::BFS(Vertice v) {
    // TODO
    vector<Vertice> visited;
    vector<Vertice> queue;
    queue.push_back(v);
    while (!queue.empty()) {
        Vertice current = queue.front();
        queue.erase(queue.begin());
        if (find(visited.begin(), visited.end(), current) == visited.end()) {
            current.print();
            visited.push_back(current);
            vector<Vertice> neighbors = current.getNeighbors();
            for (int i = 0; i < neighbors.size(); i++) {
                queue.push_back(neighbors[i]);
            }
        }
    }
}

int main(){
    Graph g = Graph();
    g.addVertice(Vertice(1));
    g.addVertice(Vertice(2));
    g.addVertice(Vertice(3));
    g.addVertice(Vertice(4));
    g.addVertice(Vertice(5));
    g.addEdge(g.vertices[0], g.vertices[1]);
    g.addEdge(g.vertices[0], g.vertices[2]);
    g.addEdge(g.vertices[1], g.vertices[3]);
    g.addEdge(g.vertices[2], g.vertices[3]);
    g.addEdge(g.vertices[2], g.vertices[4]);
    g.addEdge(g.vertices[3], g.vertices[4]);
    g.DFS(g.vertices[0]);
    cout << endl;
    g.BFS(g.vertices[0]);
    return 0;
}