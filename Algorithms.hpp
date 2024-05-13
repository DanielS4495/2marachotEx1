//211358486
//danielsamson10@gmail.com
#include "Graph.hpp"
#include <string>
#include <unordered_map>


namespace ariel {
    // namespace Algorithms{
    class Algorithms {
    private:
        static int DFS(int v, vector<bool>& visited, vector<int>& parent, Graph& graph);
        static void DFSReverse(int v, vector<bool>& visited, Graph& graph);
        static int detectCycleDFS(int v, vector<bool>& visited, vector<int>& parent,  Graph& g);
        static std::string constructCyclePath(int v, const vector<int>& parent);
        static bool isDirectedGraph(Graph& g);
    public:
        static bool isConnected(Graph& g);
        static std::string shortestPath(Graph& g, int start, int end);//מחזיר מסלול הקצר ביותר
        static std::string isContainsCycle(Graph& g);//מחזיר האם קיים מעגל 
        static std::string isBipartite(Graph& g);//ומחזיר את החלוקה של הגרף לגרף דו-צדדי 
        static std::string negativeCycle(Graph& g);//מחזיר האם קיים מעגל עם משקלים שלילים
        static bool isBipartiteUtil(Graph& g, int src, unordered_map<int, int>& color);
        
};
// }
}