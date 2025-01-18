#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"
#include "../../structures/Array/ArrayStatic.hpp"

TEST(ArrayTest, TestCreateSizeIsOk) {
    ArrayStatic<int>* inter = new ArrayStatic<int>(20);
    EXPECT_EQ(inter->size(), 20);
    delete inter;
}

TEST(ArrayTest, TestSetAndGetIsOk) {
    ArrayStatic<int>* inter = new ArrayStatic<int>(20);
    EXPECT_TRUE(inter->set(0, 2));
    EXPECT_TRUE(inter->get(0).check());
    EXPECT_EQ(*(inter->get(0)), 2);
    delete inter;
}

TEST(ArrayTest, TestSetAndGetIsOkWhenDifferent) {
    ArrayStatic<int>* inter = new ArrayStatic<int>(20);
    EXPECT_TRUE(inter->set(0, 2));
    EXPECT_TRUE(inter->set(1, 3));
    EXPECT_TRUE(inter->get(0).check());
    EXPECT_EQ(*(inter->get(0)), 2);
    delete inter;
}

TEST(ArrayTest, TestSetAndGetIsOkWhenNotExistent) {
    ArrayStatic<int>* inter = new ArrayStatic<int>(20);
    EXPECT_TRUE(inter->set(0, 2));
    EXPECT_TRUE(inter->set(1, 3));
    EXPECT_FALSE(inter->get(3).check());
    delete inter;
}