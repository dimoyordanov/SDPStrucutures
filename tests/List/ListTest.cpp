#include <string>

#include <gtest/gtest.h>

#include "../../structures/List/LinkedList.hpp"

TEST(LinkedListTests, LinkListedEmpty) {
    LinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTests, LinkListedCreate) {
    LinkedList<int> list;
    list.pushBack(1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(*(list.front()), 1);
    EXPECT_EQ(*(list.popFront()), 1);
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTests, LinkListedPushBack) {
    LinkedList<int> list;
    for(int i = 0; i < 20; i++){
        list.pushBack(i);
    }
    for(int i = 0; i < 20; i++){
        EXPECT_EQ(*(list.front()), i);
        EXPECT_EQ(*(list.popFront()), i);
    }
    
}
TEST(LinkedListTests, LinkListedPushFront) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }
    for(int i = 0; i < 20; i++){
        EXPECT_EQ(*(list.front()), i);
        EXPECT_EQ(*(list.popFront()), i);
    }
}

TEST(LinkedListTests, LinkListIterator) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }
    int b = 0;
    for(auto i: list){
        EXPECT_EQ(i, b++);
    }
}

TEST(LinkedListTests, LinkListEqual) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    LinkedList<int> list2 = list;

    int b = 0;
    for(auto i: list2){
        EXPECT_EQ(i, b++);
    }
}

TEST(LinkedListTests, LinkListCopy) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    LinkedList<int> list2(list);

    int b = 0;
    for(auto i: list2){
        EXPECT_EQ(i, b++);
    }
}