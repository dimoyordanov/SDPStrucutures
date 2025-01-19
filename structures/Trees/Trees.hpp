#pragma once

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
            elem = ((*elem)->data > value)?&((*elem)->right):&((*elem)->left)){}
        
        return *elem;
    }

public:
    BinarySearchTree() : root(nullptr) {};
    
    bool add(T value) {
        No* elem = new No(value);
        gotoElement(value) = elem;
        return true;
    }
    
    bool contains(T value) {
        return gotoElement(value)!=nullptr;
    }
};
