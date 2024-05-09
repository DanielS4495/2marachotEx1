//211358486
//danielsamson10@gmail.com
#include "Graph.hpp"
#include <string>

namespace ariel
{
    // namespace Algorithms{
    class Algorithms{
    public:
        static bool isConnected(Graph g);
        static std::string shortestPath(Graph g, int start, int end);//מחזיר מסלול הקצר ביותר ולא אינט
        static bool isContainsCycle(Graph g);//מחזיר מעגל ולא אינט
        static std::string isBipartite(Graph g);//ומחזיר את החלוקה של הגרף לגרף דו-צדדי ולא אינט
        static std::string negativeCycle(Graph g);
};
// }
}