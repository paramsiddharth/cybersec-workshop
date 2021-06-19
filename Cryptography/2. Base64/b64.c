#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void encode(FILE*);
void decode(FILE*);
void showusage();

int main(argc, argv)
int argc; char* argv[];
{
	int i = 1;
	void (*fn)(FILE*) = encode;

	if (argc == 2) {
		const char* help[3] = {
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

	if (argc > 1 && strcmp(argv[1], "-d") == 0) {
		i++;
		fn = decode;
	}
	
	if (i < argc) {
		for (; i < argc; i++) {
			FILE* file = fopen(argv[i], "rb");
			if (file == NULL) {
				fprintf(stderr, "Unable to open file: %s\n", argv[i]);
			} else {
				fn(file);
				fclose(file);
			}
		}
	} else {
		fn(stdin);
	}

	return EXIT_SUCCESS;
}

void showusage(char* cmd) {
	printf("Base64\n");
	printf("Usage: %s [-d] [files...]\n", cmd);
	printf("-d\tDecode\n");
	printf("Made with ❤ by Param.\n");
}