// Adjascency List representation in C++

#include <bits/stdc++.h>
#include<list>
using namespace std;

// Add edge
void addEdge(list<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Print the graph
void printGraph(list<int> adj[], int V)
{
    for (int d = 0; d < V; ++d)
    {
        cout << "\n Vertex "
             << d << ":";
        for (auto x : adj[d])
            cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int V = 5;

    // Create a graph
    list<int> adj[V];

    // Add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    printGraph(adj, V);
}