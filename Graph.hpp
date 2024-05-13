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
            std::vector<std::vector<int>> weights;
        public:
            void loadGraph(const vector<vector<int>>& graph);
            void printGraph();
            size_t getsize();
            std::vector<int> getNeighbors(int v) const; 
            std::vector<int> getReverseNeighbors(int v) const; 
            int getWeight(size_t u, size_t v) const;
    };
}