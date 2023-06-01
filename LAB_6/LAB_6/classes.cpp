#include "classes.h"

template<typename T>
Array<T>::Array(int size) : capacity(size), currentSize(0) {
    data = new T[capacity];
}

template<typename T>
Array<T>::~Array() {
    delete[] data;
}

template<typename T>
int Array<T>::getSize() const {
    return currentSize;
}

template<typename T>
int Array<T>::find(const T& value) const {
    for (int i = 0; i < currentSize; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void Array<T>::insert(int position, const T& value) {
    if (position >= 0 && position <= currentSize) {
        if (currentSize == capacity) {
            resize(capacity * 2);
        }
        for (int i = currentSize; i > position; i--) {
            data[i] = data[i - 1];
        }

        data[position] = value;
        currentSize++;
    }
}

template<typename T>
void Array<T>::remove(int position) {
    if (position >= 0 && position < currentSize) {
        for (int i = position; i < currentSize - 1; i++) {
            data[i] = data[i + 1];
        }

        currentSize--;
        if (currentSize <= capacity / 4) {
            resize(capacity / 2);
        }
    }
}

template<typename T>
typename Array<T>::Iterator Array<T>::getIterator() {
    return typename Array<T>::Iterator(data, data + currentSize);
}

template<typename T>
Array<T>::Iterator::Iterator(T* pointer, T* arrayEnd) : current(pointer), end(arrayEnd) {
}

template<typename T>
void Array<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < currentSize; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}


template<typename T>
void Array<T>::Iterator::begin(Array<T>& arr) {
    current = arr.data;
}

template<typename T>
bool Array<T>::Iterator::isEnd() const {
    return current == end;
}

template<typename T>
T& Array<T>::Iterator::value() const {
    return *current;
}

template<typename T>
void Array<T>::Iterator::next() {
    if (current != end) {
        current++;
    }
}


