#ifndef ARRAYSTATIC
#define ARRAYSTATIC

template <typename T>
class ArrayStatic {
    private:
        Optional<T>* value;
        size_t capacity;
    public:

        template <typename L>
        class IteratorArrayStatic{
            size_t capacity;
            Optional<L>* list;
            size_t location;
            Optional<L> empty;
            public:
            IteratorArrayStatic(Optional<L>* list, size_t capacity, size_t location){
                this->capacity = capacity;
                this->list = list;
                this->location = location;
            }
            IteratorArrayStatic(const IteratorArrayStatic& iterator){
                this->capacity = iterator.capacity;
                this->list = iterator.list;
                this->location = iterator.location;
            }

            bool valid() const { return this->capacity > this->location; }
            operator bool() const { return valid(); }
            Optional<L>& get () {if (!valid()) {return empty;} else {return this->list[location];}}
            Optional<L>& operator*() {return get();}
            IteratorArrayStatic<L>& next(){this->location++; return *this;}
            IteratorArrayStatic<L>& prev(){this->location--; return *this;}
            IteratorArrayStatic<L>& operator++() { return next();}
            IteratorArrayStatic<L> operator++(int a) {IteratorArrayStatic<L> iterator2(*this);next();return iterator2;}
            bool operator==(const IteratorArrayStatic& iterator) {return this->location == iterator.location;}
        };

        using I = IteratorArrayStatic<T>;

        I begin(){
            return I(this->value, this->capacity, 0);
        }

        I end(){
            return I(this->value, this->capacity, this->capacity);
        }

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