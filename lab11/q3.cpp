#include <iostream>
#include <stdexcept>

class ArrayIndexOutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds!";
    }
};

template<typename T>
class SafeArray {
private:
    T* arr;
    size_t size;

public:
    SafeArray(size_t s) : size(s), arr(new T[s]) {}
    ~SafeArray() { delete[] arr; }

    T& operator[](size_t index) {
        if (index >= size) throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    size_t getSize() const { return size; }
};

// Demo
void testSafeArray() {
    SafeArray<int> sa(5);
    try {
        sa[0] = 10;
        sa[5] = 20;  // should throw
    } catch (const ArrayIndexOutOfBounds& e) {
        std::cerr << e.what() << std::endl;
    }
}
