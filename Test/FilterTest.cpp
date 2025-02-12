//
// Created by Wojtek on 12.02.2025.
//
#include <Graph.h>
#include <GraphComparator.h>
#include <Node.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
    Node cNodes[] = {{0,4}, {1,15}, {2,18},
                    {3,43},{4,12}, {5,13}};
    Node pNodes[] = {{0,2}, {1,1}, {2,4},
                        {3,5}, {4,4}, {5,3}};
    Node jNodes[] = {{0,10}, {1,8}, {2,5},
                        {3,9}, {4,11}, {5,2}};
    Graph createSampleGraph(const Node* nodes, bool isReversed=false) {
        Graph sampleGraph(isReversed);
        for(int i = 0; i < sizeof(cNodes)/sizeof(Node); i++) {
            sampleGraph.addNode(nodes[i]);
        }
        return sampleGraph;
    }
}
TEST(FilterTest, CorrectResult) {
    Graph cGraph = createSampleGraph(cNodes);
    Graph pGraph = createSampleGraph(pNodes);
    Graph jGraph = createSampleGraph(jNodes, true);
    GraphComparator comparator(cGraph, pGraph, jGraph);
    int result = comparator.executeFilter();
    EXPECT_EQ(result, 3);
    ASSERT_THAT(comparator.getCommonKeys(), testing::ElementsAre(2,3,5));
}