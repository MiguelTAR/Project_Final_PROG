#include <stdio.h>
#include <string.h>
#include "Task_Manager.h"


static void read_line(char* buffer, size_t size) {
	if (fgets(buffer, (int)size, stdin) != NULL) {
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}
	}

}

int main(void) 
{
	Task tasks[max_tasks];
	int task_count = 0;
	int next_id = 1;
	int running = 1;

	while (running) {
		int choice;

		printf("\n--- Task Manager ---\n");
		printf("1. Make a New Task\n");
		printf("2. Delete Tasks by Priority\n");
		printf("3. Display Incomplete Tasks\n");
		printf("4. Display All Tasks\n");
		printf("5. Search/Filter\n ");
		printf("6. Mark tasks as completed\n ");
		printf("7. Continue or Exit? \n ");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		while (getchar() != '\n');
		if (choice == 1) {
			char description[150];
			int priority_int;

			printf("Enter Task Description: ");
			read_line(description, sizeof(description));
			printf("Enter Task Priority (1-5): ");
			scanf("%d", &priority_int);
			while (getchar() != '\n');

			Task t = create_task(next_id, description, (Priority)priority_int);
			next_id++;

		}
	}
}


