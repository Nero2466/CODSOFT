#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    const int SECRET_NUMBER = (std::rand() % 100) + 1;

    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Ultimate Number Guessing Challenge!\n";
    std::cout << "I've secretly chosen a number between 1 and 100. Can you uncover it?\n";

    do {
        std::cout << "\nWhat's your guess? ";
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cout << "Whoops! That's not a valid number. Please enter a whole number.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        }

        attempts++;

        if (guess > SECRET_NUMBER) {
            std::cout << "Too high! Aim a little lower.\n";
        } else if (guess < SECRET_NUMBER) {
            std::cout << "Too low! Try going higher.\n";
        } else {
            std::cout << "\nBingo! You nailed it! The secret number was " << SECRET_NUMBER << ".\n";
            std::cout << "It only took you " << attempts << " tries. Well done!\n";
        }

    } while (guess != SECRET_NUMBER);

    return 0;
}