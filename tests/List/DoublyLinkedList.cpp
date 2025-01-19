#include <string>

#include <gtest/gtest.h>

#include "../../structures/List/DoublyLinkedList.hpp"

TEST(DoublyLinkedListTests, LinkListedEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTests, LinkListedCreate) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(*(list.front()), 1);
    EXPECT_EQ(*(list.popFront()), 1);
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTests, LinkListedAddRandom) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(*(list.front()), 1);
    list.insertAfter(list.begin(), 2);
    list.insertAfter(list.begin(), 5);
    list.insertAfter(++list.begin(), 3);
    list.insertAfter(list.begin(), 10);
    EXPECT_EQ(*(list.popFront()), 1);
    EXPECT_EQ(*(list.popFront()), 10);
    EXPECT_EQ(*(list.popFront()), 5);
    EXPECT_EQ(*(list.popFront()), 3);
    EXPECT_EQ(*(list.popFront()), 2);
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTests, TestRemovePopBack) {
    DoublyLinkedList<int> list;
    list.pushBack(1);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(*(list.front()), 1);
    list.insertAfter(list.begin(), 2);
    list.insertAfter(list.begin(), 5);
    list.insertAfter(list.begin(), 3);
    list.insertAfter(list.begin(), 10);
    EXPECT_EQ(*(list.popBack()), 2);
    EXPECT_EQ(*(list.popBack()), 5);
    EXPECT_FALSE(list.isEmpty());
}




TEST(DoublyLinkedListTests, LinkListedPushBack) {
    DoublyLinkedList<int> list;
    for(int i = 0; i < 20; i++){
        list.pushBack(i);
    }
    for(int i = 0; i < 20; i++){
        EXPECT_EQ(*(list.front()), i);
        EXPECT_EQ(*(list.popFront()), i);
    }
    
}
TEST(DoublyLinkedListTests, LinkListedPushFront) {
    DoublyLinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }
    for(int i = 0; i < 20; i++){
        EXPECT_EQ(*(list.front()), i);
        EXPECT_EQ(*(list.popFront()), i);
    }
}

TEST(DoublyLinkedListTests, LinkListIterator) {
    DoublyLinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }
    int b = 0;
    for(auto i: list){
        EXPECT_EQ(i, b++);
    }
}

TEST(DoublyLinkedListTests, LinkListEqual) {
    DoublyLinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    DoublyLinkedList<int> list2 = list;

    int b = 0;
    for(auto i: list2){
        EXPECT_EQ(i, b++);
    }
}

TEST(DoublyLinkedListTests, LinkListCopy) {
    DoublyLinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    DoublyLinkedList<int> list2(list);

    int b = 0;
    for(auto i: list2){
        EXPECT_EQ(i, b++);
    }
}
TEST(DoublyLinkedListTests, LinkListMap) {
    DoublyLinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    DoublyLinkedList<int> list2 = DoublyLinkedList<int>::map(list, [](int i){return i*i;});

    int b = 0;
    for(auto i: list2){
        EXPECT_EQ(i, b*b);
        b+=1;
    }
}

TEST(DoublyLinkedListTests, LinkedListFilter) {
    DoublyLinkedList<int> list;
    
     for(int i = 20; i >= 0; i--){
        list.pushFront(i);
    }

    DoublyLinkedList<int> list2 = DoublyLinkedList<int>::filter(list, [](int i)->bool{return i%2;});

    int b = 1;
    for(auto i: list2){
        EXPECT_EQ(i, b);
        b+=2;
    }
}