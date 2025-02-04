#include <iostream>

using namespace std;


int* resizeArray(int* arr, int oldSize, int newSize) {
    int* newArr = new int[newSize]; 
    for (int i = 0; i < oldSize; i++) {
        newArr[i] = arr[i]; 
    }
    delete[] arr; 
    return newArr;
}

int main() {
    int capacity = 5; 
    int size = 0;     
    int* arr = new int[capacity]; 

    
    for (int i = 1; i <= 12; i++) {
        if (size >= capacity) {
            capacity *= 2;
            arr = resizeArray(arr, size, capacity);
        }
        arr[size++] = i * 10; 
    }

    
    arr = resizeArray(arr, size, size);

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nFinal array size: " << size << endl;

    delete[] arr;
    return 0;
}
