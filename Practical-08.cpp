#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

// -------------------------
// Graph Class
// -------------------------

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:

    // Constructor
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    // Add Edge
    void addEdge(int source, int destination)
    {
        adj[source].push_back(destination);
        adj[destination].push_back(source);      // Remove this line for Directed Graph
    }
// -------------------------
// Depth First Search (DFS)
// -------------------------

void DFSUtil(int vertex, vector<bool> &visited)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbour : adj[vertex])
    {
        if (!visited[neighbour])
        {
            DFSUtil(neighbour, visited);
        }
    }
}

// Start DFS
void DFS(int start)
{
    vector<bool> visited(V, false);
    DFSUtil(start, visited);
}

// -------------------------
// Breadth First Search (BFS)
// -------------------------

void BFS(int start)
{
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbour : adj[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
// -------------------------
// Main Function
// -------------------------

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cin >> source >> destination;

        graph.addEdge(source, destination);
    }

    int startVertex;

    cout << "Enter starting vertex: ";
    cin >> startVertex;

    // -------------------------
    // DFS Time Analysis
    // -------------------------

    auto startDFS = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    graph.DFS(startVertex);

    auto endDFS = high_resolution_clock::now();

    auto dfsTime = duration_cast<nanoseconds>(endDFS - startDFS);

    // -------------------------
    // BFS Time Analysis
    // -------------------------

    auto startBFS = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    graph.BFS(startVertex);

    auto endBFS = high_resolution_clock::now();

    auto bfsTime = duration_cast<nanoseconds>(endBFS - startBFS);

    // -------------------------
    // Display Execution Time
    // -------------------------

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime.count() << " ns";
    cout << "\nBFS: " << bfsTime.count() << " ns";

    return 0;
}
