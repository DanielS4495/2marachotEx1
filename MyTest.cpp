#include "Algorithms.hpp"
#include "Graph.hpp"
#include <algorithm>
#include <string>

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using ariel::Algorithms;
// TEST_CASE("Test isConnected")
int main(int argc, char **argv)
{

    //    ariel::Graph g;
    //     // 3x3 matrix that represents a connected graph.
    //     vector<vector<int>> graph = {
    //         {0, 1, 0},
    //         {1, 0, 1},
    //         {0, 1, 0}};
    //     g.loadGraph(graph); // Load the graph to the object.

    //     g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    //      cout << Algorithms::negativeCycle(g) << endl;
    //     cout << Algorithms::isConnected(g) << "h"<<endl;        // Should print: "1" (true).
    //     cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    //     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    //     cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    //     // 5x5 matrix that represents a non-connected graph with a cycle.
    //     vector<vector<int>> graph2 = {
    //         {0, 1, 1, 0, 0},
    //         {1, 0, 1, 0, 0},
    //         {1, 1, 0, 1, 0},
    //         {0, 0, 1, 0, 0},
    //         {0, 0, 0, 0, 0}};

    //     g.loadGraph(graph2); // Load the graph to the object.

    //     g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    //     cout << Algorithms::isConnected(g)<<"h" << endl;        // Should print: "0" (false).
    //     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    //     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    //     cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

    //     // 5x5 matrix that reprsents a connected weighted graph.
    //     vector<vector<int>> graph3 = {
    //         {0, 1, 2, 0, 0},
    //         {1, 0, 3, 0, 0},
    //         {2, 3, 0, 4, 0},
    //         {0, 0, 4, 0, 5},
    //         {0, 0, 0, 5, 0}};
    //     g.loadGraph(graph3); // Load the graph to the object.

    //     g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    //     cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    //     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
    //     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    //     cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."

    //     // 5x4 matrix that reprsents invalid graph.
    //     vector<vector<int>> graph4 = {
    //         {0, 1, 2, 0},
    //         {1, 0, 3, 0},
    //         {2, 3, 0, 4},
    //         {0, 0, 4, 0},
    //         {0, 0, 0, 5}};
    //     try
    //     {
    //         g.loadGraph(graph4); // Load the graph to the object.
    //     }
    //     catch (const std::invalid_argument &e)
    //     {
    //         cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    //     }

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
        {0, 5, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {7, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
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
        cout << "5 - negativeCycle(g) == there is a negetive cycle" << endl;

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
        cout << "6 - negativeCycle(g) == there is a negetive cycle" << endl;

    vector<vector<int>> graph7 = {
        {0, 3, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {-2, 0, 0, 11, 0},
        {11, 0, 0, 0, -2},
        {0, 0, -2, 0, 0},
    };

    g.loadGraph(graph7);
    if (Algorithms::negativeCycle(g) == "there is no negetive cycle")
        cout << "7 - negativeCycle(g) == there is no negetive cycle" << endl;

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
        {0, 5, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 1},
        {0, 0, 0, 0, -6, 0},
        {0, -4, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0},
        {0, 0, 3, 0, 0, 0},
    };
    g.loadGraph(graph9);
    if (Algorithms::isContainsCycle(g) == "1 -> 3 -> 4 -> 2 -> 1")
        cout << "9 - isContainsCycle(g) == 1 -> 3 -> 4 -> 2 ->1 " << endl;

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

    vector<vector<int>> birpatite = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},

    };

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
    if (Algorithms::shortestPath(g, 0, 2) == "2 -> 0")
        cout << "12 - shortestPath(g,0, 2) == 2 -> 0" << endl;

    vector<vector<int>> graph13 = {
        {0, 5, 1},
        {5, 0, 1},
        {1, 1, 0},
    };
    g.loadGraph(graph13);
    if (Algorithms::shortestPath(g, 0, 1) == "1 -> 2 -> 0")
        cout << "13 - shortestPath(g,0, 1) == 1 -> 2 -> 0" << endl;

    vector<vector<int>> graph14 = {
        {0, 5, 1, 2, 10},
        {0, 0, 0, 0, 2},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},

    };
    g.loadGraph(graph14);
    if (Algorithms::shortestPath(g, 0, 4) == "4 -> 3 -> 0")
        cout << "14 - shortestPath(g,0, 4) == 4 -> 3 -> 0" << endl;

    g.loadGraph(birpatite);
    if (Algorithms::isBipartite(g) == "Graph is bipartite.")
        cout << "15 - isBipartite(g) == Graph is bipartite." << endl;

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