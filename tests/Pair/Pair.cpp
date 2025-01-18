#include <string>

#include <gtest/gtest.h>

#include "../../structures/Pair/Pair.hpp"

TEST(Pair, PairWorksOk) {
    Pair<int, int> p = Pair<int, int>(3,4);
    EXPECT_EQ(+p,4);
    EXPECT_EQ(-p,3);
}
