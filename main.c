#include <stdio.h>
#include <string.h>
#include "Task_Manager.h"


static void read(char* buffer, size_t size) {
	if (fgets(buffer, (int)size, stdin) != NULL) {
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}
	}

}


void create_interact_task(Task task[], int* task_count, int* next_id)
{
	char description[200];
	int priority_int;

	printf("Please Enter Task Description: ");
	read(description, sizeof(description));


	printf("Please Enter Priority (1 = Highest, 5 = Lowest): ");
	scanf("%d", &priority_int);
	while (getchar() != '/n');

	if (priority_int < 1 || priority_int > 5) {
		printf("Invalid Priority.\n");
		return;
	}
	Task t = create_task(*next_id, description, (Priority)priority_int);
	
	if (add_task(task, task_count, t) == 0) {
		printf("Task created with ID %d.\n", *next_id);
		(*next_id)++;
	}
	else {
		printf("Task List full.\n");
	}

}

void delete_interact_task(Task task[], int* task_count) {

	int priority_int;

	printf("enter priority (1-5) of tasks to delete: ");
	scanf("%d", &priority_int);
	while (getchar() != '\n');

	if (priority_int < 1 || priority_int > 5) {
		printf("Invalid Priority.\n");
		return;
	}

	int deleted = delete_task(task, task_count, (Priority)priority_int);
	printf("Deleted %d tasks with priority %d.\n", deleted, priority_int);
}



   int main(void) {
	Task tasks[max_tasks];
	int task_count = 0;
	int next_id = 1;

	int running = 1;

	while (running) {
		int choice;
		printf("\n--------------Task Menu-----------------");
		printf("1. Create a new task\n");
		printf("2. Delete tasks by priority\n");
		printf("3. Show incomplete tasks\n");
		printf("4. Show all tasks\n");
		printf("5. Continue / Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice) {
		case 1:
			create_interact_task(tasks, &task_count, &next_id);
			break;

		case 2:
			delete_interact_task(tasks, &task_count);
			break;

		case 3:
			display_incomplete_tasks(tasks, task_count);
			break;

		case 4:
			display_all_tasks(tasks, task_count);
			break;

		case 5:
			running = continue_or_exit();
			break;

		default:
			printf("Invalid choice. Please try again.\n");
			break;

		}

	}

	printf("Exiting Section 1......\n");
	return 0;
}

