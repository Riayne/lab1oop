#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray() : data(nullptr), size(0) {}

    DynamicArray(int n) : size(n) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    int getSize() const {
        return size;
    }

    int& at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& at(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw invalid_argument("New size cannot be negative");
        }

        int* newData = new int[newSize]();
        int elementsToCopy = (newSize < size) ? newSize : size;
        for (int i = 0; i < elementsToCopy; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1(5);
    cout << "Array 1: ";
    arr1.print();

    arr1.at(2) = 10;
    cout << "Array 1 after modification: ";
    arr1.print();

    DynamicArray arr2 = arr1;
    cout << "Array 2 (copy of Array 1): ";
    arr2.print();

    DynamicArray arr3 = move(arr1);
    cout << "Array 3 (moved from Array 1): ";
    arr3.print();
    cout << "Array 1 after move: ";
    arr1.print();

    arr3.resize(8);
    cout << "Array 3 after resize: ";
    arr3.print();

    return 0;
}
