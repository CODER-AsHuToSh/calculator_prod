#include <iostream>
#include <stdexcept>

// Function declarations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division by zero");
    }
    return a / b;
}

int main() {
    double num1, num2;
    char op;

    std::cout << "Simple Calculator\n";

    // Input with validation
    std::cout << "Enter first number: ";
    if (!(std::cin >> num1)) {
        std::cerr << "Invalid input for first number.\n";
        return 1;
    }

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    if (!(std::cin >> num2)) {
        std::cerr << "Invalid input for second number.\n";
        return 1;
    }

    try {
        double result;

        switch (op) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            default:
                std::cerr << "Invalid operator.\n";
                return 1;
        }

        std::cout << "Result = " << result << "\n";
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
