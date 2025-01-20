#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"
#include "../../structures/Array/DynamicArray.hpp"

TEST(DynamicArrayTest, asicCase) {
    DynamicArray<int> array;
    array.pushBack(3);
    array.pushBack(4);
    array.pushBack(5);
    EXPECT_EQ(array.getAt(2).get(), 5);
    EXPECT_EQ(array.getAt(1).get(), 4);
    EXPECT_EQ(array.getAt(0).get(), 3);
    EXPECT_FALSE(array.getAt(4).check());
}

