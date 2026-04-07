#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v); // u->v
        l[v].push_back(u); // v->u
    }

    void printGraph()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbours = l[u]; // neighbours => list of connections of u
            cout << u << " : ";
            for (int v : neighbours)
            { // for each neighbour v
                cout << v << ", ";
            }
            cout << endl;
        }
    }

    void bfs()
    { // O(V + E)
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neightbours = l[u];
            for (int v : neightbours)
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &vis)
    { // O(V + E)
        vis[u] = true;
        cout << u << " ";

        list<int> neightbours = l[u];
        for (int v : neightbours)
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs()
    {
        vector<bool> vis(7, false);
        dfsHelper(0, vis);
        cout << endl;
    }
};

int main()
{
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.printGraph();

    graph.bfs();

    graph.dfs();
    return 0;
}