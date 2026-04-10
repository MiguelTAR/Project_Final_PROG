//Section 1
#include "Task_Manager.h"

Task create_task(int id, const char* description, Priority priority) {

	Task t;
	t.id = id;
	t.priority = priority;
	t.status = status_not_started;

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