if(BUILD_TESTING)
    add_executable(GraphTest GraphTest.cpp ../Source/Graph.cpp ../Source/Node.cpp)
    add_executable(FilterTest FilterTest.cpp ../Source/Graph.cpp ../Source/Node.cpp ../Source/GraphComparator.cpp)

    target_link_libraries(GraphTest PRIVATE GTest::gtest_main)
    target_link_libraries(FilterTest PRIVATE GTest::gtest_main GTest::gmock_main)

    include(GoogleTest)
    gtest_discover_tests(GraphTest)
    gtest_discover_tests(FilterTest)
endif()
