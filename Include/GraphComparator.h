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
    std::vector<int> toThrowAway;

    static IntMap createIntMap(const Graph& targetGraph);

    void check() const;
public:
    GraphComparator(Graph& cGraph, Graph& pGraph, Graph& jGraph);
    void executeFilter() const;
};



#endif //GRAPHCOMPARATOR_H
