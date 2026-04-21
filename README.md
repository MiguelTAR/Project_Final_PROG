# Project

Miguel - Section 1:

Function: create_task – creates a new Task that has the following elements: 

The given ID 

The given description 

The given priority 

Status automatically set to NOT_STARTED 

Parameter 

Type 

Purpose 

id 

string 

Unique  

description 

Constant character     

Text describing what the task is  

priority 

Named integer constants 

Priority level (1-5) 

 

Function: add_task – adds a new task to the array if there is space. 

Parameter 

Type 

Purpose 

tasks[] 

array 

The list where the tasks are stored 

task_count 

string 

Pointer to the number of tasks currently stored 

new_task 

array 

The task to insert into the array 

 

Function: delete_tasks – Deletes all tasks that match the given priority 

Parameter 

Type 

Purpose 

tasks[] 

array 

The list of tasks  

task_count 

string 

Pointer to the number of tasks 

priority 

Constant array 

The priority level to delete (1-5) 



Section 2 (Rachael and Naomi):  

 

Function: display_tasks – displays an updated list of all tasks 

Shows every task currently stored in the system. 

Displays the task ID 

Displays the task description 

Displays the task priority 

Displays the current status (Not_started or Completed) 

 

 

Parameter 

Type 

Purpose 

Tasks[] 

Array 

The list of tasks to display 

 

Task_count 

String 

Pointer to the number of tasks currently stored 

 

 

Function: search_filter_tasks – searches and filters tasks 

Finds tasks based on , priority, or status. 

Allows the user to skip the filter search 

Filters tasks by priority level (1–5) 

Filters tasks by status (NOT_STARTED or COMPLETED) 

Displays only the tasks that match the search or filter 

Parameter 

Type 

Purpose 

tasks[] 

array 

The list where the tasks are stored 

task_count 

string 

Pointer to the number of tasks currently stored 

Skip 

 

Char array 

Stores the word "skip" if the user wants to skip the filter search  

priority 

 

named integer constant 

 

Priority level (1–5) 

 

status 

constant array 

 

Task status (NOT_STARTED / COMPLETED) 

 

 

Function: mark_task_complete – marks a task as completed 

Updates a task’s status using its ID. 

Finds the task with the given ID 

Changes its status to COMPLETED 

Leaves all other task information unchanged 

 

Parameter 

Type 

Purpose 

tasks[] 

array 

The list of tasks  

task_count 

string 

Pointer to the number of tasks 

id 

string 

 

The ID of the task to update 



April - Section 


void display_incomplete_tasks(Task tasks[], int task_count);

void display_all_tasks(Task tasks[], int task_count);

int continue_or_exit(void);

do the following functions



 



 
