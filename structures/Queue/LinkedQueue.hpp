#pragma once

#include "../../structures/List/LinkedList.hpp"

template <typename T>
class LinkedQueue : protected LinkedList<T>
{
private:
public:
    LinkedQueue() = default;
    ~LinkedQueue() = default;

    bool isQueueEmpty() {
        return this->front().check();
    }

    bool operator==(LinkedQueue& qu){
        return LinkedList<T>::operator==(qu);
    }

    T peek(){
        return this->front();
    }

    void enqueue(const T& value){
        this->pushBack(value);
    }

    void enqueue(T&& value){
        this->pushBack(value);
    }

    T dequeue(){
        return this->popFront();
    }
};
