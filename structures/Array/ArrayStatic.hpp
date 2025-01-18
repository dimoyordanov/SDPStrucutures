#ifndef ARRAYSTATIC
#define ARRAYSTATIC

template <typename T>
class ArrayStatic {
    private:
        Optional<T>* value;
        size_t capacity;
    public:
        ArrayStatic(size_t s = 20){
            value = new Optional<T>[s];
            capacity = s;
        }
        Optional<T> get(size_t index) const{
            if (index < 0 || index >= capacity) {
                return Optional<T>();
            }
            return this->value[index];
        }
        bool set(size_t index, const T& value) {
            if (index < 0 || index >= capacity) {
                return false;
            }
            if (this->value[index].check()) {
                return false;
            }
            this->value[index].set(value);
            return true;
        }
        bool set(size_t index, T&& value) {
            if (index < 0 || index >= capacity) {
                return false;
            }
            if (this->value[index].check()) {
                return false;
            }
            this->value[index].set(value);
            return true;
        }
        bool remove(size_t index) {
            if (index < 0 || index >= capacity) {
                return false;
            }
            if (!this->value[index].check()) {
                return false;
            }
            this->value[index].unset();
            return true;
        }
        size_t size() const{
            return this->capacity;
        }
        ~ArrayStatic(){
            delete[] value;
        }
};

#endif