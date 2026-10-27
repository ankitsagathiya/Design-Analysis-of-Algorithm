#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// -------------------------
// Travelling Salesman Problem
// -------------------------

int minimumCost = INT_MAX;
vector<int> bestPath;

void tsp(vector<vector<int>> &graph, vector<bool> &visited,
         int currentVertex, int count, int cost,
         int startVertex, vector<int> &path, int vertices)
{
    // If all vertices are visited, return to the starting vertex
    if (count == vertices)
    {
        if (graph[currentVertex][startVertex] != 0)
        {
            int totalCost = cost + graph[currentVertex][startVertex];

            if (totalCost < minimumCost)
            {
                minimumCost = totalCost;
                bestPath = path;
                bestPath.push_back(startVertex);
            }
        }

        return;
    }

    // Try visiting every unvisited vertex
    for (int nextVertex = 0; nextVertex < vertices; nextVertex++)
    {
        if (!visited[nextVertex] &&
            graph[currentVertex][nextVertex] != 0)
        {
            visited[nextVertex] = true;
            path.push_back(nextVertex);

            tsp(graph, visited, nextVertex, count + 1,
                cost + graph[currentVertex][nextVertex],
                startVertex, path, vertices);

            // Backtrack
            visited[nextVertex] = false;
            path.pop_back();
        }
    }
}

// -------------------------
// Main Function
// -------------------------

int main()
{
    int vertices;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));

    cout << "\nEnter the cost adjacency matrix:\n";
    cout << "Enter 0 if there is no edge between two vertices.\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(vertices, false);
    vector<int> path;

    int startVertex = 0;

    visited[startVertex] = true;
    path.push_back(startVertex);

    tsp(graph, visited, startVertex, 1, 0,
        startVertex, path, vertices);

    if (minimumCost == INT_MAX)
    {
        cout << "\nNo complete tour exists.\n";
    }
    else
    {
        cout << "\nMinimum Tour Cost = " << minimumCost << endl;

        cout << "Best Tour: ";
        for (int vertex : bestPath)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
