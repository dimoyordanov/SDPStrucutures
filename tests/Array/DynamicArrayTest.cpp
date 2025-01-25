#include <string>

#include <gtest/gtest.h>

#include "../../structures/Array/DynamicArray.hpp"

TEST(DynamicArrayTest, BasicCase) {
    DynamicArray<int> array;
    array.pushBack(0);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);
    array.pushBack(4);
    array.pushBack(5);
    EXPECT_EQ(array.getAt(5), 5);
    EXPECT_EQ(array.getAt(4), 4);
    EXPECT_EQ(array.getAt(3), 3);
    EXPECT_THROW(array.getAt(10), std::runtime_error);

    int b = 0;
    for(int i: array){
        EXPECT_EQ(i, b++);
    }

}

TEST(DynamicArrayTest, pushFrontCase) {
    DynamicArray<int> array;
    array.pushFront(0);
    array.pushFront(1);
    array.pushFront(2);
    array.pushFront(3);
    array.pushFront(4);
    array.pushFront(5);
    EXPECT_EQ(array.getAt(0), 5);
    EXPECT_EQ(array.getAt(1), 4);
    EXPECT_EQ(array.getAt(2), 3);
    EXPECT_THROW(array.getAt(10), std::runtime_error);

    int b = 5;
    for(int i: array){
        EXPECT_EQ(i, b--);
    }

}


TEST(DynamicArrayTest, removeLastCase) {
    DynamicArray<int> array;
    array.pushFront(0);
    array.pushFront(1);
    array.pushFront(2);
    array.pushFront(3);
    array.pushFront(4);
    array.pushFront(5);
    array.popBack();
    EXPECT_EQ(array.getAt(0), 5);
    EXPECT_EQ(array.getAt(1), 4);
    EXPECT_THROW(array.getAt(10), std::runtime_error);

    int b = 5;
    for(int i: array){
        EXPECT_EQ(i, b--);
    }

}


TEST(DynamicArrayTest, removeMidCase) {
    DynamicArray<int> array;
    array.pushFront(0);
    array.pushFront(1);
    array.pushFront(2);
    array.pushFront(3);
    array.pushFront(4);
    array.pushFront(5);
    array.removeAt(3);
    EXPECT_EQ(array.getAt(0), 5);
    EXPECT_EQ(array.getAt(1), 4);
    EXPECT_EQ(array.getAt(2), 3);
    EXPECT_EQ(array.getAt(3), 1);
    EXPECT_EQ(array.getAt(4), 0);
    EXPECT_THROW(array.getAt(10), std::runtime_error);
}

TEST(DynamicArrayTest, removeFirstCase) {
    DynamicArray<int> array;
    array.pushFront(0);
    array.pushFront(1);
    array.pushFront(2);
    array.pushFront(3);
    array.pushFront(4);
    array.pushFront(5);
    array.removeAt(0);
    EXPECT_EQ(array.getAt(0), 4);
    EXPECT_EQ(array.getAt(1), 3);
    EXPECT_THROW(array.getAt(10), std::runtime_error);

    int b = 4;
    for(int i: array){
        EXPECT_EQ(i, b--);
    }

}

TEST(DynamicArrayTest, testCopyConstructor) {
    DynamicArray<int> array;
    array.pushFront(0);
    array.pushFront(1);
    array.pushFront(2);
    array.pushFront(3);
    array.pushFront(4);
    array.pushFront(5);
    DynamicArray<int> array2(array);
    array2.removeAt(0);
    EXPECT_EQ(array2.getAt(0), 4);
    EXPECT_EQ(array2.getAt(1), 3);
    EXPECT_THROW(array2.getAt(10), std::runtime_error);

    int b = 4;
    for(int i: array2){
        EXPECT_EQ(i, b--);
    }

    b = 5;
    for(int i: array){
        EXPECT_EQ(i, b--);
    }

}
