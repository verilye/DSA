#include <bits/stdc++.h>
#include <iostream>

class Graph
{
    
    public:
    // number of verticies
    int V;
    std::vector<bool> visited;
    std::vector<std::list<int>> adj;

    Graph(int V)
    {
        this->V= V;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int v, int w)
    {
        // Add w to v’s list.
        adj[v].push_back(w);
    };

    void DFS(int s)
    {

        this->visited[s] = true;
        std::cout<< s << " ";

        for(int i = 0; i < V;i++){
            if(!visited[i]){
                DFS(i);
            }
        }

    };
};

int main()
{

    // Driver code
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}