//211358486
//danielsamson10@gmail.com
#pragma once

#include <iostream> 
#include <vector>
#include <stdexcept>
using namespace std;

namespace ariel {
    class Graph {
        private:
            // bool allIntegral(const std::vector<std::vector<int>>& vec);
            std::vector<std::vector<int>> g;
        public:
            void loadGraph(std::vector<std::vector<int>>& graph);
            void printGraph();
    };
}