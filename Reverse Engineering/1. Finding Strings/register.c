#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool verify(char* key) { return strcmp(key, "W0247-4RXD3-6TW0F-0FD63-64EFD-38180") == 0; }

int main(int argc, char* argv[]) {
	char key[500];

	if (argc > 1) {
		if (strcmp(argv[1], "--unregister") == 0) {
			FILE* status = fopen(".status", "r");
			if (status == NULL) {
				printf("Not registered.\n");
				exit(EXIT_SUCCESS);
			}
			fclose(status);
			if (!remove(".status")) {
				printf("Unregistered successfully!\n");
				exit(EXIT_SUCCESS);
			} else {
				fprintf(stderr, "Failed to unregister!\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	{
		FILE* status = fopen(".status", "r");
		if (status != NULL) {
			fscanf(status, "%s", key);
			fclose(status);
			if (verify(key)) {
				printf("Key found: %s\n", key);
				printf("Already registered.\n");
				exit(EXIT_SUCCESS);
			}
		}
	}

	if (argc < 2) {
		printf("Enter the licence key: ");
		scanf("%[^\n]s", key);
	} else {
		strcpy(key, argv[1]);
	}

	if (verify(key)) {
		printf("Successfully registered!\n");
		FILE* status = fopen(".status", "w");
		fprintf(status, "%s", key);
		fclose(status);
		exit(EXIT_SUCCESS);
	} else {
		fprintf(stderr, "Invalid key!\n");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}