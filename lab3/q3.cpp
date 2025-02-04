#include <iostream>
using namespace std;

class Glass{
    public:
    	int liquidLevel;
    	int drink(int millimeter){
    		liquidLevel -= millimeter;
    		if (liquidLevel <100){
    			cout<<"liquidLevel below 100"<<endl;
    			refill();
    			cout << "The glass has been refilled to 200 ml." << endl;
			}
		}
    	int refill(){
    		liquidLevel = 200;
		}
        
};

int main(){
	Glass obj;
	obj.liquidLevel = 200;

    while (true) {
        cout << "Current Liquid Level: " << obj.liquidLevel << " ml" << endl;
        cout << "Enter the amount of liquid you want to drink (or 0 to exit): ";
        int drinkAmount;
        cin >> drinkAmount;

        if (drinkAmount == 0) {
            cout << "Program terminated." << endl;
            break;
        }

        obj.drink(drinkAmount); 
    }

    return 0;
}
