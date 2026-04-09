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

    void bfsHelper(int st, vector<bool>& visited) { // O(V + E)
        queue<int> q;
        q.push(st);
        visited[st] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neightbours = l[u];
            for (int v : neightbours)
            {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void bfs() {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bfsHelper(i, visited);
                cout << endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis) { // O(V + E)
        vis[u] = true;
        cout << u << " ";

        for (int v : l[u]) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) { //for disconnected graphs
            if(!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }
};

int main(){
    Graph graph(10);

    graph.addEdge(0, 2);
    graph.addEdge(2, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 9);
    graph.addEdge(4, 3);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);

    // graph.printGraph();

    // graph.bfs();

    graph.dfs();
    return 0;
}