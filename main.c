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
