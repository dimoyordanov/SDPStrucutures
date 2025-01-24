#pragma once

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
        using N = Node<T>;
        N *head;
        N *endNode;

    public:

        template <typename B>
        class IteratorLinkedList {
            Node<B>* elem;
            friend LinkedList<B>;
            public:
                IteratorLinkedList(): elem(nullptr){}
                IteratorLinkedList(Node<B>* node): elem(node){}
                IteratorLinkedList<B>& operator==(IteratorLinkedList<B>& a) {this->elem = a.elem; return *this;}
                bool valid() {return elem != nullptr;}
                B get() {
                    if (!valid()) {
                        throw std::runtime_error("Unable to access null pointer");
                    } else {
                        return elem->value;
                    }
                }
                IteratorLinkedList<B> next() {return (!valid())?IteratorLinkedList():IteratorLinkedList(this->elem->next);}
                bool equal(IteratorLinkedList<B>& val) {return this->elem == val.elem;}
                IteratorLinkedList<B>& operator++() {return *this = this->next();}
                IteratorLinkedList<B> operator++(int a) {IteratorLinkedList<B> v = *this; *this = this->next(); return v;}
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

        bool operator==(LinkedList<T>& list){
            for (I a = list.begin(), b = this->begin();
                 a!=list.end() || b != this->end();
                 (a++,b++))
            {
                if(((b.elem == nullptr && a.elem!=b.elem) ||
                    (a.elem == nullptr && a.elem!=b.elem)) || 
                    (*a!=*b)) {
                    return false;
                }
            }
            return true;
        }

        T removeAfter(I position) {
            if(!position.valid()) {
                throw std::runtime_error("Can not remove after null");
            }
            Node<T>* value = position.elem->next;
            if(value == nullptr) {
                throw std::runtime_error("Can not remove null element");
            }
            position.elem->next = value->next;
            if (value->next == nullptr) {
                this->endNode = position.elem;
            }
            T retValue = value->value;
            delete value;
            return retValue;
        }

        T removeAt(I position) {
            if(!position.valid()) {
                throw std::runtime_error("Can not remove at null");
            }
            Node<T>* value = position.elem;
            T retValue = value->value;
            if(position.elem == head) {
                head = position.elem->next;
                position.elem->next = nullptr;
                delete value;
                return retValue;
            } else {
                bool found = false;
                I iterator;
                for (iterator = this->begin(); iterator != end(); ++iterator){
                    if(position.elem == iterator.elem->next){
                        found = true;
                        break;
                    }
                }
                if (found == true) {
                    return removeAfter(iterator);
                } else {
                    throw std::runtime_error("Unable to find the element in the linked list");
                }
            }
        }

        bool insertAfter(I position, const T& nodeValue) {
            if(!position.valid()) {
                if(isEmpty()){
                    this->endNode = this->head = new N(nodeValue, this->head);
                    return true;
                } 
                return false;
            }
            N* value = new N(nodeValue, position.elem->next);
            position.elem->next = value;
            if(endNode == position.elem) {
                endNode = value;
            }
            return true;
        }

        bool insertBefore(I position, const T& nodeValue) {
            if(!position.valid()) {
                if(isEmpty()){
                    this->endNode = this->head = new N(nodeValue, this->head);
                    return true;
                } 
                return false;
            }
            if (position.elem == head) {
                N* value = new N(nodeValue, position.elem);
                this->head = value;
                return true;
            }
            bool found = false;
            I iterator;
            for (iterator = this->begin(); iterator != end(); ++iterator){
                if(position.elem == iterator.elem->next){
                    found = true;
                    break;
                }
            }
            if (found) {
                insertAfter(iterator, nodeValue);
            }
            return found;
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

        T popFront() {
            return removeAt(this->begin());
        }

        T popBack() {
            return removeAt(this->last());
        }

        T front() {
            if (isEmpty()) {
                throw std::runtime_error("Linked list is null");
            }
            return this->head->value;
        }

        T back() {
            if (isEmpty()) {
                throw std::runtime_error("Linked list is null");
            } 
            return this->endNode->value;
        }

        void erase() {
            while (!isEmpty()) {
                this->popFront();
            }
        }

        static LinkedList<T> map(const LinkedList<T>& move, T (*f)(T)){
            LinkedList<T> list;
            for (auto i : move){
                list.pushBack(f(i));
            }
            return list;
        } 
        static LinkedList<T> filter(const LinkedList<T>& move, bool (*f)(T)){
            LinkedList<T> list;
            for (auto i : move){
                if (f(i)){
                    list.pushBack(i);
                }
            }
            return list;
        } 


        ~LinkedList(){
            erase();
        }

};