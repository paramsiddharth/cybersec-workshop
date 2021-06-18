#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void encode(FILE*);

int main(argc, argv)
int argc; char* argv[];
{
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			FILE* file = fopen(argv[i], "rb");
			if (file == NULL) {
				fprintf(stderr, "Unable to open file: %s\n", argv[i]);
			} else {
				encode(file);
				fclose(file);
			}
		}
	} else {
		encode(stdin);
	}

	return EXIT_SUCCESS;
}