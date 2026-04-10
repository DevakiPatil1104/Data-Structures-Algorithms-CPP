// finding all possible paths to reach the destination

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

    void pathHelper(int src, int dest, vector<bool>& vis, vector<int> &path) {
        path.push_back(src);

        if(src == dest) {
            for(int x : path) {
                cout << x << " ";
            } 
            cout << endl; 
            path.pop_back(); //remove dest node from path
            return;
        }

        vis[src] = true;

        for(int v : l[src]) {
            if(!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }

        vis[src] = false;
        path.pop_back(); //backtrack
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(V, false);
        vector<int> path;
        pathHelper(src, dest, vis, path);
    }
};

int main(){
    int V = 6;
    Graph graph(V, false);

    // directed graph
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1); 
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    int src = 5, dest = 1;
    graph.printAllPaths(src, dest);

    return 0;
}