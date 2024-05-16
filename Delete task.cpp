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