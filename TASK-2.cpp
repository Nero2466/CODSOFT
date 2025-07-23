#include <iostream>

int main() {
    double firstNumber, secondNumber, result;
    char operationSymbol, continueCalc;

    std::cout << "Hello! This is a simple calculator.\n";

    do {
        while (true) {
            std::cout << "Please enter the first number: ";
            std::cin >> firstNumber;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                break;
            }
        }

        while (true) {
            std::cout << "Enter operation (+, -, *, /): ";
            std::cin >> operationSymbol;

            if (std::cin.fail() || (operationSymbol != '+' && operationSymbol != '-' && operationSymbol != '*' && operationSymbol != '/')) {
                std::cout << "Invalid operation. Try again.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else if (std::cin.peek() != '\n') {
                std::cout << "Only one character allowed.\n";
                std::cin.ignore(10000, '\n');
            } else {
                break;
            }
        }

        while (true) {
            std::cout << "Enter the second number: ";
            std::cin >> secondNumber;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else if (operationSymbol == '/' && secondNumber == 0) {
                std::cout << "Cannot divide by zero. Try again.\n";
            } else {
                break;
            }
        }

        switch (operationSymbol) {
            case '+': result = firstNumber + secondNumber; break;
            case '-': result = firstNumber - secondNumber; break;
            case '*': result = firstNumber * secondNumber; break;
            case '/': result = firstNumber / secondNumber; break;
        }

        std::cout << "Result: " << firstNumber << " " << operationSymbol << " " << secondNumber << " = " << result << "\n";

        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> continueCalc;
        std::cin.ignore(10000, '\n');

    } while (continueCalc == 'y' || continueCalc == 'Y');

    return 0;
}
