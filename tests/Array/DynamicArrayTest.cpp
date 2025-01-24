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

