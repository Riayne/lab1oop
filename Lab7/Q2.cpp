#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Base class: Shape
class Shape {
protected:
    int x, y;       // Position
    string color;
    double borderThickness;

public:
    Shape(int x, int y, string color, double borderThickness = 1.0)
        : x(x), y(y), color(color), borderThickness(borderThickness) {}

    virtual void draw() const = 0;  // Pure virtual function
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual void getInfo() const {
        cout << "Shape Info:\n";
        cout << "Position: (" << x << ", " << y << ")\n";
        cout << "Color: " << color << "\n";
        cout << "Border Thickness: " << borderThickness << "\n";
    }

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(int x, int y, string color, double radius, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), radius(radius) {}

    void draw() const override {
        cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << " and color " << color << ".\n";
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }

    void getInfo() const override {
        Shape::getInfo();
        cout << "Radius: " << radius << "\n";
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(int x, int y, string color, double width, double height, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), width(width), height(height) {}

    void draw() const override {
        cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << ", height " << height << " and color " << color << ".\n";
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }

    void getInfo() const override {
        Shape::getInfo();
        cout << "Width: " << width << ", Height: " << height << "\n";
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(int x, int y, string color, double a, double b, double c, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), sideA(a), sideB(b), sideC(c) {}

    void draw() const override {
        cout << "Drawing Triangle at (" << x << ", " << y << ") with sides " << sideA << ", " << sideB << ", " << sideC << " and color " << color << ".\n";
    }

    double calculateArea() const override {
        double s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double calculatePerimeter() const override {
        return sideA + sideB + sideC;
    }

    void getInfo() const override {
        Shape::getInfo();
        cout << "Sides: " << sideA << ", " << sideB << ", " << sideC << "\n";
    }
};

// Derived class: Polygon (Generalized)
class Polygon : public Shape {
private:
    vector<double> sides;

public:
    Polygon(int x, int y, string color, vector<double> sides, double borderThickness = 1.0)
        : Shape(x, y, color, borderThickness), sides(sides) {}

    void draw() const override {
        cout << "Drawing Polygon at (" << x << ", " << y << ") with " << sides.size() << " sides and color " << color << ".\n";
    }

    double calculateArea() const override {
        cout << "Area calculation depends on specific polygon type.\n";
        return 0.0;
    }

    double calculatePerimeter() const override {
        double perimeter = 0;
        for (double side : sides) {
            perimeter += side;
        }
        return perimeter;
    }

    void getInfo() const override {
        Shape::getInfo();
        cout << "Sides: ";
        for (double side : sides) {
            cout << side << " ";
        }
        cout << "\n";
    }
};

// Main function to demonstrate the tool
int main() {
    Circle circle(10, 20, "Red", 5.0);
    Rectangle rectangle(5, 10, "Blue", 15.0, 10.0);
    Triangle triangle(0, 0, "Green", 3.0, 4.0, 5.0);
    Polygon polygon(2, 3, "Yellow", {6.0, 7.0, 8.0, 9.0, 10.0});

    cout << "=== Shape Details ===\n";
    circle.getInfo();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << "\n\n";

    rectangle.getInfo();
    cout << "Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << "\n\n";

    triangle.getInfo();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << "\n\n";

    polygon.getInfo();
    cout << "Perimeter: " << polygon.calculatePerimeter() << "\n\n";

    cout << "=== Drawing Shapes ===\n";
    circle.draw();
    rectangle.draw();
    triangle.draw();
    polygon.draw();

    return 0;
}
