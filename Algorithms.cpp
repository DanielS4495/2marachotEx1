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

using namespace std;
namespace ariel
{

    int Algorithms::DFS(int v, vector<bool> &visited, vector<int> &parent, ariel::Graph &graph)
    {
        visited[(size_t)v] = true;
        vector<int> neighbors = graph.getNeighbors(v);
        int n = neighbors.size();
        for (int i = 0; i < n; i++)
        {
            if (neighbors[(size_t)i] != 0)
            {
                if (!visited[static_cast<size_t>(neighbors[(size_t)i])])
                {
                    parent[(size_t)i] = v;
                    return DFS(i, visited, parent, graph);
                }
                else if (visited[(size_t)i] != 0 && parent[(size_t)v] != i)
                {
                    parent[(size_t)i] = v;
                    return i;
                }
            }
        }

        return -1;
    }
    // void Algorithms::DFSReverse(int v, vector<bool> &visited, ariel::Graph &graph)
    // {
    //     visited[(size_t)v] = true;
    //     vector<int> reverseNeighbors = graph.getReverseNeighbors(v);
    //     int n = reverseNeighbors.size();
    //     for (size_t i = 0; i < reverseNeighbors.size(); ++i)
    //     {
    //         if (!visited[static_cast<size_t>(reverseNeighbors[i])])
    //         {
    //             DFSReverse(static_cast<size_t>(reverseNeighbors[i]), visited, graph);
    //         }
    //     }
    // }

    bool Algorithms::isConnected(Graph &graph)
    {
        size_t V = graph.getsize();

        // Perform DFS traversal from each vertex
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        // DFS(0, visited, graph);

        // Check if all vertices are reachable from the first vertex
        bool isconectedVertex = true;
        // int count = 0;
        for (size_t j = 0; j < V; j++)
        {


                int x = DFS(j, visited, parent, graph);

                // if (i != j)
            
            for (size_t i = 0; i < V; i++)
            {
                if (!visited[i])
                    return false;
            }

            // else{ return false;}
            visited.clear();
            parent.clear();
        }
        return isconectedVertex;
    }
    int Algorithms::detectCycleDFS(int v, std::vector<bool> &visited, std::vector<int> &parent, Graph &g)
    {
        // visited[(size_t)v] = true; // Mark the current node as visited
        // parent[(size_t)v] = true; // Add it to the recursion stack

        int vv = DFS(v, visited, parent, g);
        // Recur for all adjacent vertices

        std::vector<int> neighbors = g.getNeighbors(v);
        for (int i = 0; i < neighbors.size(); ++i)
        {
            int neighbor = neighbors[(size_t)i];
            if (!visited[(size_t)neighbor])
            {
                constructCyclePath(neighbor, parent); // If the adjacent vertex is not visited and there is a cycle
            }
            else if (parent[(size_t)neighbor])
            {
                constructCyclePath(neighbor, parent); // If the adjacent vertex is already in the recursion stack, there is a cycle
            }
        }

        parent[(size_t)v] = false; // Remove the vertex from the recursion stack before returning
        return -1;                 // If no cycle is found from this vertex, return an empty string
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
    bool Algorithms::isDirectedGraph(Graph &g)
    {
        // // Iterate through each vertex in the graph
        // for (int v = 0; v < g.getsize(); ++v)
        // {
        //     // Get the neighbors of the current vertex
        //     std::vector<int> neighbors = g.getNeighbors(v);
        //     // Iterate through the neighbors
        //     for (int neighbor : neighbors)
        //     {
        //         // Check if the current vertex is also a neighbor of its neighbor
        //         std::vector<int> reverseNeighbors = g.getReverseNeighbors(neighbor);
        //         if (std::find(reverseNeighbors.begin(), reverseNeighbors.end(), v) == reverseNeighbors.end())
        //         {
        //             // If the current vertex is not a neighbor of its neighbor, the graph is directed
        //             return true;
        //         }
        //     }
        // }
        // If no such case is found, the graph is undirected
        return false;
    }
    std::string Algorithms::shortestPath(Graph &g, int start, int end)
    {

        string path = "";
        // Check if there is a negative cycle
        if (Algorithms::negativeCycle(g) != "0")
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
            // cout << i << endl;
            for (size_t u = 0; u < (size_t)V; u++)
            {
                // cout << u << endl;
                for (size_t j = 0; j < (size_t)V; j++)
                {
                    // cout << j << endl;
                    if (u != j)
                    {
                        // cout<<"1"<<endl;
                        int weight = g.getWeight((size_t)u, (size_t)j);

                        // cout<<weight<< endl;
                        // cout<<weight<< endl;
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
                // path += std::to_string(start);
                // start = parent[(size_t)start];

                path = path + std::to_string(parent[(size_t)end]) + " -> ";
                end = parent[(size_t)end];
                // path = std::to_string(start) + " -> " + path;
            }

            path += std::to_string(start);
            // return std::string.reverse(path) ;// No negative cycle found
            // reverse(path.begin(),path.end());
            return path;
        }
        else
            return "-1";
    }
    string Algorithms::isContainsCycle(Graph &g)
    {
        if (negativeCycle(g) == "0")
        {
            return "0";
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
                visited.clear();
                parent.clear();
            }
        }
        return "0";
    }
    bool Algorithms::isBipartiteUtil(Graph &g, int src, unordered_map<int, int> &color)
    {
        // Assign initial color to source vertex
        color[src] = 0;

        // Create a queue for BFS
        queue<int> q;
        q.push(src);

        // Run BFS
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // Traverse all adjacent vertices of u
            for (int v : g.getNeighbors(u))
            {
                // If v is not colored yet
                if (color.find(v) == color.end())
                {
                    // Assign alternate color to this adjacent vertex
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                // If v is already colored and has the same color as u, the graph is not bipartite
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
        // If no conflicts found, the graph is bipartite
        return true;
    }
    std::string Algorithms::isBipartite(Graph &g)
    {
        unordered_map<int, int> color; // Map to store vertex-color pairs

        // Iterate over all vertices to check if the graph is bipartite
        for (int i = 0; i < g.getsize(); ++i)
        {
            if (color.find(i) == color.end())
            {
                // If the current vertex is not colored yet, run BFS from it
                if (!isBipartiteUtil(g, i, color))
                {
                    return "Graph is not bipartite.";
                }
            }
        }
        return "Graph is bipartite.";
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
            // cout << i << endl;
            for (size_t u = 0; u < (size_t)V; u++)
            {
                // cout << u << endl;
                for (size_t j = 0; j < (size_t)V; j++)
                {
                    // cout << j << endl;
                    if (u != j)
                    {
                        // cout<<"1"<<endl;
                        int weight = g.getWeight((size_t)u, (size_t)j);

                        // cout<<weight<< endl;
                        // cout<<weight<< endl;
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
                        return "There is a negative cycle";
                    }
                }
            }
        }
        return "0"; // No negative cycle found
    }

}
