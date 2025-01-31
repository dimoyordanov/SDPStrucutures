#pragma once

template <typename T>
class DynamicArray;

template <typename B> 
class DynamicArrayIterator{
        DynamicArray<B>* arr;
        int index;
    public:
        DynamicArrayIterator(int index, DynamicArray<B>* arr): index(index), arr(arr) {}
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

    DynamicArrayIterator<T> begin() {
        return DynamicArrayIterator<T>(0, this);
    }
    DynamicArrayIterator<T> end() {
        return DynamicArrayIterator<T>(arraySize, this);
    }

    void resize() {
        T* temp = new T[capacity*2];
        for (size_t i = 0; i < arraySize; i++)
        {
            temp[i] = this->array[i];
        }
        delete this->array;
        this->capacity *= 2;
        this->array = temp;
    }
    DynamicArray(): array(new T[1]), arraySize(0), capacity(4) {}
    DynamicArray(size_t capacity): array(new T[capacity]), arraySize(0), capacity(capacity) {}
    
    bool insertAt(T data, size_t index) {
        if(index > arraySize){
            return false;
        }
        if(capacity-2 <= arraySize){
            resize();
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

    T getAt(size_t index) {
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

    T popBack(T data){
        return removeAt(this->arraySize);
    }
    ~DynamicArray(){
        delete[] array;
    }
    
};
