// 211358486
// danielsamson10@gmail.com
#include "Algorithms.hpp"
#include <climits>
#include <queue>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;
namespace ariel
{
    int Algorithms::DFS(int v, vector<bool> &visited, vector<int> &parent, ariel::Graph &graph)
    {
        visited[(size_t)v] = true;
        vector<int> neighbors = graph.getNeighbors(v); // Get neighbors of vertex v
        for (int neighbor : neighbors) // Iterate over neighbors
        {
            if (neighbor != -1 && !visited[(size_t)neighbor]) // Check if the neighbor is valid and not visited
            {
                parent[(size_t)neighbor] = v;                          // Set the parent of the neighbor to the current vertex v
                int cycleNode = DFS(neighbor, visited, parent, graph); // Recursive call
                if (cycleNode != -1)
                {
                    return cycleNode; // Pass the cycle detection result up the call stack
                }
            }
            else if (neighbor != -1 && parent[(size_t)v] != neighbor)
            {
                // Detected a cycle, return the node where the cycle starts
                return neighbor;
            }
        }
        return -1; // No cycle found
    }

    bool Algorithms::isConnected(Graph &graph)
    {
        size_t V = graph.getsize();
        // Perform DFS traversal from each vertex
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        // Check if all vertices are reachable from the first vertex
        bool isconectedVertex = true;
        int x = DFS(0, visited, parent, graph);
        for (size_t i = 0; i < V; i++)
            if (!visited[i])
                return false;
        return isconectedVertex;
    }

