#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"
#include "../../structures/Array/ArrayStatic.hpp"

TEST(ArrayTest, TestCreateSizeIsOk) {
    ArrayStatic<int, 20>* inter = new ArrayStatic<int, 20>();
    EXPECT_EQ(inter->size(), 20);
    delete inter;
}

TEST(ArrayTest, TestSetAndGetIsOk) {
    ArrayStatic<int, 20>* inter = new ArrayStatic<int, 20>();
    EXPECT_TRUE(inter->set(0, 2));
    EXPECT_TRUE(inter->get(0));
    EXPECT_EQ(inter->get(0), 2);
    delete inter;
}

TEST(ArrayTest, TestSetAndGetIsOkWhenDifferent) {
    ArrayStatic<int, 20>* inter = new ArrayStatic<int, 20>();
    EXPECT_TRUE(inter->set(0, 2));
    EXPECT_TRUE(inter->set(1, 3));
    EXPECT_TRUE(inter->get(0));
    EXPECT_EQ(inter->get(0), 2);
    delete inter;
}

TEST(ArrayTest, TestSetAndGetIsOkWhenNotExistent) {
    ArrayStatic<int, 20>* inter = new ArrayStatic<int, 20>();
    EXPECT_TRUE(inter->set(0, 2));
    EXPECT_TRUE(inter->set(1, 3));
    EXPECT_THROW(inter->get(21), std::runtime_error);
    delete inter;
}

TEST(ArrayTest, TestCopyContructor) {
    ArrayStatic<int, 20>* inter = new ArrayStatic<int, 20>();
    EXPECT_TRUE(inter->set(0, 2));
    ArrayStatic<int, 20>* inter2 = new ArrayStatic<int, 20>(*inter);
    EXPECT_EQ(inter2->get(0), 2);
    delete inter;
    delete inter2;
}

TEST(ArrayTest, testIterator) {
    ArrayStatic<int, 20>* inter = new ArrayStatic<int, 20>();
    for(int i = 0;i<20;i++){
        EXPECT_TRUE(inter->set(i, i+1));
    }
    auto a = inter->begin();
    for(int i = 0; i<20; i++){
        EXPECT_EQ(*a,i+1);
        a++;
    }
    EXPECT_FALSE(a.valid());
    delete inter;
}