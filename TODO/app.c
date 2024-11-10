#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char description[100];
    int priority;
};

void addTask(struct Task *tasks, int *taskCount, const char *description, int priority) {
    if (*taskCount >= 10) {
        printf("To-do list is full. Cannot add more tasks.\n");
        return;
    }

    int i;
    for (i = 0; i < *taskCount; ++i) {
        if (tasks[i].priority == priority) {
            printf("Priority %d is reserved. Please enter a different priority.\n", priority);
            return;
        }
    }

    // Add 
    strcpy(tasks[*taskCount].description, description);
    tasks[*taskCount].priority = priority;

    // Increment the task count
    (*taskCount)++;

    printf("Task added successfully!\n");
}

// Function to display all tasks
void displayTasks(const struct Task *tasks, int taskCount) {
    if (taskCount == 0) {
        printf("No tasks in the to-do list.\n");
    } else {
        printf("To-Do List:\n");
        for (int i = 0; i < taskCount; ++i) {
            printf("%d. Priority %d: %s\n", i + 1, tasks[i].priority, tasks[i].description);
        }
    }
}

int main() {
    struct Task tasks[10]; 
    int taskCount = 0;

    int choice;
    char description[100];
    int priority;

    do {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description); // Fix to read the whole line
                // scanf("%s", description);
                printf("Enter priority (1-5): ");
                scanf("%d", &priority);

                addTask(tasks, &taskCount, description, priority);
                break;

            case 2:
                displayTasks(tasks, taskCount);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

