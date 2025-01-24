#ifndef ARRAYSTATIC
#define ARRAYSTATIC

#include <exception>

template <typename T, size_t capacity>
class ArrayStatic {
    private:
        T value[capacity];
    public:

        template <typename L, size_t capacity2>
        class IteratorArrayStatic{
            L* list;
            size_t location;
            public:
            IteratorArrayStatic(L* list, size_t location){
                this->list = list;
                this->location = location;
            }
            IteratorArrayStatic(const IteratorArrayStatic& iterator){
                this->list = iterator.list;
                this->location = iterator.location;
            }

            bool valid() const { return capacity2 > this->location; }
            operator bool() const { return valid(); }
            L& get () {
                if (!valid()) {
                    throw std::runtime_error("Trying to access ellement that is out of bounrs");
                } else {
                    return this->list[location];
                }
            }
            L& operator*() {return get();}
            IteratorArrayStatic<L, capacity2>& next(){this->location++; return *this;}
            IteratorArrayStatic<L, capacity2>& prev(){this->location--; return *this;}
            IteratorArrayStatic<L, capacity2>& operator++() { return next();}
            IteratorArrayStatic<L, capacity2> operator++(int a) {IteratorArrayStatic<L, capacity2> iterator2(*this);next();return iterator2;}
            bool operator==(const IteratorArrayStatic& iterator) {return this->location == iterator.location;}
        };

        using I = IteratorArrayStatic<T, capacity>;

        I begin(){
            return I(this->value, 0);
        }

        I end(){
            return I(this->value, this->capacity);
        }

        ArrayStatic(){
        }

        ArrayStatic(const ArrayStatic<T, capacity>& array) {
            for(int i = 0; i < capacity; i++){
                this->value[i] = array.value[i];
            }
        }

        T get(size_t index) const{
            if (index < 0 || index >= capacity) {
                throw std::runtime_error("Unable to access element since it is out of bounds");
            }
            return this->value[index];
        }
        bool set(size_t index, const T& value) {
            if (index < 0 || index >= capacity) {
                throw std::runtime_error("Unable to access element since it is out of bounds");
            }
            this->value[index] = value;
            return true;
        }
        bool set(size_t index, T&& value) {
            if (index < 0 || index >= capacity) {
                throw std::runtime_error("Unable to access element since it is out of bounds");
            }
            this->value[index] = value;
            return true;
        }
        size_t size() const{
            return capacity;
        }
        ~ArrayStatic(){
        }
};

#endif