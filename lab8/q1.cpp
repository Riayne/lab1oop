#include <iostream>
#include <algorithm>


using namespace std;

class Fraction{
    private:
    int numerator,denominator;

    int reduce(){
        if(denominator == 0){
            numerator = 0;
            denominator = 1;
            return;
        }
        int gcd_value = __gcd(numerator,denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
        
        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

    }
    public:
    Fraction(int n=0,int d=1) : numerator(n) , denominator(d){}

    Fraction operator+(const Fraction& obj)const{
        return Fraction(numerator*obj.denominator+obj.numerator*denominator,denominator*obj.denominator);
    }
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }
    Fraction operator* (const Fraction&other) const{
        return Fraction(numerator*other.numerator,denominator*other.denominator);
    }
    Fraction operator/ (const Fraction&other) const {
        return Fraction(numerator*other.denominator,denominator*other.numerator);
    }


    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction& other) const {
        return other < *this;
    }
    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }


    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }
};


int main() {
    Fraction f1, f2;

    cout << "Enter first fraction (format: a/b): ";
    cin >> f1;

    cout << "Enter second fraction (format: a/b): ";
    cin >> f2;

    cout << "f1 = " << f1 << ", f2 = " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    cout << boolalpha; 
    cout << "f1 == f2? " << (f1 == f2) << endl;
    cout << "f1 != f2? " << (f1 != f2) << endl;
    cout << "f1 < f2? " << (f1 < f2) << endl;
    cout << "f1 > f2? " << (f1 > f2) << endl;
    cout << "f1 <= f2? " << (f1 <= f2) << endl;
    cout << "f1 >= f2? " << (f1 >= f2) << endl;

    return 0;
}


