#include <string>

#include <gtest/gtest.h>

#include "../../structures/Trees/Trees.hpp"


TEST(BinarySearchTree, BinarySearchTreeAddElement) {
    BinarySearchTree<int> p;
    p.add(1);

    EXPECT_TRUE(p.contains(1));
}

TEST(BinarySearchTree, BinarySearchTreeAdd2Element) {
    BinarySearchTree<int> p;
    p.add(1);
    p.add(2);

    EXPECT_TRUE(p.contains(1));
    EXPECT_TRUE(p.contains(2));
}

TEST(BinarySearchTree, BinarySearchTreeEmpty) {
    BinarySearchTree<int> p;

    EXPECT_FALSE(p.contains(6));
}


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


TEST(BinarySearchTree, BinarySerchTreeDeleteNode) {
    BinarySearchTree<int> p;
    for(int i: {5,3,8,4,2,1,7,9,6,0}){
        p.add(i);
    }

    for (size_t i = 0; i < 10; i++)
    {
        EXPECT_TRUE(p.contains(i));
    }
    for (size_t i = 0; i < 10; i++)
    {

        EXPECT_TRUE(p.contains(i));
        EXPECT_TRUE(p.deleteElem(i));
        EXPECT_FALSE(p.contains(i));
        EXPECT_FALSE(p.deleteElem(i));
    }

    EXPECT_FALSE(p.deleteElem(20));
}
