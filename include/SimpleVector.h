#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H

#include <Arduino.h>

// Minimalistic Vector class
// Provides dynamic storage for elements

template <typename T>
class SimpleVector
{
private:
    T *data;      // Pointer to the data
    int capacity; // Maximum capacity
    int size;     // Current number of elements

    void resize(); // Internal function to expand storage

public:
    SimpleVector();
    ~SimpleVector();

    void push_back(const T &value);       // Adds an element to the end
    T &operator[](int index);             // Access an element (modifiable)
    const T &operator[](int index) const; // Access an element (read-only)
    int getSize() const;                  // Returns the number of stored elements
};

#endif