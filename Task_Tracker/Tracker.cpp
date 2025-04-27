#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define SIZE 100

struct Task {
    char description[SIZE];
    int done;  // 0 = not done, 1 = done
};

int main() {
    struct Task tasks[MAX_TASKS];
    int task_count = 0;
    int choice;

    while (1) {
        printf("\n--- Task Tracker ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Done\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        if (choice == 1) {
            if (task_count >= MAX_TASKS) {
                printf("Task limit reached.\n");
                continue;
            }
            printf("Enter new task: ");
            fgets(tasks[task_count].description, SIZE, stdin);
            tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = 0;  // remove newline
            tasks[task_count].done = 0;
            task_count++;
            printf("Task added!\n");
        }
        else if (choice == 2) {
            if (task_count == 0) {
                printf("No tasks yet.\n");
            } else {
                for (int i = 0; i < task_count; i++) {
                    printf("%d. [%c] %s\n", i+1, tasks[i].done ? '✔' : '✗', tasks[i].description);
                }
            }
        }
        else if (choice == 3) {
            if (task_count == 0) {
                printf("No tasks to mark.\n");
            } else {
                int num;
                printf("Enter task number to mark as done: ");
                scanf("%d", &num);
                if (num >= 1 && num <= task_count) {
                    tasks[num-1].done = 1;
                    printf("Task marked as done!\n");
                } else {
                    printf("Invalid task number.\n");
                }
            }
        }
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

//
// DIdn't did on own , Use AI to generate most of the code and then added some of my own code to make it work