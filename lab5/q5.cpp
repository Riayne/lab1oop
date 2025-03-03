#include <iostream>
using namespace std;

class Car {
public:

	int horsepwr = 66;
	int seating_capacity = 1500;
	int no_of_speakers = 849;

	void display() {
    
		cout << "horsepower: " << horsepwr << endl;
		cout << "seating capacity: " << seating_capacity << endl;
		cout << "no of speakers: " << no_of_speakers << endl;
	}

	void const function(int hp, int sc, int ns) {
		horsepwr = hp;
		seating_capacity = sc;
		no_of_speakers = ns;
	}
};
int main() {
	Car obj;
	obj.display();
	obj.function(26, 99, 456);
	obj.display();
}
