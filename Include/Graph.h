//
// Created by Wojtek on 10.02.2025.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <map>
#include <Node.h>


class Graph {
private:
    bool isReversed;
    std::map<Node, std::vector<Node>> adjList;
    void addEdge(const Node& src, const Node& dest);
public:
    explicit Graph(bool isReversed=false);
    void addNode(const Node& node);
    [[nodiscard]] std::map<Node, std::vector<Node>> getAdjList() const;
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};



#endif //GRAPH_H
