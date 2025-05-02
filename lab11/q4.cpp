#include <iostream>

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() const { return a * b; }
};

template<typename T>
class Derived : public Base<T> {
private:
    T c, d;
public:
    Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}

    T multiplyDerived() const { return c * d; }
    void showMultiplications() const {
        std::cout << "Base product: " << this->multiplyBase() << std::endl;
        std::cout << "Derived product: " << multiplyDerived() << std::endl;
    }
};
