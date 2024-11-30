#include <pthread.h>
#include <unistd.h>
#include <iostream>

int main() {
    string x = symbol("x");       // Define symbol x
    Expression f = x * x * x;       // Define function f(x) = x^3

    Expression df = f.diff(x);  // Find derivative f'(x) symbolically

    std::cout << "Derivative of x^3 is: " << df << std::endl;

    return 0;
}

