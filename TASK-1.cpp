#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
    
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = (rand() % 100) + 1;

    int playerGuess = 0;

    int numberOfAttempts = 0;

    
    std::cout << "Welcome to the exciting Number Guessing Game!" << std::endl;
    
    std::cout << "I have thought of a number between 1 and 100." << std::endl;
    
    std::cout << "Can you guess what it is?" << std::endl;

    do {
        
        std::cout << "\nEnter your guess: ";
        
        std::cin >> playerGuess;

        numberOfAttempts++;

        if (playerGuess > secretNumber) {
        
            std::cout << "Oops! Your guess is too high. Try a lower number." << std::endl;
        
        } else if (playerGuess < secretNumber) {
        
            std::cout << "Not quite! Your guess is too low. Aim a little higher." << std::endl;
        
        } else {
        
            std::cout << "\nCongratulations! You guessed the number " << secretNumber << " correctly!" << std::endl;
        
            std::cout << "It took you " << numberOfAttempts << " attempts." << std::endl;
        
        }


    } while (playerGuess != secretNumber);

    
    return 0;
}