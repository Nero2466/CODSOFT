#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <ios>

void showAppMenu() {
    std::cout << "\n===== YOUR DAILY TASKS =====" << std::endl;
    std::cout << "1. Add a new task" << std::endl;
    std::cout << "2. See all tasks" << std::endl;
    std::cout << "3. Mark a task done" << std::endl;
    std::cout << "4. Delete a task" << std::endl;
    std::cout << "5. Close the app" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "What do you want to do? ";
}

void addNewTask(std::vector<std::string>& taskList, std::vector<bool>& taskStatus) {
    std::string description;
    std::cout << "\nEnter what you need to do: ";
    std::getline(std::cin >> std::ws, description);
    taskList.push_back(description);
    taskStatus.push_back(false);
    std::cout << "Task added!\n";
}

void displayAllTasks(const std::vector<std::string>& taskList, const std::vector<bool>& taskStatus) {
    std::cout << "\n===== YOUR TO-DO LIST =====" << std::endl;
    if (taskList.empty()) {
        std::cout << "You have no tasks right now.\n";
    } else {
        for (size_t i = 0; i < taskList.size(); ++i) {
            std::cout << (i + 1) << ". ";
            std::cout << taskList[i];
            if (taskStatus[i]) {
                std::cout << " [DONE]";
            } else {
                std::cout << " [PENDING]";
            }
            std::cout << std::endl;
        }
    }
    std::cout << "===========================\n";
}

void markTaskComplete(std::vector<bool>& taskStatus, int chosenTaskNum) {
    int actualIndex = chosenTaskNum - 1;

    if (actualIndex >= 0 && actualIndex < taskStatus.size()) {
        taskStatus[actualIndex] = true;
        std::cout << "Task number " << chosenTaskNum << " is now DONE!\n";
    } else {
        std::cout << "That task number doesn't exist. Please try again.\n";
    }
}

void deleteTask(std::vector<std::string>& taskList, std::vector<bool>& taskStatus, int chosenTaskNum) {
    int actualIndex = chosenTaskNum - 1;

    if (actualIndex >= 0 && actualIndex < taskList.size()) {
        taskList.erase(taskList.begin() + actualIndex);
        taskStatus.erase(taskStatus.begin() + actualIndex);
        std::cout << "Task number " << chosenTaskNum << " has been deleted!\n";
    } else {
        std::cout << "That task number doesn't exist. Please try again.\n";
    }
}

int main() {
    std::vector<std::string> myTasks;
    std::vector<bool> myTaskStatuses;

    int menuOption;
    int selectedTaskNumber;

    do {
        showAppMenu();
        std::cin >> menuOption;

        if (std::cin.fail()) {
            std::cout << "\nInvalid input! Please enter a number from the menu.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (menuOption) {
            case 1:
                addNewTask(myTasks, myTaskStatuses);
                break;
            case 2:
                displayAllTasks(myTasks, myTaskStatuses);
                break;
            case 3:
                if (myTasks.empty()) {
                    std::cout << "\nThere are no tasks to mark yet. Add some first!\n";
                    break;
                }
                displayAllTasks(myTasks, myTaskStatuses);
                std::cout << "Enter the number of the task you finished: ";
                std::cin >> selectedTaskNumber;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid task number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    markTaskComplete(myTaskStatuses, selectedTaskNumber);
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 4:
                if (myTasks.empty()) {
                    std::cout << "\nNothing to delete. Your list is empty.\n";
                    break;
                }
                displayAllTasks(myTasks, myTaskStatuses);
                std::cout << "Enter the number of the task to delete: ";
                std::cin >> selectedTaskNumber;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid task number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    deleteTask(myTasks, myTaskStatuses, selectedTaskNumber);
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 5:
                std::cout << "\nClosing the To-Do List. See you Gaurav!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please pick a number from the menu (1-5).\n";
                break;
        }
    } while (menuOption != 5);

    return 0;
}