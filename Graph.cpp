//211358486
//danielsamson10@gmail.com
// #include "Graph.hpp"
// #include <vector>
// #include <iostream>

// using namespace std;
// namespace Ariel{
//     class Graph{
//         vector<vector<int>> g;
//         public:
//             void loadGraph(vector<vector<int>>& graph){
               
//                 int n = graph.size(); // Get the number of rows
//                 bool b = true;
//                 // Check if it is a square matrix
//                 if (n == 0 || n != graph[0].size()){
//                     cout << "Invalid graph: The graph is not a square matrix." << endl;
//                     return;
//                 }
//                 // Check if each row has exactly n elements and elements are integers
//                 for (int i = 0; i < n; ++i) {
//                     if (graph[i].size() != n)
//                         b = false;
//                     for (int j = 0; j < n; ++j) {
//                         if (!std::is_integral<decltype(graph[i][j])>::value)
//                             b = false;
//                     }
//                 }
//                 if(!b){
//                     cout << "Invalid graph: The graph does not have an integral values." << endl;
//                     return;
//                 }
//                 else this->g = graph; // copy the metrix to the metrix class
//             }
//             void printGraph(){ 
//                 int n = g.size();
//                  for (const auto& row : this->g) {
//                     for (int val : row) {
//                         cout << val << " ";
//                     }
//                     cout << endl;
//                     }
//             }
//     };
// }
#include "Graph.hpp"
// #include <algorithm> // for std::all_of

using namespace std;

namespace ariel {
            vector<vector<int>> g;

            void loadGraph(const vector<vector<int>>& graph) {
                long unsigned int n = graph.size(); // Get the number of rows
                if (n == 0) {
                    throw invalid_argument("Invalid graph: Empty graph.");
                }

                for (int i = 0; i < n; ++i) {
                    if (graph[i].size() != n)
                        throw invalid_argument("Invalid graph: The graph does not have an integral values.");
                    for (int j = 0; j < n; ++j) {
                        if (!std::is_integral<decltype(graph[i][j])>::value)
                             throw invalid_argument("Invalid graph: The graph does not have an integral values.");
                    }
                }

                // Copy the matrix to the class member
                g = graph;
            }

            void printGraph(){
                for (const auto& row : g) {
                    for (auto val : row) {
                        cout << val << " ";
                    }
                    cout << endl;
                }
            }

            // bool allIntegral(const std::vector<std::vector<int>>& vec){
            //     return all_of(vec.begin(), vec.end(), [](int val) {
            //         return std::is_integral<int>::value;
            //     });
            // }


} // namespace ariel
