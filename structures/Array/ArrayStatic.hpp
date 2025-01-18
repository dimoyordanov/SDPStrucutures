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

        ArrayStatic(ArrayStatic&& array){
            this->value = array.value;
            this->capacity = array.capacity;

            array.value = nullptr;
            array.capacity = 0;
        }

        ArrayStatic(const ArrayStatic& array){
            value = new Optional<T>[array.capacity];
            capacity = array.capacity;
            for(int i = 0; i < capacity; i++){
                if(array.value[i].check()){
                    this->value[i] = array.value[i];
                }
            }
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