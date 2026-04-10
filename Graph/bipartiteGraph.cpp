// is graph bipartite

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

    bool isBipartite() {
        queue<int> q;
        vector<int> color(V, -1);

        for(int i=0; i<V; i++) {
            if(color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for(int v : l[curr]) {
                        if(color[v] == -1) {
                            color[v] = !color[curr];
                            q.push(v);
                        } else {
                            if(color[curr] == color[v]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

int main(){
    int V = 5;
    Graph graph(V, false);

    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3); 

    cout << graph.isBipartite() << endl;
    return 0;
}