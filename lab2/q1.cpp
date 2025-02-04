#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc,char*argv){
	
	int n =argc-1;
	int arr[n];
	int* ptr;
	
	for(int i=0;i<n;i++){
		arr[i]=atoi(argv[i+1]);
		
	}
	
	int sum=0;
	
	for(i=0;i<n;i++){
		arr[i] = std::atoi(argv[i + 1]); // Convert string to integer
    }

    // Pointer to the first element of the array
    int* ptr = arr;

    // Calculate the sum using pointer arithmetic
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(ptr + i); // Access each element via pointer arithmetic
    }

    // Output the sum
    std::cout << "The sum of the elements is: " << sum << std::endl;

    return 0;
}

