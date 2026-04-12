// topological sort using dfs approach 

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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
    }

    void printGraph() {
        for (int u = 0; u < V; u++) {
            cout << u << " : ";
            for (int v : l[u]) { 
                cout << v << ", ";
            }
            cout << endl;
        }
    }

    void dfs(int node, vector<bool>& vis, stack<int>& s) {
        vis[node] = true;

        for(int v : l[node]) {
            if(!vis[v]) {
                dfs(v, vis, s);
            }
        }

        s.push(node);
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, vis, s);
            }
        }

        vector<int> topoOrder;
        while(!s.empty()) {
            topoOrder.push_back(s.top());
            s.pop();
        }

        for(int x : topoOrder) {
            cout << x << " ";
        } 
        cout << endl;
    }
};

int main(){
    int V = 6;
    Graph graph(V);

    // directed acyclic graph (DAG)
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1); 
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort();

    return 0;
}