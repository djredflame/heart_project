#include "SimpleVector.h"
#include <Arduino.h>

// Constructor
/**
 * @brief Constructs a SimpleVector with an initial capacity of 4.
 */
template <typename T>
SimpleVector<T>::SimpleVector() : capacity(4), size(0)
{
    data = new T[capacity];
}

// Destructor
/**
 * @brief Destructs the SimpleVector and releases allocated memory.
 */
template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] data;
}

// Resize function
/**
 * @brief Resizes the vector to double its current capacity.
 */
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

/**
 * @brief Adds an element to the end of the vector.
 * Resizes the vector if the current capacity is reached.
 *
 * @param value The value to be added to the vector.
 */
template <typename T>
void SimpleVector<T>::push_back(const T &value)
{
    if (size == capacity)
    {
        resize();
    }
    data[size++] = value;
}

/**
 * @brief Overloads the subscript operator to access elements.
 *
 * @param index The index of the element to access.
 * @return Reference to the element at the specified index.
 */
template <typename T>
T &SimpleVector<T>::operator[](int index)
{
    return data[index];
}

/**
 * @brief Overloads the subscript operator to access elements (read-only).
 *
 * @param index The index of the element to access.
 * @return Const reference to the element at the specified index.
 */
template <typename T>
const T &SimpleVector<T>::operator[](int index) const
{
    return data[index];
}

/**
 * @brief Returns the size of the vector.
 *
 * @return The number of elements in the vector.
 */
template <typename T>
int SimpleVector<T>::getSize() const
{
    return size;
}

// Explicit instantiations
template class SimpleVector<String>;
template class SimpleVector<int>;