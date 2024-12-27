#include "SimpleVector.h"
#include <Arduino.h>

// Constructor
template <typename T>
SimpleVector<T>::SimpleVector() : capacity(4), size(0)
{
    data = new T[capacity];
}

// Destructor
template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] data;
}

// Resize function
template <typename T>
void SimpleVector<T>::resize()
{
    capacity *= 2;
    T *newData = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

// Add element to the end
template <typename T>
void SimpleVector<T>::push_back(const T &value)
{
    if (size == capacity)
    {
        resize();
    }
    data[size++] = value;
}

// Access an element by index (modifiable)
template <typename T>
T &SimpleVector<T>::operator[](int index)
{
    return data[index];
}

// Access an element by index (read-only)
template <typename T>
const T &SimpleVector<T>::operator[](int index) const
{
    return data[index];
}

// Get the current size
template <typename T>
int SimpleVector<T>::getSize() const
{
    return size;
}

// Explicit instantiations
template class SimpleVector<String>;
template class SimpleVector<int>;
