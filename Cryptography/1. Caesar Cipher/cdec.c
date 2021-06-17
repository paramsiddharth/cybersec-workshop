#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define MAX_LEN 10000
#define ALEPH_LEN 26

void showusage(char*);
void parsenum(char*, long**);
void decode(FILE*, long);

int main(int argc, char* argv[]) {
	long* order;
	int i = 1;

	if (argc == 2) {
		char* help[3] = {
			"-?",
			"-h",
			"--help"
		};
		for (int j = 0; j < 3; j++) {
			if (strcmp(argv[1], help[j]) == 0) {
				showusage(argv[0]);
				return EXIT_SUCCESS;
			}
		}
	}

	if (argc > 1) {
		parsenum(argv[i], &order);
		if (order == NULL) {
			order = malloc(sizeof(int));
			*order = 13;
		}
		else
			i++;
	} else {
		order = malloc(sizeof(int));
		*order = 13;
	}

	if (i < argc) {
		for (; i < argc; i++) {
			FILE* file = fopen(argv[i], "r");
			if (file != NULL) {
				decode(file, *order);
				fclose(file);
			} else
				fprintf(stderr, "Failed to open file: %s\n", argv[i]);
		}
	} else {
		decode(stdin, *order);
	}

	if (order != NULL)
		free(order);
	return EXIT_SUCCESS;
}

void showusage(char* cmd) {
	printf("Caesar Cipher\n");
	printf("Usage: %s <order> [files...]\n", cmd);
	printf("Made with ❤ by Param.\n");
}

void parsenum(char* string, long** order) {
	char* endptr;
	errno = 0;
	long num = strtol(string, &endptr, 10);
	if (endptr == string || errno == ERANGE && (num == LONG_MAX || num == LONG_MIN))
		*order = NULL;
	else {
		*order = malloc(sizeof(long));
		**order = num;
	}
}

void decode(FILE* f, long order) {
	while (order < 0)
		order += ALEPH_LEN;
	order %= ALEPH_LEN;

	char line[MAX_LEN];
	while (fgets(line, MAX_LEN, f)) {
		for (int i = 0; i < strlen(line); i++) {
			char ch = line[i];
			if ('a' <= ch && ch <= 'z')
				ch = (ch - 'a' + order) % 26 + 'a';
			else if ('A' <= ch && ch <= 'Z')
				ch = (ch - 'A' + order) % 26 + 'A';
			
			printf("%c", ch);
		}
	}
}