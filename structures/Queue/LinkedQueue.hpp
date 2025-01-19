#pragma once

#include "../../structures/List/LinkedList.hpp"

template <typename T>
class LinkedQueue : protected LinkedList<T>
{
private:
public:
    LinkedQueue() = default;
    ~LinkedQueue() = default;

    Optional<T> peek(){
        return this->front();
    }

    void enqueue(const T& value){
        this->pushBack(value);
    }

    void enqueue(T&& value){
        this->pushBack(value);
    }

    Optional<T> pop(){
        return this->popFront();
    }
};
