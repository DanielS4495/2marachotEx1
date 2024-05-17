// 211358486
// danielsamson10@gmail.com
#include "Graph.hpp"
#include <string>
#include <unordered_map>

namespace ariel
{
    class Algorithms
    {
    private:
        static int DFS(int v, vector<bool> &visited, vector<int> &parent, Graph &graph);
        static std::string constructCyclePath(int v, const vector<int> &parent);
        static bool bfs(Graph &g, int src, std::vector<int> &color,
                        std::vector<int> &groupA, std::vector<int> &groupB);

    public:
        static bool isConnected(Graph &g);                             // מחזיר האם הגרף קשיר
        static std::string shortestPath(Graph &g, int start, int end); // מחזיר מסלול הקצר ביותר
        static std::string isContainsCycle(Graph &g);                  // מחזיר האם קיים מעגל
        static std::string isBipartite(Graph &g);                      // ומחזיר את החלוקה של הגרף לגרף דו-צדדי
        static std::string negativeCycle(Graph &g);                    // מחזיר האם קיים מעגל עם משקלים שלילים
    };
}