// is graph bipartite

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt)); // (u->v, wt)
        if(isUndir) {
            l[v].push_back(make_pair(v, wt)); // (v->u, wt)
        }
    }

    void primsAlgo(int src, int V) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
        pq.push(make_pair(0, src)); //(wt, u)

        vector<bool> mstSet(V, false);
        int ans = 0;

        while(pq.size() > 0) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mstSet[u]) {
                mstSet[u] = true;
                ans += wt;

                list<pair<int, int>> neighbors = l[u];
                for(pair<int, int> n : neighbors) {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v)); 
                }
            }
        }

        cout << "Final cost of MST = " << ans << endl;
    }
};

int main(){
    // Prim's Algorithm graph
    Graph graph(4);
    int V=4;

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50); 

    graph.primsAlgo(0, V);

    return 0;
}