#include <iostream>
using namespace std;

class Date{
    private:
        int month;
        int day;
        int year;
        
    public:
    	int displayDate(){
		cout<<"Enter day month and year: ";
		cin>>day>>month>>year;
		cout<<month<<"/"<<day<<"/"<<year;
		}
        
};

int main(){
    Date obj;
    obj.displayDate();

    return 0;
}

