#include <iostream>
#include <algorithm>
#include <vector>
#include "Graph.h"

using namespace std;

Graph::Graph() {
    this->vertices = vector<Vertice>();
}

void Graph::addVertice(Vertice &v) {
    this->vertices.push_back(v);
}

void Graph::addEdge(Vertice &v1, Vertice &v2) {
    v1.addNeighbor(v2);
    v2.addNeighbor(v1);
}

void Graph::DFS(Vertice &v) {
    // TODO
    vector<bool> visited;
    for (int i = 0; i < this->vertices.size(); i++) {
        visited.push_back(false);
    }
    vector<Vertice> stack;
    stack.push_back(v);
    while (!stack.empty()) {
        Vertice current = stack.back();
        stack.pop_back();
        if (!visited[current.getId()]) {
            current.print();
            visited[current.getId()] = true;
            for (auto i : current.getNeighbors())
                stack.push_back(i);
        }
    }
}

void Graph::BFS(Vertice &v) {
    // TODO
    vector<bool> visited;
    for (int i = 0; i < this->vertices.size(); i++) {
        visited.push_back(false);
    }
    vector<Vertice> queue;
    queue.push_back(v);
    while (!queue.empty()) {
        Vertice current = queue.front();
        queue.erase(queue.begin());
        if (!visited[current.getId()]) {
            current.print();
            visited[current.getId()] = true;
            for (auto i : current.getNeighbors())
                queue.push_back(i);
        }
    }
}

int main(){
    Graph g = Graph();
    Vertice v1 = Vertice(1);
    Vertice v2 = Vertice(2);
    Vertice v3 = Vertice(3);
    Vertice v4 = Vertice(4);
    Vertice v5 = Vertice(5);
    g.addVertice(v1);
    g.addVertice(v2);
    g.addVertice(v3);
    g.addVertice(v4);
    g.addVertice(v5);
    g.addEdge(v1, v2);
    g.addEdge(v1, v3);
    g.addEdge(v2, v4);
    g.addEdge(v2, v5);
    
    cout << "DFS: " << endl;
    g.DFS(v1);
    cout << "BFS: " << endl;
    g.BFS(v1);
    return 0;
}