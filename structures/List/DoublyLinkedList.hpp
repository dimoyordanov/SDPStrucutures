#pragma once

#include "../../structures/Optional/Optional.hpp"

template <typename T>
class DoublyLinkedList {
    private:
        template <typename L>
        struct Node{
            L value;
            Node<L>* next;
            Node<L>* prev;
            Node(L value): value(value), next(nullptr), prev(nullptr) {}
            Node(L value, Node<L>* next): value(value), next(next), prev(nullptr) {}
            Node(L value, Node<L>* next, Node<L>* prev): value(value), next(next), prev(prev) {}
            Node(Node&& node) {
                this->value = node.value;
                this->next = node.next;
                this->prev = node.prev;
                node.prev = nullptr;
                node.next=nullptr;
            }
        };
        using N = Node<T>;
        N *head;
        N *endNode;

    public:

        template <typename B>
        class IteratorLinkedList {
            Node<B>* elem;
            friend DoublyLinkedList<B>;
            public:
                IteratorLinkedList(): elem(nullptr){}
                IteratorLinkedList(Node<B>* node): elem(node){}
                IteratorLinkedList<B>& operator==(IteratorLinkedList<B>& a) {this->elem = a.elem; return *this;}
                bool valid() {return elem != nullptr;}
                Optional<B> get() {return (!valid())?Optional<B>():Optional<B>(elem->value);}
                IteratorLinkedList<B> next() {return (!valid())?IteratorLinkedList():IteratorLinkedList(this->elem->next);}
                IteratorLinkedList<B> prev() {return (!valid())?IteratorLinkedList():IteratorLinkedList(this->elem->prev);}
                bool equal(IteratorLinkedList<B>& val) {return this->elem == val.elem;}
                IteratorLinkedList<B>& operator++() {return *this = this->next();}
                IteratorLinkedList<B>& operator--() {return *this = this->prev();}
                IteratorLinkedList<B> operator++(int a) {IteratorLinkedList<B> v = *this; *this = this->next(); return v;}
                IteratorLinkedList<B> operator--(int a) {IteratorLinkedList<B> v = *this; *this = this->prev(); return v;}
                B operator*() {return elem->value;}
                bool operator==(IteratorLinkedList<B> elem) {return this->equal(elem);}
                bool operator!=(IteratorLinkedList<B> elem) {return !this->equal(elem);}
        };


        using I = IteratorLinkedList<T>;

        I begin() const{
            return I(this->head);
        }

        I last() const{
            return I(this->endNode);
        }

        I end() const{
            return I();
        }

        bool insertAfter(I position, const T& nodeValue) {
            if(!position.valid()) {
                if(isEmpty()){
                    this->endNode = this->head = new N(nodeValue);
                    return true;
                } 
                return false;
            }
            N* value = new N(nodeValue, position.elem->next, position.elem);
            position.elem->next = value;
            if (endNode == position.elem) {
                endNode = value;
            } else {
                value->next->prev = value;
            }
            return true;
        }

        bool insertBefore(I position, const T& nodeValue) {
            if(!position.valid()) {
                if(isEmpty()){
                    this->endNode = this->head = new N(nodeValue);
                    return true;
                } 
                return false;
            }
            N* value = new N(nodeValue, position.elem, position.elem->prev);
            position.elem->prev = value;
            if (head == position.elem) {
                head = value;
            } else {
                value->prev->next = value;
            }
            return true;
        }

        DoublyLinkedList() : head(nullptr), endNode(nullptr) {}

        DoublyLinkedList(DoublyLinkedList&& move) {
            this->head = move.head;
            this->endNode = move.endNode;
            move.head=move.endNode=nullptr;
        }

        DoublyLinkedList(const DoublyLinkedList& move) : head(nullptr), endNode(nullptr) {
            for (auto i : move){
                this->pushBack(i);
            }
        }

        DoublyLinkedList& operator=(const DoublyLinkedList& move) {
            for (auto i : move){
                this->pushBack(i);
            }
            return *this;
        }

        Optional<T> removeAfter(I position) {
            if(!position.valid()) {
                return Optional<T>();
            }
            Node<T>* value = position.elem->next;
            if(value == nullptr) {
                return Optional<T>();
            }
            position.elem->next = nullptr;
            T retValue = value->value;
            delete value;
            return retValue;
        }

        Optional<T> removeAt(I position) {
            if(!position.valid()) {
                return Optional<T>();
            }
            Node<T>* value = position.elem;

            if(value->prev == nullptr && value->next == nullptr) {
                this->head = this->endNode = nullptr;
            } else if(value->prev == nullptr) {
                this->head = value->next;
                this->head->prev = nullptr;
            } else if(value->next == nullptr) {
                this->endNode = value->prev;
                this->endNode->next = nullptr;
            } else {
                value->prev->next = value->next;
                value->next->prev = value->prev;
            }
            T retValue = value->value;
            delete value;
            return retValue;
        }

        bool isEmpty() const{
            return this->head==nullptr || this->endNode == nullptr;
        }

        bool pushFront(const T& value) {
            insertBefore(begin(), value);
            return true;
        }
        bool pushBack(const T& value) {
            insertAfter(last(), value);
            return true;
        }

        bool pushFront(T&& value) {
            insertBefore(begin(), value);
            return true;
        }
        bool pushBack(T&& value) {
            insertAfter(last(), value);
            return true;
        }

        Optional<T> popFront() {
            return this->removeAt(begin());
        }
        Optional<T> popBack() {
            return this->removeAt(last());
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

        static DoublyLinkedList<T> map(const DoublyLinkedList<T>& move, T (*f)(T)){
            DoublyLinkedList<T> list;
            for (auto i : move){
                list.pushBack(f(i));
            }
            return list;
        } 
        static DoublyLinkedList<T> filter(const DoublyLinkedList<T>& move, bool (*f)(T)){
            DoublyLinkedList<T> list;
            for (auto i : move){
                if (f(i)){
                    list.pushBack(i);
                }
            }
            return list;
        } 


        ~DoublyLinkedList(){
            erase();
        }

};