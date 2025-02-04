#include <iostream>

using namespace std;

void* addToArray(void* arr, int size, int addValue) {
    int* intArray = (int*)arr; 

    for (int i = 0; i < size; i++) {
        intArray[i] += addValue; 
    }

    return arr; 
}

int main() {
    const int size = 5;
    int myArray[size] = {1, 2, 3, 4, 5}; 

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    
    void* modifiedArray = addToArray((void*)myArray, size, 10);

    
    int* resultArray = (int*)modifiedArray;

    cout << "Modified Array: ";
    for (int i = 0; i < size; i++) {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    return 0;
}
