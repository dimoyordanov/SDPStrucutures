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
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTests, LinkListedAddRandom) {
    LinkedList<int> list;
    list.pushBack(1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.front(), 1);
    list.insertAfter(list.begin(), 2);
    list.insertAfter(list.begin(), 5);
    list.insertAfter(++list.begin(), 3);
    list.insertAfter(list.begin(), 10);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 10);
    EXPECT_EQ(list.popFront(), 5);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListTests, TestRemovePopBack) {
    LinkedList<int> list;
    list.pushBack(1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.front(), 1);
    list.insertAfter(list.begin(), 2);
    list.insertAfter(list.begin(), 5);
    list.insertAfter(list.begin(), 3);
    list.insertAfter(list.begin(), 10);
    EXPECT_EQ(list.popBack(), 2);
    EXPECT_EQ(list.popBack(), 5);
    EXPECT_FALSE(list.isEmpty());
}


TEST(LinkedListTests, LinkListedPushBack) {
    LinkedList<int> list;
    for(int i = 0; i < 20; i++){
        list.pushBack(i);
    }
    for(int i = 0; i < 20; i++){
        EXPECT_EQ(list.front(), i);
        EXPECT_EQ(list.popFront(), i);
    }
    
}
TEST(LinkedListTests, LinkListedPushFront) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }
    for(int i = 0; i < 20; i++){
        EXPECT_EQ(list.front(), i);
        EXPECT_EQ(list.popFront(), i);
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
TEST(LinkedListTests, LinkListMap) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    LinkedList<int> list2 = LinkedList<int>::map(list, [](int i){return i*i;});

    int b = 0;
    for(auto i: list2){
        EXPECT_EQ(i, b*b);
        b+=1;
    }
}

TEST(LinkedListTests, LinkedListFilter) {
    LinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    LinkedList<int> list2 = LinkedList<int>::filter(list, [](int i)->bool{return i%2;});

    int b = 1;
    for(auto i: list2){
        EXPECT_EQ(i, b);
        b+=2;
    }
}