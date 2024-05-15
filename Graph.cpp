// 211358486
// danielsamson10@gmail.com

#include "Graph.hpp"
// #include <algorithm> // for std::all_of

using namespace std;

namespace ariel
{
    vector<vector<int>> g;
    size_t Graph::getsize()
    {
        return g.size();
    }
    int Graph::getWeight(size_t u, size_t v) const
    {
        return this->g[u][v];
    }

    std::vector<int> Graph::getNeighbors(int v) const
    {
        vector<int> check(g.size(), -1);
        if (v < 0 || static_cast<size_t>(v) > g.size())
        {
            throw std::out_of_range("Vertex index out of range");
        }
        for (size_t i = 0; i < g.size(); i++)
        {
            if (g[(size_t)v][i] != 0)
                check[i] = i;
        }
        return check;
    }
    std::vector<int> Graph::getReverseNeighbors(int v) const
    {
        if (v < 0 || v >= g.size())
        {
            throw std::out_of_range("Vertex index out of range");
        }
        std::vector<int> reverseNeighbors;
        for (size_t u = 0; u < g.size(); ++u)
        {
            for (size_t i = 0; i < g[u].size(); ++i)
            {
                if (g[u][i] == v)
                { // If there's an edge from u to v, u is a reverse neighbor of v
                    reverseNeighbors.push_back(u);
                    break; // Stop searching for u in other lists
                }
            }
        }
        return reverseNeighbors;
    }
    void Graph::loadGraph(const vector<vector<int>> &graph)
    {
        size_t n = graph.size(); // Get the number of rows
        if (n == 0)
        {
            throw invalid_argument("Invalid graph: Empty graph.");
        }

        for (size_t i = 0; i < n; ++i)
        {
            if (graph[i].size() != n)
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            for (size_t j = 0; j < n; ++j)
            {
                // if (!std::is_integral<decltype(graph[i][j])>::value)
                //  throw invalid_argument("2 Invalid graph: The graph does not have an integral values.");
            }
        }

        // Copy the matrix to the class member
        g = graph;
    }

    void Graph::printGraph()
    {
        string p = "";
        int count = 0;
        for (size_t row = 0; row < this->getsize(); row++)
        {
            for (size_t col = 0; col < this->getsize(); col++)
            {
                if (this->getWeight(row, col) != 0)
                    count++;
            }
        }

        p = "Graph with " + to_string(this->getsize()) + " vertixes and " + to_string(count) + " edges";
        cout << p << " " << endl;
    }

    // bool allIntegral(const std::vector<std::vector<int>>& vec){
    //     return all_of(vec.begin(), vec.end(), [](int val) {
    //         return std::is_integral<int>::value;
    //     });
    // }

} // namespace ariel
