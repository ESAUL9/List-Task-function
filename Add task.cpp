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
