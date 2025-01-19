#include <string>

#include <gtest/gtest.h>

#include "../../structures/Trees/Trees.hpp"

TEST(BinarySearchTree, BinarySerchTreeCreate) {
    BinarySearchTree<int> p;
    p.add(4);
    p.add(2);
    p.add(5);
    p.add(1);
    p.add(3);
    p.add(0);

    for (size_t i = 0; i <= 5; i++)
    {
        EXPECT_TRUE(p.contains(i));
    }
    
    EXPECT_FALSE(p.contains(6));
}
