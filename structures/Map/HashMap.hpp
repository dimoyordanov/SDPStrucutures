#pragma once

#include "../../structures/Array/DynamicArray.hpp"
#include "../../structures/List/LinkedList.hpp"
#include <memory>

template <typename K, typename V>
struct KeyValuePair
{
    K key;
    V value;
    KeyValuePair(K key, V value): key(key), value(value) {}
};


template <typename K, typename V>
class HashMap
{
private:
    DynamicArray<LinkedList<KeyValuePair<K, V> >* >* array;
    size_t ellementsInserted;
    double resize_index = 0.8;
    size_t capacity;
protected:
    void resize(size_t newCapacity) {
        DynamicArray<LinkedList<KeyValuePair<K, V> >* >* newArr = new DynamicArray<LinkedList<KeyValuePair<K, V> >* >(newCapacity);
        for (size_t i = 0; i < newCapacity; i++)
        {
            newArr->pushBack(new LinkedList<KeyValuePair<K, V>>());
        }
        for (LinkedList<KeyValuePair<K, V>>* i: *array)
        {
            if(!i->isEmpty()) {
                for (KeyValuePair<K,V> z: *i) {      
                    size_t hash = std::hash<K>{}(z.key);
                    newArr->getAt(hash%this->capacity)->pushBack(z);
                }
            }
        }

        for (auto I : *array)
        {
            delete I;
        }

        delete array;
        array = newArr;
        capacity = newCapacity;
    }
public:
    HashMap(): array(nullptr), ellementsInserted (0), capacity(16) {
        array = new DynamicArray<LinkedList<KeyValuePair<K, V> >* >(16);
        for (size_t i = 0; i < 16; i++)
        {
            array->pushBack(new LinkedList<KeyValuePair<K, V>>());
        }
        
    }

    ~HashMap() {
        delete array;
    }

    void put(K key, V value) {
        if (capacity*resize_index < ellementsInserted) {
            resize(capacity*2);
        }
        size_t hash = std::hash<K>{}(key);
        this->array->getAt(hash%this->capacity)->pushBack(KeyValuePair<K,V>(key, value));
        ellementsInserted++;
    }

    V get(K key) {
        size_t hash = std::hash<K>{}(key);
        for (KeyValuePair<K, V> i: *(this->array->getAt(hash%this->capacity))) {
            if (key == i.key) {
                return i.value;
            }
        }
        throw std::runtime_error("Unable to find element");
    }

    bool contains(K key) {
        size_t hash = std::hash<K>{}(key);
        for (KeyValuePair<K, V> i: *(this->array->getAt(hash%this->capacity))) {
            if (key == i.key) {
                return true;
            }
        }
        return false;
    }
};
