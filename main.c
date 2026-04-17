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


