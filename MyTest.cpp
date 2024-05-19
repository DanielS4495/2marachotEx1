// 211358486
// danielsamson10@gmail.com
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using ariel::Algorithms;

int main(int argc, char **argv)
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},

    };
    g.loadGraph(graph1);

    if (Algorithms::isConnected(g) == true)
        cout << "1 - isConnected(g) == true" << endl;

    vector<vector<int>> graph2 = {
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 3, 0},
        {0, 5, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {7, 0, 5, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
    };
    g.loadGraph(graph2);
    if (Algorithms::isConnected(g) == true)
        cout << "2 - isConnected(g) == true" << endl;

    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3},
        {0, 5, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {7, 0, 5, 0, 0},
    };
    g.loadGraph(graph3);
    if (Algorithms::isConnected(g) == false)
        cout << "3 - isConnected(g) == false" << endl;
       
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }

    vector<vector<int>> graph5 = {
        {0, 5, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 1},
        {0, 0, 0, 0, -6, 0},
        {0, -4, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 3, 0, 0, 0},
    };
    g.loadGraph(graph5);
    if (Algorithms::negativeCycle(g) == "there is a negetive cycle")
        cout << "5 - negetiveCycle(g) == there is a negetive cycle" << endl;

    vector<vector<int>> graph6 = {
        {0, 5, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 1},
        {0, 0, 0, 0, -6, 0},
        {0, -4, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 3, 0, 0, 0},
    };
    g.loadGraph(graph6);
    if (Algorithms::negativeCycle(g) == "there is a negetive cycle")
        cout << "6 - negetiveCycle(g) == there is a negetive cycle" << endl;

    vector<vector<int>> graph7 = {
        {0, 3, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {-2, 0, 0, 11, 0},
        {11, 0, 0, 0, -2},
        {0, 0, -2, 0, 0},
    };

    g.loadGraph(graph7);
    if (Algorithms::negativeCycle(g) == "there is no negetive cycle")
        cout << "7 - negetiveCycle(g) == there is no negetive cycle" << endl;

    vector<vector<int>> graph8 = {
        {0, 5, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 1},
        {0, 0, 0, 0, -6, 0},
        {0, -4, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, -11, 0, 0, 0},
    };
    g.loadGraph(graph8);
    if (Algorithms::isContainsCycle(g) == "there is a negetive cycle")
        cout << "8 - isContainsCycle(g) == there is a negetive cycle" << endl;

    vector<vector<int>> graph9 = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph9);
    if (Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 3, 4}, B={1, 2}.")
        cout << "9 - isBipartite(g) == The graph is bipartite: A={0, 3, 4}, B={1, 2}." << endl;

    vector<vector<int>> graph10 = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
    };

    g.loadGraph(graph10);
    if (Algorithms::isContainsCycle(g) == "0")
        cout << "10 - isContainsCycle(g) == 0" << endl;
    

    vector<vector<int>> graph11 = {
        {0, 5, 1, 2, 10},
        {0, 0, 0, 0, 2},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},

    };
    g.loadGraph(graph11);
    if (Algorithms::isBipartite(g) == "Graph is not bipartite")
        cout << "11 - isBipartite(g) == is not bipartite" << endl;

    vector<vector<int>> graph12 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph12);
    if (Algorithms::shortestPath(g, 0, 2) == "0 -> 2")
        cout << "12 - shortestPath(g,0, 2) == 0 -> 2" << endl;

    vector<vector<int>> graph13 = {
        {0, 5, 1},
        {5, 0, 1},
        {1, 1, 0},
    };
    g.loadGraph(graph13);
    if (Algorithms::shortestPath(g, 0, 1) == "0 -> 2 -> 1")
        cout << "13 - shortestPath(g,0, 1) == 0 -> 2 -> 1" << endl;

    vector<vector<int>> graph14 = {
        {0, 5, 1, 2, 10},
        {0, 0, 0, 0, 2},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},

    };
    g.loadGraph(graph14);
    if (Algorithms::shortestPath(g, 0, 4) == "0 -> 3 -> 4")
        cout << "14 - shortestPath(g,0, 4) == 0 -> 3 -> 4" << endl;
    vector<vector<int>> birpatite = {
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},

        };
    g.loadGraph(birpatite);
    if (Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 5}, B={2, 3, 4}.")
        cout << "15 - isBipartite(g) == The graph is bipartite: A={0, 1, 5}, B={2, 3, 4}." << endl;
    

    vector<vector<int>> isnotbipartite = {
        {0, 1, 0, 0, 7},
        {1, 0, 7, 7, 0},
        {0, 7, 0, 1, 7},
        {0, 7, 1, 0, 7},
        {7, 0, 7, 7, 0},

    };
    g.loadGraph(isnotbipartite);
    if (Algorithms::isBipartite(g) == "Graph is not bipartite")
        cout << "16 - isBipartite(g) == is not bipartite" << endl;
}