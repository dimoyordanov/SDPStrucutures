#pragma once

#include "../../structures/Stack/LinkedStack.hpp"
#include "../../structures/Queue/LinkedQueue.hpp"

template <typename T>
class BinarySearchTree
{
private:
    template <typename L>
    struct Node {
        L data;
        using N = Node<L>;
        N* left;
        N* right;
        Node<L>(L data): data(data) { }
        Node<L>(L data, N* left, N* right) : data(data), left(left), right(right) {}
    };

    using No = Node<T>;

    No* root;

protected:
    Node<T>*& gotoElement(T value) {
        No** elem;
        for(elem = &(this->root);
            (*elem) != nullptr && (*elem)->data != value;
            elem = ((*elem)->data < value)?&((*elem)->right):&((*elem)->left)){}
        
        return *elem;
    }
    Node<T>*& findMinBox(No* start) {
        No** elem;
        for(elem = &(start);
            (*elem) != nullptr;
            elem = &((*elem)->left)){}
        
        return *elem;
    }

public:
    BinarySearchTree() : root(nullptr) {};

    bool add(T value) {
        No*& val = gotoElement(value);
        if (val != nullptr) {
            return false;
        }
        val = new No(value);
        return true;
    }
    
    bool contains(T value) {
        return gotoElement(value)!=nullptr;
    }

    bool deleteElem(T value) {
        No*& val = gotoElement(value);
        No* orig = val;
        if (val == nullptr) {
            return false;
        }
        No*& elem = findMinBox(val->right);
        elem = val->left;
        val = val->right;
        delete orig;
        return true;
    }
};
