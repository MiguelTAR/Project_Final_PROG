// Task Manager Header File
#ifndef task_manager_h
#define task_manager_h

#include <stdio.h>
#include <string.h>

#define max_tasks 100

typedef enum {
	priority_1 = 1,
	priority_2,
	priority_3,
	priority_4, 
	priority_5
} Priority;

typedef enum {
	status_not_started = 0,
	status_in_progress,
	status_completed
}Status;

typedef struct {
	int id;
	char description[150];
	Priority priority;
	Status status;
} Task;


//---------Section 1 - Miguel-----------------

Task create_task(int id, const char* description, Priority priority);

int add_task(Task tasks[], int* task_count,Task new_task);

int delete_task(Task tasks[], int* task_count, Priority priority);


//---------Section 2 - Naomi and Rachael-----------------
void display_tasks(const Task tasks[], int task_count);

void search_filter_tasks(Task tasks[], int task_count, 
		int Skip[], Priority priority, Status status);

int mark_task_complete(Task tasks[], int task_count, int id);


//---------Section 3 - April-----------------
void display_incomplete_tasks(Task tasks[], int task_count);

void display_all_tasks(Task tasks[], int task_count);

int continue_or_exit(void);


#endif