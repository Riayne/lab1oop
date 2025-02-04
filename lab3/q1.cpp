#include <iostream>
using namespace std;

class User{
    private:
        string name;
        int age;
        
    public:
        string getname() {  
            return name;
        }
        
        int getage() {  
            return age;
        }
        
        void setname(string n){
            name = n;
        }
        
        void setage(int a){
            age = a;
        }
};

int main(){
    User obj;
    obj.setage(24);
    obj.setname("Teo");


    cout << "Name: " << obj.getname() << endl;
    cout << "Age: " << obj.getage() << endl;

    return 0;
}
