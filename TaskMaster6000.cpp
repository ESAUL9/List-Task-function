#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

using namespace std;

const int MAX_TASKS = 4;
//Priority Struct, storing due date and stars. 
struct TaskPrior {
    string dueDate;
    string taskPriority;
};
//this is my class task. its storing variables
class Task {
public:
    string taskID;
    string taskDesc;
    TaskPrior details;

    Task() {}
    Task(string id, string desc, string dueDate, string priority) : taskID(id), taskDesc(desc), details({ dueDate, priority }) {}
};

void viewAllTasks(const Task tasks[], int size) {
    cout << "-----------------------------------------------------------------------------------------------------------------------\n"
        << "                                             Task Management system\n"
        << "\n    ID                         Description                               Due Date                          Priority     \n"
        << "-------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << setw(15) << left << tasks[i].taskID << ". " << setw(45) << left << tasks[i].taskDesc << setw(25) << left << tasks[i].details.dueDate << setw(20) << left << tasks[i].details.taskPriority << endl;
    }
}

void searchTask(const Task tasks[], int size, const string& keyword) {
    bool found = false;
    cout << "Search Results:" << endl;
    for (int i = 0; i < size; ++i) {
        if (tasks[i].taskDesc.find(keyword) != string::npos) {
            cout << setw(15) << left << tasks[i].taskID << ". " << setw(45) << left << tasks[i].taskDesc << setw(25) << left << tasks[i].details.dueDate << setw(20) << left << tasks[i].details.taskPriority << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No tasks found matching the keyword \"" << keyword << "\"." << endl;
    }
}

void addTask(Task tasks[], int& tasksSize, Task chosenTasks[], int& chosenSize) {
    if (chosenSize >= MAX_TASKS) {
        cout << "You have reached the maximum number of tasks allowed in your agenda." << endl;
        return;
    }

    string taskID;
    cout << "Enter the ID of the task you want to add: ";
    cin >> taskID;

    bool found = false;
    for (int i = 0; i < tasksSize; ++i) {
        if (tasks[i].taskID == taskID) {
            // Check for low priority task
            if (tasks[i].details.taskPriority <"***") {
                char choice;
                cout << "This task has low priority. Are you sure you want to add it? (y/n): ";
                cin >> choice;
                if (choice != 'y' && choice != 'Y') {
                    cout << "Task not added. User declined to add low priority task." << endl;
                    return;
                }
            }

            chosenTasks[chosenSize++] = tasks[i]; // Add the found task to the chosen tasks list
            cout << "Task added successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Task with ID \"" << taskID << "\" not found." << endl;
    }
}

void deleteTask(Task chosenTasks[], int& chosenSize, const string& taskID) {
    for (int i = 0; i < chosenSize; ++i) {
        if (chosenTasks[i].taskID == taskID) {
            for (int j = i; j < chosenSize - 1; ++j) {
                chosenTasks[j] = chosenTasks[j + 1];
            }
            chosenSize--;
            cout << "Task with ID \"" << taskID << "\" deleted successfully." << endl;
            return;
        }
    }
    cout << "Task with ID \"" << taskID << "\" not found." << endl;
}

void listTasks(const Task chosenTasks[], int size) {
    cout << "Listing chosen tasks:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << chosenTasks[i].taskID << ". " << chosenTasks[i].taskDesc << endl;
    }
}
//This is the recursive function. It's iterating through the many numbers that the user can press. 
void userChoiceRecursive(Task tasks[], int tasksSize, Task chosenTasks[], int chosenSize) {
    int userChoice;

    cout << "\nThese are the current tasks on the agenda. \n"
        << "\nPress 1: to add a task to your agenda\n"
        << "Press 2: to delete a task from your agenda\n"
        << "Press 3: to list the current tasks you have chosen\n"
        << "Press 4: to search for a task\n"
        << "Press 5: to view all tasks\n"
        << "Press 6: to exit\n"
        << "Your choice: ";
    cin >> userChoice;

    try {
        if (userChoice > 6 || userChoice < 1) {
            throw runtime_error("Invalid choice. Please pick a number 1-6.\n");
        }
        else if (userChoice == 6) {
            cout << "Exiting program." << endl;
            return;
        }
        else if (userChoice == 5) {
            viewAllTasks(tasks, tasksSize);
            userChoiceRecursive(tasks, tasksSize, chosenTasks, chosenSize);
        }
        else if (userChoice == 4) {
            cout << "\nEnter a keyword to search for a task: ";
            string keyword;
            cin.ignore();
            getline(cin, keyword);
            searchTask(tasks, tasksSize, keyword);
            userChoiceRecursive(tasks, tasksSize, chosenTasks, chosenSize);
        }
        else if (userChoice == 1) {
            addTask(tasks, tasksSize, chosenTasks, chosenSize);
            userChoiceRecursive(tasks, tasksSize, chosenTasks, chosenSize);
        }
        else if (userChoice == 2) {
            cout << "Enter the ID of the task you want to delete: ";
            string taskID;
            cin >> taskID;
            deleteTask(chosenTasks, chosenSize, taskID);
            userChoiceRecursive(tasks, tasksSize, chosenTasks, chosenSize);
        }
        else if (userChoice == 3) {
            listTasks(chosenTasks, chosenSize);
            userChoiceRecursive(tasks, tasksSize, chosenTasks, chosenSize);
        }
    }
    catch (runtime_error& excpt) {
        cout << excpt.what();
        cin.clear(); // Clear any error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any additional characters entered
        userChoiceRecursive(tasks, tasksSize, chosenTasks, chosenSize);
    }
}

int main() {
    cout << "--------------------------------------------------------------------------------------------------\n"
        << "Hello! Welcome to my program.\n"
        << "This program is a comprehensive task management system.\n"
        << "The advanced features added will be prioritization, categorization, and deadline management.\n"
        << "\nPlease press enter to continue\n"
        << "--------------------------------------------------------------------------------------------------";
    cin.get(); // Wait for user to press enter
    system("cls"); // Clear the screen

    // All tasks available
    Task allTasks[10] = {
        Task("A", "Go grocery shopping",    "Friday, April 19th, 2024", "**"),
        Task("B", "Renew driver's license", "Tuesday, April 16th, 2024", "****"),
        Task("C", "Drs. visit",             "Monday, April 15th, 2024", "****"),
        Task("D", "Pay rent",               "Friday, April 27th, 2024", "****"),
        Task("E", "Take garbage outside",   "Wednesday, April 17th, 2024", "*****"),
        Task("F", "Clean house",            "Saturday, April 20th, 2024", "***"),
        Task("G", "Take algebra test",      "Thursday, April 18th, 2024", "****"),
        Task("H", "Therapist visit",        "Friday, April 19th, 2024", "*"),
        Task("I", "Take psychology final",  "Monday, May 14th, 2024", "***"),
        Task("K", "Play video games",       "Friday, April 19th, 2024", "*")
    };

    int allTasksSize = 10;

    // This is just for the chosen tasks!
    Task chosenTasks[MAX_TASKS];
    int chosenTasksSize = 0;

    // uses the userChoiceRecusive
    userChoiceRecursive(allTasks, allTasksSize, chosenTasks, chosenTasksSize);

    return 0;
}
