//  Bellman Ford's Algorithm
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Edge {
public:
    int v; //dest vertex
    int wt; //edge wt

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};




int main(){
    int V = 6;
    // Bellman Ford Graph
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

    graph[4].push_back(Edge(3, 2));

    graph[2].push_back(Edge(4, 4));

    graph[3].push_back(Edge(1, -1));

    

    return 0;
}