// FinalLuis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

    // Function to list all tasks
void listTasks() {
    // Algorithm listTasks():
    // Check if there are tasks available

    if (taskCount == 0) {

        // print when no tasks are avvailable

        printf("There are no tasks available.\n");
    }
    else {
        // Print "Tasks"

        printf("Tasks:\n");

        // Go through each task

        for (int i = 0; i < taskCount; i++) {
            // print Task and description
            printf("ID: %d, Description: %s\n", taskIDs[i], tasks[i]);
        }
    }
}
// End Algorithm