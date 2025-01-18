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
        Node<T> *endNode;

    public:

        template <typename B>
        class IteratorLinkedList {
            Node<B>* elem;
            public:
                IteratorLinkedList(): elem(nullptr){}
                IteratorLinkedList(Node<B>* node): elem(node){}
                IteratorLinkedList<B>& operator==(IteratorLinkedList<B>& a) {this->elem = a.elem; return *this;}
                bool valid() {return elem != nullptr;}
                Optional<B> get() {return (!valid())?Optional<B>():Optional<B>(elem->value);}
                IteratorLinkedList<B> next() {return (!valid())?IteratorLinkedList():IteratorLinkedList(this->elem->next);}
                bool equal(IteratorLinkedList<B>& val) {return this->elem == val.elem;}
                IteratorLinkedList<B>& operator++() {return *this = this->next();}
                IteratorLinkedList<B> operator++(int a) {IteratorLinkedList<B> v = this; *this = this->next(); return v;}
                B operator*() {return elem->value;}
                bool operator==(IteratorLinkedList<B> elem) {return this->equal(elem);}
                bool operator!=(IteratorLinkedList<B> elem) {return !this->equal(elem);}
        };

        IteratorLinkedList<T> begin() const{
            return IteratorLinkedList<T>(this->head);
        }

        IteratorLinkedList<T> last() const{
            return IteratorLinkedList<T>(this->endNode);
        }

        IteratorLinkedList<T> end() const{
            return IteratorLinkedList<T>();
        }

        LinkedList() : head(nullptr), endNode(nullptr) {}

        LinkedList(LinkedList&& move) {
            this->head = move.head;
            this->endNode = move.endNode;
            move.head=move.endNode=nullptr;
        }

        LinkedList(const LinkedList& move) : head(nullptr), endNode(nullptr) {
            for (auto i : move){
                this->pushBack(i);
            }
        }

        LinkedList& operator=(const LinkedList& move) {
            for (auto i : move){
                this->pushBack(i);
            }
            return *this;
        }


        bool isEmpty() const{
            return this->head==nullptr || this->endNode == nullptr;
        }

        bool pushFront(T value) {
            this->head = new Node<T>(value, this->head);

            if (isEmpty()) {
                this->endNode = this->head;
            }
            return true;
        }
        bool pushBack(T value) {
            if (isEmpty()) {
              pushFront(value);
            } else {
                this->endNode = (this->endNode->next = new Node<T>(value));
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
            return Optional<T>(this->endNode->value);
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