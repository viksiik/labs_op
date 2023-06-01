#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include "windows.h"

template<typename T>
class Array {
private:
    T* data;
    int capacity;
    int currentSize;

public:
    Array(int size);
    ~Array();
    int getSize() const;
    int find(const T& value) const;
    void insert(int position, const T& value);
    void remove(int position);

    class Iterator {
    private:
        T* current;
        T* end;

    public:
        Iterator(T* pointer, T* arrayEnd);
        void begin(Array<T>& arr);
        bool isEnd() const;
        T& value() const;
        void next();
    };

    Iterator getIterator();
private:
    void resize(int newCapacity);
};


#endif
