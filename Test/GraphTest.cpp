//
// Created by Wojtek on 10.02.2025.
//
#include <Graph.h>
#include <Node.h>
#include <gtest/gtest.h>
using Vector = std::vector<Node>;
namespace {
    Node sampleNodes[] = {{0, 5},{1,1}, {2, 6}, {3, 15}};
    Graph createSampleGraph(bool isReversed=false) {
        Graph sampleGraph(isReversed);
        for(int i = 0; i < sizeof(sampleNodes)/sizeof(Node); i++) {
            sampleGraph.addNode(sampleNodes[i]);
        }
        return sampleGraph;
    }
}
TEST(GraphInitTest, AllNodesAdded) {
    Graph sampleGraph = createSampleGraph();
    for(int i = 0; i < sizeof(sampleNodes)/sizeof(Node); i++) {
        sampleGraph.addNode(sampleNodes[i]);
    }
    EXPECT_EQ(sampleGraph.getAdjList().size(), 4);
}
TEST(GraphInitTest, AllEdgesDirectionedCorrectly) {
    Vector edges[4];
    Graph sampleGraph = createSampleGraph();
    auto it = sampleGraph.getAdjList().begin();
    for(int i = 0; i < 4; i++) {
        if(it == sampleGraph.getAdjList().end()) return;
        edges[i] = it->second;
        ++it;
    }
    EXPECT_EQ(edges[0].size(), 1);
    EXPECT_EQ(edges[0][0].getId(), 1);

    EXPECT_EQ(edges[1].size(), 0);

    EXPECT_EQ(edges[2].size(), 2);
    EXPECT_EQ(edges[2][0].getId(), 0);
    EXPECT_EQ(edges[2][1].getId(), 1);

    EXPECT_EQ(edges[3].size(), 3);
    EXPECT_EQ(edges[3][0].getId(), 0);
    EXPECT_EQ(edges[3][1].getId(), 1);
    EXPECT_EQ(edges[3][2].getId(), 2);
}
TEST(GraphInitTest, ReversedGraphCorrectEdges) {
    Vector edges[4];
    Graph reversedGraph = createSampleGraph(true);
    auto it = reversedGraph.getAdjList().begin();
    for(int i = 0; i < 4; i++) {
        if(it == reversedGraph.getAdjList().end()) return;
        edges[i] = it->second;
        ++it;
    }
    EXPECT_EQ(edges[0].size(), 2);
    EXPECT_EQ(edges[0][0].getId(), 2);
    EXPECT_EQ(edges[0][1].getId(), 3);

    EXPECT_EQ(edges[1].size(), 3);
    EXPECT_EQ(edges[1][0].getId(), 0);
    EXPECT_EQ(edges[1][1].getId(), 2);
    EXPECT_EQ(edges[1][2].getId(), 3);

    EXPECT_EQ(edges[2].size(), 1);
    EXPECT_EQ(edges[2][0].getId(), 3);

    EXPECT_EQ(edges[3].size(), 0);
}