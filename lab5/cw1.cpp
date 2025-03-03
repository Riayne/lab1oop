#include <iostream>
using namespace std;

class Engine {
	bool isrunning;
public:
	void start() {
		isrunning = true;
		cout << "Engine Started\n";
	}
	void stop() {
		isrunning = false;
		cout << "Engine Stopped\n";
	}
};
class Car {
	Engine eng;
public:
	void startcar() {
		eng.start();
	}
	void stopcar() {
		eng.stop();
	}
};
int main() {
	Car obj;
	obj.startcar();
	obj.stopcar();
}
