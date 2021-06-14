#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char cmd[500] = "ls -1";
	
	if (argc > 1) {
		printf("Directory: %s\n", argv[1]);
		strcat(cmd, " ");
		strcat(cmd, argv[1]);
	} else
		printf("Directory: .\n");
	
	system(cmd);

	return EXIT_SUCCESS;
}