// 211358486
// danielsamson10@gmail.com

#include "Graph.hpp"
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
    void Graph::loadGraph(const vector<vector<int>> &graph)
    {
        size_t n = graph.size();
        if (n == 0)
        {
            throw invalid_argument("Invalid graph: Empty graph.");
        }

        for (size_t i = 0; i < n; ++i)
        {
            if (graph[i].size() != n)
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
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
}
