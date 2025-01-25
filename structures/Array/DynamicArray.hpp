#pragma once

template <typename T>
class DynamicArray;

template <typename B> 
class DynamicArrayIterator{
        const DynamicArray<B>* arr;
        int index;
    public:
        DynamicArrayIterator(int index, const DynamicArray<B>* arr): index(index), arr(arr) {}
        DynamicArrayIterator<B>& operator++() { return *this = DynamicArrayIterator(index+1, arr);}
        DynamicArrayIterator<B> operator++(int a) {DynamicArrayIterator<B> aa = *this ;*this = DynamicArrayIterator(index+1, arr);return aa;}
        DynamicArrayIterator<B>& operator--() { return *this = DynamicArrayIterator(index-1, arr);}
        DynamicArrayIterator<B> operator--(int a) {DynamicArrayIterator<B> aa = *this ;*this = DynamicArrayIterator(index-1, arr);return aa;}
        DynamicArrayIterator<B>& operator=(DynamicArrayIterator<B> v) {this->arr = v.arr; this->index = v.index;return *this;}
        bool operator==(DynamicArrayIterator<B>& val) {return this->index == val.index;}
        bool operator!=(DynamicArrayIterator<B>& val2) {return !(*this==val2);};
        B operator*() {return arr->getAt(this->index);}
};

template <typename T>
class DynamicArray
{
private:
    friend DynamicArrayIterator<T>;
    T* array;
    size_t arraySize;
    size_t capacity;

public:

    void resize(DynamicArray<T>* source, size_t newCapacity) {
        T* temp = new T[newCapacity];
        for (size_t i = 0; i < source->arraySize && i < newCapacity; i++)
        {
            temp[i] = source->array[i];
        }
        delete this->array;
        this->capacity = newCapacity;
        this->array = temp;
    }

    DynamicArrayIterator<T> begin() const{
        return DynamicArrayIterator<T>(0, this);
    }
    DynamicArrayIterator<T> end() const{
        return DynamicArrayIterator<T>(arraySize, this);
    }

    DynamicArray(): array(nullptr), arraySize(0), capacity(1) {
        this->array = new T[1];
    }
    DynamicArray(size_t capacity): array(nullptr), arraySize(0), capacity(capacity) {
        this->array = new T[capacity];
    }
    DynamicArray(const DynamicArray<T>& arr): array(nullptr), arraySize(0), capacity(1) {
        this->array = new T[1];
        for(T i: arr) {
            this->pushBack(i);
        }
    }

    bool insertAt(T data, size_t index) {
        if(index > arraySize){
            return false;
        }
        if(capacity < arraySize){
            resize(this, capacity*2);
        }
        for(size_t ind = arraySize; ind > index; ind--){
            this->array[ind] = this->array[ind-1]; 
        }
        this->array[index] = data;
        this->arraySize++;
        return true;
    }

    T removeAt(size_t index) {
        if(index > arraySize){
            throw std::runtime_error("Trying to access element that is out of bounds");
        }
        T data = this->array[index];
        for(size_t ind = index; ind < this->arraySize-1; ind++){
            this->array[ind] = this->array[ind+1]; 
        }
        this->arraySize--;
        return data;
    }

    T getAt(size_t index) const{
        if(index > arraySize){
            throw std::runtime_error("Trying to access element that is out of bounds");
        }
        return this->array[index];
    }

    void pushBack(T data){
        insertAt(data, this->arraySize);
    }

    void pushFront(T data){
        insertAt(data, 0);
    }

    T popBack(){
        return removeAt(this->arraySize);
    }
    ~DynamicArray(){
        delete[] array;
    }
    
};
