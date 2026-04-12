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

    void calIndegree(vector<int>& indeg) {
        for(int u=0; u<V; u++) {
            for(int v : l[u]) {
                indeg[v]++;
            }
        }
    }

    void topoSort() { //Kahn's Algo
        vector<int> indeg(V, 0);
        calIndegree(indeg);
        queue<int> q;
        //0 indeg nodes -> starting point
        for(int i=0; i<V; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for(int v : l[curr]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
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