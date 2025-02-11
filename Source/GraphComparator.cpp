//
// Created by Wojtek on 11.02.2025.
//

#include "GraphComparator.h"

IntMap GraphComparator::createIntMap(const Graph& targetGraph) {
    IntMap map;
    for(auto it = targetGraph.getAdjList().begin(); it != targetGraph.getAdjList().end(); ++it) {
        for(int i = 0; i < it->second.size(); i++) {
            map[it->first.getId()].emplace_back(it->second[i].getId());
        }
    }
    return map;
}

void GraphComparator::check() const {
    const IntMap cIds = createIntMap(cGraph);
    const IntMap pIds = createIntMap(pGraph);
    const IntMap jIds = createIntMap(jGraph);
    std::vector<int> commonKeys;

    for(const auto& [key, vecC] : cIds) {
        auto itP = pIds.find(key);
        auto itJ = jIds.find(key);
        if(itP != pIds.end() && itJ != jIds.end()) {
            const std::vector<int>& vecP = itP->second;
            const std::vector<int>& vecJ = itJ->second;

            std::vector<int> commonCP;
            std::vector<int> commonAll;
            std::ranges::set_intersection(vecC.begin(), vecC.end(),
                vecP.begin(), vecP.end(),
                std::back_inserter(commonCP));
            std::ranges::set_intersection(commonCP.begin(), commonCP.end(),
                vecJ.begin(), vecJ.end(),
                std::back_inserter(commonAll));

            if(!commonAll.empty()) {
                commonKeys.push_back(key);
            }
        }
    }
    std::cout << "common keys to delete: ";
    for(const auto& x: commonKeys) {
        std::cout << x << " ";
    }
    std::cout<<"\n";
}

GraphComparator::GraphComparator(Graph &cGraph, Graph &pGraph, Graph &jGraph)
: cGraph(cGraph), pGraph(pGraph), jGraph(jGraph) {}

void GraphComparator::executeFilter() const {
    check();
}
