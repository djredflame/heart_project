
#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H

#include <Arduino.h>

/**
 * @brief A minimalistic dynamic array class.
 *
 * This class provides dynamic storage for elements of type T.
 * It supports basic operations such as adding elements and accessing them.
 *
 * @tparam T The type of elements stored in the vector.
 */
template <typename T>
class SimpleVector
{
private:
    T *data;      ///< Pointer to the dynamically allocated array of elements.
    int capacity; ///< The maximum number of elements the vector can hold before resizing.
    int size;     ///< The current number of elements in the vector.

    /**
     * @brief Resizes the internal storage to accommodate more elements.
     *
     * This function is called internally when the vector needs to expand its capacity.
     */
    void resize();

public:
    /**
     * @brief Constructs an empty SimpleVector.
     */
    SimpleVector();

    /**
     * @brief Destroys the SimpleVector and frees allocated memory.
     */
    ~SimpleVector();

    /**
     * @brief Adds an element to the end of the vector.
     *
     * @param value The element to be added.
     */
    void push_back(const T &value);

    /**
     * @brief Accesses an element at the specified index (modifiable).
     *
     * @param index The index of the element to access.
     * @return A reference to the element at the specified index.
     */
    T &operator[](int index);

    /**
     * @brief Accesses an element at the specified index (read-only).
     *
     * @param index The index of the element to access.
     * @return A const reference to the element at the specified index.
     */
    const T &operator[](int index) const;

    /**
     * @brief Returns the number of elements currently stored in the vector.
     *
     * @return The number of elements in the vector.
     */
    int getSize() const;
};

#endif