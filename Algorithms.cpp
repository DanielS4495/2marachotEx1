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
        vector<int> neighbors = graph.getNeighbors(v);
        for (int neighbor : neighbors)
        {
            if (neighbor != -1 && !visited[(size_t)neighbor])
            {
                parent[(size_t)neighbor] = v;
                int cycleNode = DFS(neighbor, visited, parent, graph);
                if (cycleNode != -1)
                {
                    return cycleNode;
                }
            }
            else if (neighbor != -1 && parent[(size_t)v] != neighbor)
            {
                parent[(size_t)neighbor] = v;
                return neighbor;
            }
        }
        return -1;
    }
    bool Algorithms::isConnected(Graph &graph)
    {
        size_t V = graph.getsize();
        if (V == 0)
            return true;
        std::vector<bool> visited(V, false);
        std::vector<int> parent(V, -1);
        DFS(0, visited, parent, graph);
        for (size_t i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
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
        if (u != -1)
            cyclePath = std::to_string(u) + " -> " + cyclePath;
        else
            cyclePath = "";
        return cyclePath;
    }
    std::string Algorithms::shortestPath(Graph &g, int start, int end)
    {
        string path = "";
        if (Algorithms::negativeCycle(g) == "there is a negetive cycle")
        {
            return "-1";
        }
        size_t V = g.getsize();
        vector<int> dist(V, INT_MAX); // Initialize distances with infinity
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
        if (dist[(size_t)end] == INT_MAX)
        {
            return "-1";
        }
        // Use a stack to store the path in the correct order
        std::stack<int> pathStack;
        int currentNode = end;
        while (currentNode != start)
        {
            pathStack.push(currentNode);
            currentNode = parent[(size_t)currentNode];
        }
        pathStack.push(start);
        // Construct the path string
        while (!pathStack.empty())
        {
            path += std::to_string(pathStack.top());
            pathStack.pop();
            if (!pathStack.empty())
            {
                path += " -> ";
            }
        }
        return path;
    }
    std::string Algorithms::isContainsCycle(Graph &g)
    {
        if (negativeCycle(g) == "there is a negetive cycle")
        {
            return "there is a negetive cycle";
        }
        vector<bool> visited(g.getsize(), false); 
        vector<int> parent(g.getsize(), -1);     
        for (int i = 0; i < g.getsize(); ++i)
        {
            if (!visited[(size_t)i]) 
            {
                int cyclePath = DFS(i, visited, parent, g);
                if (cyclePath != -1) 
                {
                    std::string path = constructCyclePath(cyclePath, parent);
                    if (path.empty())
                        return "0";
                    else
                        return "The cycle is " + path;
                }
            }
        }
        return "0";
    }
    bool Algorithms::BFSColor(Graph &g, int src, std::vector<int> &color,
                              std::vector<int> &groupA, std::vector<int> &groupB)
    {
        color[(size_t)src] = 0;
        groupA.push_back(src);
        std::queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            std::vector<int> neighbors = g.getNeighbors(u);
            for (int v : neighbors)
            {
                if (v != -1)
                {
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
                    else if (color[(size_t)v] == color[(size_t)u])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    std::string Algorithms::isBipartite(Graph &g)
    {
        if (negativeCycle(g) == "there is a negative cycle")
        {
            return "there is a negative cycle";
        }
        std::vector<int> color(g.getsize(), -1);
        std::vector<int> groupA;
        std::vector<int> groupB;
        for (int i = 0; i < g.getsize(); ++i)
        {
            if (color[(size_t)i] == -1)
            {
                if (!BFSColor(g, i, color, groupA, groupB))
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
        message.pop_back(); 
        message.pop_back(); 
        message += "}.";
        return message;
    }
    std::string Algorithms::negativeCycle(Graph &g)
    {
        size_t V = g.getsize();
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
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
        return "there is no negetive cycle";
    }
}
