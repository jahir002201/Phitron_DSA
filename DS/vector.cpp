#include<iostream>
#include<stdexcept>
using namespace std;

template <typename T>
class Vector {
public:
    T* val;
    size_t vector_size;
    size_t vector_capacity;

    Vector(size_t capacity = 10) {
        val = new T[capacity];
        vector_size = 0;
        vector_capacity = capacity;
    }

    ~Vector() {
        delete[] val;
    }

    void push_back(const T& value) {
        if (vector_size == vector_capacity) {
            resize(vector_capacity * 2);
        }
        val[vector_size++] = value;
    }

    void pop_back() {
        if (vector_size > 0) {
            --vector_size;
        }
    }

    size_t size() const {
        return vector_size;
    }

    size_t capacity() const {
        return vector_capacity;
    }

    void resize(size_t new_capacity) {
        if (new_capacity > vector_capacity) {
            T* new_val = new T[new_capacity];
            for (size_t i = 0; i < vector_size; ++i) {
                new_val[i] = val[i];
            }
            delete[] val;
            val = new_val;
            vector_capacity = new_capacity;
        }
    }

    bool empty() const {
        return vector_size == 0;
    }

    T& at(size_t index) {
        if (index >= vector_size) {
            throw out_of_range("Index out of range");
        }
        return val[index];
    }

    T& operator[](size_t index) {
        return val[index];
    }

    T& front() {
        if (empty()) {
            throw out_of_range("Vector is empty");
        }
        return val[0];
    }

    T& back() {
        if (empty()) {
            throw out_of_range("Vector is empty");
        }
        return val[vector_size - 1];
    }

    void clear() {
        vector_size = 0;
    }

    void insert(size_t index, const T& value) {
        if (index > vector_size) {
            throw out_of_range("Index out of range");
        }
        if (vector_size == vector_capacity) {
            resize(vector_capacity * 2);
        }
        for (size_t i = vector_size; i > index; --i) {
            val[i] = val[i - 1];
        }
        val[index] = value;
        ++vector_size;
    }

    void erase(size_t index) {
        if (index >= vector_size) {
            throw out_of_range("Index out of range");
        }
        for (size_t i = index; i < vector_size - 1; ++i) {
            val[i] = val[i + 1];
        }
        --vector_size;
    }

    T* begin() {
        return val;
    }

    T* end() {
        return val + vector_size;
    }

    T* rbegin() {
        return val + vector_size - 1;
    }

    T* rend() {
        return val - 1;
    }

    void swap(Vector<T>& other) {
        std::swap(val, other.val);
        std::swap(vector_size, other.vector_size);
        std::swap(vector_capacity, other.vector_capacity);
    }

    void shrink_to_fit() {
        resize(vector_size);
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > vector_capacity) {
            resize(new_capacity);
        }
    }
};

int main() {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;

    vec.pop_back();
    cout << "After pop_back(), size: " << vec.size() << endl;

    vec.insert(1, 15);
    cout << "After insert at index 1, second element: " << vec.at(1) << endl;

    vec.erase(2);
    cout << "After erase at index 2, third element: " << vec.at(2) << endl;

    return 0;
}