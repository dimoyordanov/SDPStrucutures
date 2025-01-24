#pragma once

#include "../../structures/List/LinkedList.hpp"

template <typename T>
class LinkedStack : protected LinkedList<T>
{
private:
public:
    LinkedStack() = default;
    ~LinkedStack() = default;

    bool isStackEmpty() {
        return this->isEmpty();
    }

    T peek(){
        return this->front();
    }

    void push(const T& value){
        this->pushFront(value);
    }

    void push(T&& value){
        this->pushFront(value);
    }

    T pop(){
        return this->popFront();
    }
};
