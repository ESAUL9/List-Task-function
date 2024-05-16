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