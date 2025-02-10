//
// Created by Wojtek on 10.02.2025.
//

#include "Graph.h"

void Graph::addEdge(const Node &src, const Node &dest) {
    adjList[src].emplace_back(dest);
}

Graph::Graph(const bool isReversed) {
    this->isReversed = isReversed;
}

void Graph::addNode(const Node &node) {
    adjList[node] = std::vector<Node>();
    for(auto it = adjList.begin(); it != adjList.end(); ++it) {
        if(it->first.getId() == node.getId()) continue;
        if(node.getValue() < it->first.getValue()) {
            (isReversed) ? addEdge(node, it->first) : addEdge(it->first, node);
        }else if (node.getValue() == it->first.getValue()) {
            addEdge(node, it->first);
            addEdge(it->first, node);
        }
        else {
            (isReversed) ? addEdge(it->first, node) : addEdge(node, it->first);
        }
    }
}

std::map<Node, std::vector<Node>> Graph::getAdjList() const {
    return adjList;
}

std::ostream & operator<<(std::ostream &os, const Graph &graph) {
    for(auto it = graph.adjList.begin(); it != graph.adjList.end(); ++it) {
        os << "( " << it->first.getId()  << ", " << it->first.getValue() << " ): ";
        for(const auto& node : it->second) {
            os << "( " << node.getId() << ", " << node.getValue() << " ) -->";
        }
        os << "NULL\n";
    }
    return os;
}
