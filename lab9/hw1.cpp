#include <iostream>
using namespace std;

// Abstract class Shape
class Shape {
public:
    virtual double getArea() = 0; // Pure virtual function
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    double getArea() override {
        return length * width;
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle rect(5, 3);
    Triangle tri(4, 6);

    cout << "Area of Rectangle: " << rect.getArea() << endl;
    cout << "Area of Triangle: " << tri.getArea() << endl;

    return 0;
}
