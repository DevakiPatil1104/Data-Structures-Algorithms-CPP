// cycle detection in directed graph

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir=true) {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v); // u->v
        if(isUndir) {
            l[v].push_back(u); // v->u
        }
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

    bool dirCycleHelper(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for(int v : l[src]) {
            if(!vis[v]) {
                if(dirCycleHelper(v, vis, recPath)) 
                    return true;
            } else {
                if(recPath[v])
                    return true;
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for(int i=0; i<V; i++) { //for disconnected directed graph cycle detection
            if(!vis[i]) {
                if(dirCycleHelper(0, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    int V = 4;
    Graph graph(V, false);

    // directed graph
    graph.addEdge(1, 0);
    graph.addEdge(0, 2); 
    graph.addEdge(2, 3);
    graph.addEdge(3, 0); //Back Edge

    cout << graph.isCycleDir() << endl;
    
    return 0;
}