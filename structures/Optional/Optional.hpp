#ifndef OPTIONAL
#define OPTIONAL

#include <exception>

template <typename T>
class Optional
{
private:
    T data;
    bool set;

public:
    Optional(T data) : data(data), set(true) {};
    Optional() : set(false) {};

    Optional(const Optional& val) {
        this->data = val.data;
        this->set = val.set;
    }

    Optional& operator=(const Optional& val){
        this->data = val.data;
        this->set = val.set;
    }

    bool check() { return this->set; }
    operator bool() { return check(); }

    T get() { return this->data; }
    T operator*() { return get(); }
};


#endif