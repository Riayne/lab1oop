#include<iostream>
using namespace std;
//Write a program that finds the second highest number in a float type array of 20 elements using pointer.

int main(){
	
	float arr[20];
    
    
    float* ptr = arr;

    
    cout << "Enter 20 float numbers:" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> *(ptr + i);
    }
    
     for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19 - i; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                float temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    
    cout << "the second hihest number is "<< *(ptr +18)<<endl;
	
}
