//
// Created by Wojtek on 11.02.2025.
//

#ifndef GRAPHCOMPARATOR_H
#define GRAPHCOMPARATOR_H
#include <Graph.h>
#include <algorithm>

using IntMap = std::map<int, std::vector<int>>;
class GraphComparator {
private:
    Graph& cGraph;
    Graph& pGraph;
    Graph& jGraph;
    std::vector<int> commonKeys;

    static IntMap createIntMap(const Graph& targetGraph);

    std::vector<int> check() const;
public:
    GraphComparator(Graph& cGraph, Graph& pGraph, Graph& jGraph);
    [[nodiscard]] int executeFilter();
    [[nodiscard]] std::vector<int> getCommonKeys() const;
};



#endif //GRAPHCOMPARATOR_H
