void viewAllTasks(const Task tasks[], int size) {
    cout << "-----------------------------------------------------------------------------------------------------------------------\n"
        << "                                             Task Management system\n"
        << "\n    ID                         Description                               Due Date                          Priority     \n"
        << "-------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << setw(15) << left << tasks[i].taskID << ". " << setw(45) << left << tasks[i].taskDesc << setw(25) << left << tasks[i].details.dueDate << setw(20) << left << tasks[i].details.taskPriority << endl;
    }
}