#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"
#include "../../structures/Array/DynamicArray.hpp"

TEST(DynamicArrayTest, asicCase) {
    DynamicArray<int> array;
    array.pushBack(3);
    array.pushBack(4);
    array.pushBack(5);

}

