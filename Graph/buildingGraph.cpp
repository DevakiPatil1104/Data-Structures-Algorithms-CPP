#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }
    
    void addEdge(int u, int v) {
        l[u].push_back(v);  //u->v
        l[v].push_back(u);  //v->u
    }

    void printGraph() {
        for(int u=0; u<V; u++) {
            list<int> neighbours = l[u];  //neighbours => list of connections of u
            cout << u << " : ";
            for(int v: neighbours) {  //for each neighbour v
                cout << v << ", ";
            }
            cout << endl;
        }
    }

};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.printGraph();
    return 0;
}