// C++ code to print BFS traversal from a given
// source vertex
#include <limits.h>
#include <bits/stdc++.h>
#include <iostream>

#define V 9

using namespace std;

int minDistance(vector<int> dist, vector<bool> seen){

    int min = INT_MAX, min_index;

    for(int v = 0; v<V; v++){
        if(seen[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }

    }

    return min_index;

}

void printSolution(vector<int> dist)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src){

    vector<bool> seen;
    seen.resize(V, false);

    vector<int> dist;
    dist.resize(V, INT_MAX);
    dist[src] = 0;

    //Find shortest path for all vericies

    for(int count = 0; count<V; count++){

        int u = minDistance(dist, seen);

        seen[u] = true;

        for(int v = 0; v<V;v++ ){

            if(!seen[v] && graph[u][v]
            && dist[u] != INT_MAX
            && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] =dist[u] + graph[u][v];
            }


        }  
    }

    printSolution(dist);

}

int main()
{

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    // Function call
    dijkstra(graph, 0);
    return 0;
}