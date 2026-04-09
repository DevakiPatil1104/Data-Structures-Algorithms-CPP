// cycle detection in undirected graph

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v); // u->v
        l[v].push_back(u); // v->u
    }

    void printGraph() {
        for (int u = 0; u < V; u++) {
            list<int> neighbours = l[u]; // neighbours => list of connections of u
            cout << u << " : ";
            for (int v : neighbours) { // for each neighbour v 
                cout << v << ", ";
            }
            cout << endl;
        }
    }

    bool undirCycleHelper(int src, int parent, vector<bool>& vis) {
        vis[src] = true;

        for(int v : l[src]) {
            if(!vis[v]) {
                if(undirCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if(v != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }

};

int main(){
    int V = 5;
    Graph graph(V);

    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2); //Back Edge
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    cout << graph.isCycleUndir() << endl;
    
    return 0;
}