#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"
#include "../../structures/Array/DynamicArray.hpp"

TEST(DynamicArrayTest, BasicCase) {
    DynamicArray<int> array;
    array.pushBack(0);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);
    array.pushBack(4);
    array.pushBack(5);
    EXPECT_EQ(array.getAt(5).get(), 5);
    EXPECT_EQ(array.getAt(4).get(), 4);
    EXPECT_EQ(array.getAt(3).get(), 3);
    EXPECT_FALSE(array.getAt(10).check());

    int b = 0;
    for(int i: array){
        EXPECT_EQ(i, b++);
    }

}

