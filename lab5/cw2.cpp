#include <iostream>
#include <vector>
using namespace std;
class Car {
	string name;
	int id;
public:
	Car(string name, int id) :name(name), id(id) {};
	string getcar() {
		return name;
	}
	int getid() {
		return id;
	}
};
class Garage {
	vector <Car*> cars;
public:
	void parkCar(Car* car) {
		cars.push_back(car);
	}
	void listCar() {
		for (Car* car : cars) { 
			cout << "Car: " << car->getcar() << endl << "ID: " << car->getid() << endl;
		}
	}
};
int main() {
	Garage garage;
	Car obj("Cultus", 333);
	Car obj2("Corolla", 867);
	garage.parkCar(&obj);
	garage.parkCar(&obj2);
	garage.listCar();
}
