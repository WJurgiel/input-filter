#include <Graph.h>
#include <iostream>
#include <Node.h>

#include "GraphComparator.h"

int main() {
    const Node cEdges[] = {
        {0,300}, {1,20}, {2,4}, { 3,200}, {4, 200}};
    const Node pEdges[] = {
        {0,2}, {1,1}, {2,2}, {3,1}, {4,1}};
    const Node jEdges[] = {
        {0,10}, {1,2}, {2,10}, {3,1}, {4, 11}
    };
    Graph cGraph, pGraph, jGraph(true);
    for(int i = 0; i < sizeof(cEdges) / sizeof(Node); i++) {
        cGraph.addNode(cEdges[i]);
        pGraph.addNode(pEdges[i]);
        jGraph.addNode(jEdges[i]);
    }
    std::cout << "C:\n";
    std::cout << cGraph << '\n';

    std::cout << "P:\n";
    std::cout << pGraph << '\n';

    std::cout << "J:\n";
    std::cout << jGraph << '\n';

    GraphComparator comparator(cGraph,pGraph,jGraph);
    comparator.executeFilter();
    return 0;
}
