#include <iostream>

int main() 
{
    double firstNumber, secondNumber;

    char operationSymbol;

    std::cout << "Hello! This is a simple calculator." << std::endl;

    std::cout << "Please enter the first number: ";

    std::cin >> firstNumber;

    std::cout << "Now, enter the operation you want to perform (+, -, *, /): ";

    std::cin >> operationSymbol;

    std::cout << "And finally, enter the second number: ";

    std::cin >> secondNumber;

    double calculationResult;

    if (operationSymbol == '+')
     {
        calculationResult = firstNumber + secondNumber;

        std::cout << "Result: " << firstNumber << " + " << secondNumber << " = " << calculationResult << std::endl;

    } else if (operationSymbol == '-')
     {
        calculationResult = firstNumber - secondNumber;
        std::cout << "Result: " << firstNumber << " - " << secondNumber << " = " << calculationResult << std::endl;
        
    } 
    else if (operationSymbol == '*') 
    {
        calculationResult = firstNumber * secondNumber;
        std::cout << "Result: " << firstNumber << " * " << secondNumber << " = " << calculationResult << std::endl;
    }
     else if (operationSymbol == '/') 
     {
        if (secondNumber != 0) {
            calculationResult = firstNumber / secondNumber;
            std::cout << "Result: " << firstNumber << " / " << secondNumber << " = " << calculationResult << std::endl;
        } else {
            std::cout << "Error! Cannot divide by zero. Please try again with a different second number." << std::endl;
        }
    } else 
    {
        std::cout << "That's not a valid operation. Please use +, -, *, or /." << std::endl;
    }

    return 0;
}