    std::string Algorithms::constructCyclePath(int v, const std::vector<int> &parent)
    {

        std::string cyclePath;
        cyclePath += std::to_string(v);
        int u = parent[(size_t)v];
        while (u != v && u != -1)
        {
            cyclePath = std::to_string(u) + " -> " + cyclePath;
            u = parent[(size_t)u];
        }
        cyclePath = std::to_string(u) + " -> " + cyclePath; // Add the last vertex to close the cycle
        return cyclePath;
    }
    std::string Algorithms::shortestPath(Graph &g, int start, int end)
    {
        string path = "";
        // Check if there is a negative cycle
        if (Algorithms::negativeCycle(g) == "there is a negetive cycle")
        {
            return "-1";
        }
        size_t V = g.getsize();
        // Initialize distances with infinity
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        dist[(size_t)start] = 0;
        parent[(size_t)start] = 0; // Source vertex is at distance 0
        // Relax edges repeatedly
        for (size_t i = 0; i < ((size_t)V - 1); i++)
        {
            for (size_t u = 0; u < (size_t)V; u++)
            {
                for (size_t j = 0; j < (size_t)V; j++)
                {
                    if (u != j)
                    {
                        int weight = g.getWeight((size_t)u, (size_t)j);
                        if (weight != 0 && ((dist[(size_t)u] + weight) < dist[(size_t)j]))
                        {
                            dist[(size_t)j] = dist[(size_t)u] + weight;
                            parent[j] = u;
                        }
                    }
                }
            }
        }
        // Check for negative weight cycle
        if (dist[(size_t)end] != INT_MAX)
        {
            path = std::to_string(end) + " -> ";
            while (parent[(size_t)end] != start)
            {
                path = path + std::to_string(parent[(size_t)end]) + " -> ";
                end = parent[(size_t)end];
            }
            path += std::to_string(start);
            return path;
        }
        else
            return "-1";
    }
    std::string Algorithms::isContainsCycle(Graph &g)
    {
        if (negativeCycle(g) == "there is a negetive cycle")
        {
            return "there is a negetive cycle";
        }
        vector<bool> visited(g.getsize(), false); // Mark all vertices as not visited
        vector<int> parent(g.getsize(), -1);      // Array to store the parent of each vertex in the DFS traversal
        for (int i = 0; i < g.getsize(); ++i)
        {
            int cyclePath = DFS(i, visited, parent, g);
            if (parent[(size_t)i] != cyclePath && i == cyclePath && (cyclePath != -1))
                return "The cycle is a " + constructCyclePath(i, parent);
            else
            {
                fill(visited.begin(), visited.end(), false);
                fill(parent.begin(), parent.end(), -1);
            }
        }
        return "0";
    }
    bool Algorithms::bfs(Graph &g, int src, std::vector<int> &color,
                         std::vector<int> &groupA, std::vector<int> &groupB)
    {
        // Assign initial color to source vertex
        color[(size_t)src] = 0;
        // Add the source vertex to group A
        groupA.push_back(src);
        // Create a queue for BFS
        std::queue<int> q;
        q.push(src);
        // Run BFS
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            // Traverse all adjacent vertices of u
            std::vector<int> neighbors = g.getNeighbors(u);
            for (int v : neighbors)
            {
                if (v != -1)
                {
                    // If v is not colored yet
                    if (color[(size_t)v] == -1)
                    {
                        // Assign alternate color to this adjacent vertex
                        color[(size_t)v] = 1 - color[(size_t)u];
                        // Add the vertex to the corresponding group
                        if (color[(size_t)v] == 0)
                            groupA.push_back(v);
                        else
                            groupB.push_back(v);
                        q.push(v);
                    }
                    // If v is already colored and has the same color as u, the graph is not bipartite
                    else if (color[(size_t)v] == color[(size_t)u])
                    {
                        return false;
                    }
                }
            }
        }
        // If no conflicts found, the graph is bipartite
        return true;
    }

    std::string Algorithms::isBipartite(Graph &g)
    {
        if (negativeCycle(g) == "there is a negative cycle")
        {
            return "there is a negative cycle";
        }

        // Vector to store vertex-color pairs
        std::vector<int> color(g.getsize(), -1);
        // Vectors to store vertices in the two groups
        std::vector<int> groupA;
        std::vector<int> groupB;

        // Iterate over all vertices to check if the graph is bipartite
        for (int i = 0; i < g.getsize(); ++i)
        {
            if (color[(size_t)i] == -1)
            {
                // If the current vertex is not colored yet, run BFS from it
                if (!bfs(g, i, color, groupA, groupB))
                {
                    return "Graph is not bipartite";
                }
            }
        }

        // Construct the message with the two groups
        std::string message = "The graph is bipartite: A={";
        for (int v : groupA)
        {
            message += std::to_string(v) + ", ";
        }
        message.pop_back(); // Remove the trailing comma
        message.pop_back(); // Remove the space
        message += "}, B={";
        for (int v : groupB)
        {
            message += std::to_string(v) + ", ";
        }
        message.pop_back(); // Remove the trailing comma
        message.pop_back(); // Remove the space
        message += "}.";

        return message;
    }

    std::string Algorithms::negativeCycle(Graph &g)
    {
        size_t V = g.getsize();
        // Initialize distances with infinity
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Source vertex is at distance 0
        // Relax edges repeatedly
        for (size_t i = 0; i < ((size_t)V - 1); i++)
        {
            for (size_t u = 0; u < (size_t)V; u++)
            {
                for (size_t j = 0; j < (size_t)V; j++)
                {
                    if (u != j)
                    {

                        int weight = g.getWeight((size_t)u, (size_t)j);
                        if (weight != 0 && ((dist[(size_t)u] + weight) < dist[(size_t)j]))
                        {
                            dist[(size_t)j] = dist[(size_t)u] + weight;
                        }
                    }
                }
            }
        }
        // Check for negative weight cycle
        for (int u = 0; u < (int)V; u++)
        {
            for (int j = 0; j < (int)V; j++)
            {
                if (u != j)
                {
                    int weight = g.getWeight((size_t)u, (size_t)j);
                    if (weight != 0 && dist[(size_t)u] + weight < dist[(size_t)j])
                    {
                        return "there is a negetive cycle";
                    }
                }
            }
        }
        return "there is no negetive cycle"; // No negative cycle found
    }
}
