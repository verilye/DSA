// C++ code to print BFS traversal from a given
// source vertex

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{

    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    vector<list<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        // Add w to v’s list.
        adj[v].push_back(w);
    }

    // Prints BFS traversal from a given source s
    void BFS(int s){

        // Mark all verticies not visited
        vector<bool> visited;
        visited.resize(V,false);
        

        list<int> queue;

        visited[s] = true;

        queue.push_back(s);

        while(!queue.empty()){

            s = queue.front();
            cout<< s<< " ";
            queue.pop_front();

            for(auto adjacent : adj[s]){
                if(!visited[adjacent]){
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }

    };
};

// Driver code
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}