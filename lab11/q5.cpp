#include <iostream>
#include <vector>
#include <stdexcept>

class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: no elements to pop or view!";
    }
};

template<typename T>
class Stack {
private:
    std::vector<T> container;

public:
    void push(const T& value) {
        container.push_back(value);
    }

    void pop() {
        if (container.empty()) throw StackUnderflowException();
        container.pop_back();
    }

    T top() const {
        if (container.empty()) throw StackUnderflowException();
        return container.back();
    }

    bool empty() const {
        return container.empty();
    }
};

// Demo
void testStack() {
    Stack<int> s;
    try {
        s.pop();  // Throws
    } catch (const StackUnderflowException& e) {
        std::cerr << e.what() << std::endl;
    }
    s.push(10);
    std::cout << "Top: " << s.top() << std::endl;
}
