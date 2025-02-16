#include <iostream>
#include <cmath>
using namespace std;

class Circle{
    double radius;
    public:
    Circle(double r) : radius(r){}
    
    double getArea(){
        return M_PI*radius*radius;
    }
    
    double getPerimeter(){
        return 2*M_PI*radius;
    }
};

int main()
{
    Circle cir(6.0);
    cout<<"Area: "<< cir.getArea()<<endl;
    cout<<"Perimetre: "<<cir.getPerimeter()<<endl;
    return 0; 
}

   
