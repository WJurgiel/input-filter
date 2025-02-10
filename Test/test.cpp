//
// Created by Wojtek on 10.02.2025.
//
#include <gtest/gtest.h>

namespace{
    int GetCoolNumber() {return 40;}
}
TEST(Suite, name) {
    EXPECT_EQ(GetCoolNumber(), 40);
}
