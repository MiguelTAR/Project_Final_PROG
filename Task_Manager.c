//Section 1
#include "Task_Manager.h"

Task create_task(int id, const char* description, Priority priority) {

	Task t;
	t.id = id;
	t.priority = priority;
	t.satus = status_not_started;

	strncpy(t.description, description, sizeof(t.description) - 1);
	t.description[sizeof(t.description) - 1] = '\0';

	return t;

}

int add_task(Task task[], int* task_count, Task new_task) {

	if (*task_count >= max_tasks) {
		return -1;
	}
	task[*task_count] = new_task;
	(*task_count)++;
	return 0;
}

int delete_task(Task task[], int* task_count, Priority priority) {

	int write = 0;
	int deleted = 0;

	for (int i = 0; i < *task_count; i++) {
		if (task[i].priority == priority) {
			deleted++;
		}
		else {
			task[write++] = task[i];
		}
	}

	*task_count = write;
	return deleted;

}


// section 3
// show only tasks that are NOT completed
void display_incomplete_tasks(Task tasks[], int task_count) {       
    printf("\n--- Incomplete Tasks ---\n");
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].satus != status_completed) {
            printf("ID: %d | Description: %s | Priority: %d\n",
                tasks[i].id,
                tasks[i].description,
                tasks[i].priority);
        }
    }
}

// show ALL tasks
void display_all_tasks(Task tasks[], int task_count) {             
    printf("\n--- All Tasks ---\n");
    for (int i = 0; i < task_count; i++) {
        printf("ID: %d | Description: %s | Priority: %d | Status: %d\n",
            tasks[i].id,
            tasks[i].description,
            tasks[i].priority,
            tasks[i].satus);
    }
}

// ask the user if they want to continue or exit
// return 1 = continue, 0 = exit
int continue_or_exit() {                                            
    char choice;
    printf("\nWould you like to continue? (yes/no): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        return 1;
    }
    else {
        return 0;
    }
}