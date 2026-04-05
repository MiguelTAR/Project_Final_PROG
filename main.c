#include <stdio.h>
#include <string.h>
#include "Task_Manager.h"


static void read(char* buffer, size_t size) {
	if (fgets(buffer, (int)size, stdin) != NULL) {
		size_t len = strlen(buffer);
	}

}