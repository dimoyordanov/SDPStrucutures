#ifndef OPTIONAL
#define OPTIONAL

#include <exception>

template <typename T>
class Optional
{
private:
    T data;
    bool hasValue;

public:
    Optional(T data) : data(data), hasValue(true) {};
    Optional() : hasValue(false) {};

    Optional(const Optional& val) {
        this->data = val.data;
        this->hasValue = val.hasValue;
    }

    Optional& operator=(const Optional& val){
        this->data = val.data;
        this->hasValue = val.hasValue;
        return *this;
    }

     Optional(Optional&& val){
        this->data = val.data;
        this->hasValue = val.hasValue;
    }

    void set(T data) {this->data = data; this->hasValue = true;}

    void unset() {this->hasValue = false;}

    bool check() { return this->hasValue; }
    operator bool() { return check(); }

    T get() { return this->data; }
    T operator*() { return get(); }
};


#endif