#pragma once

#include "../../structures/Optional/Optional.hpp"

template <typename T>
class LinkedList {
    private:
        template <typename L>
        struct Node{
            L value;
            Node<L>* next;
            Node(L value): value(value), next(nullptr) {}
            Node(L value, Node<L>* next): value(value), next(next) {}
            Node(Node&& node) {this->value = node.value; this->next = node.next; node.next=nullptr;}
        };
        Node<T> *head;
        Node<T> *end;

    public:
        LinkedList() : head(nullptr), end(nullptr) {}

        LinkedList(LinkedList&& move) {
            this->head = move.head;
            this->end = move.end;
            move.head=move.end=nullptr;
        }


        bool isEmpty() const{
            return this->head==nullptr || this->end == nullptr;
        }

        bool pushFront(T value) {
            this->head = new Node<T>(value, this->head);

            if (isEmpty()) {
                this->end = this->head;
            }
            return true;
        }
        bool pushBack(T value) {
            if (isEmpty()) {
              pushFront(value);
            } else {
                this->end = (this->end->next = new Node<T>(value));
            }
            return true;
        }

        Optional<T> popFront() {
            if (isEmpty()) {
              return Optional<T>();
            } 
            Node<T>* temp = this->head;
            this->head = temp->next;
            T value = temp->value;
            delete temp;
            return Optional<T>(value);
        }

        Optional<T> front() {
            if (isEmpty()) {
              return Optional<T>();
            }
            return Optional<T>(this->head->value);
        }

        Optional<T> back() {
            if (isEmpty()) {
              return Optional<T>();
            } 
            return Optional<T>(this->end->value);
        }

        void erase() {
            while (!isEmpty()) {
                this->popFront();
            }
        }

        ~LinkedList(){
            erase();
        }

};