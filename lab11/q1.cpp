#include <iostream>
#include <any>
#include <stdexcept>

class BadTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad type requested from container!";
    }
};

class TypeSafeContainer {
private:
    std::any data;

public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    template<typename T>
    T get() const {
        if (!data.has_value()) throw BadTypeException();
        try {
            return std::any_cast<T>(data);
        } catch (const std::bad_any_cast&) {
            throw BadTypeException();
        }
    }
};
