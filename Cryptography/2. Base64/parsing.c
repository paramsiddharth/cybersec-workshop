#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

char table(uint8_t);
int revtable(uint8_t);

void encode(FILE* f) {
	fseek(f, 0L, SEEK_SET);
	int byte = 0;
	int savedbits[6] = {0};
	int lastpos = 0;
	while ((byte = fgetc(f)) != EOF) {
		int bits[8];
		for (int k = 0; k < 8; k++) {
			bits[k] = (byte >> (8 - k - 1)) & 1;
		}

		int i = 0;
		while (lastpos < 6) {
			savedbits[lastpos++] = bits[i++];
		}

		int sixbitval = 0;
		for (int k = 0; k < 6; k++) {
			sixbitval = (sixbitval << 1) + savedbits[k];
		}
		printf("%c", table(sixbitval));

		lastpos = 0;
		while (i < 8) {
			savedbits[lastpos++] = bits[i++];
		}

		if (lastpos == 6) {
			lastpos = 0;
			int sixbitval = 0;
			for (int k = 0; k < 6; k++) {
				sixbitval = (sixbitval << 1) + savedbits[k];
			}
			printf("%c", table(sixbitval));
		}
	}
	
	if (lastpos > 0) {
		int i = lastpos;
		while (i < 6) {
			savedbits[i++] = 0;
		}

		int sixbitval = 0;
		for (int k = 0; k < 6; k++) {
			sixbitval = (sixbitval << 1) + savedbits[k];
		}
		printf("%c", table(sixbitval));

		int emptybits = 6 - lastpos;
		while (emptybits % 8 != 0) {
			printf("=");
			emptybits += 6;
		}
	}

	printf("\n");
}

void decode(FILE* f) {
	fseek(f, 0L, SEEK_SET);
	int byte = 0;
	int savedbits[8] = {0};
	int lastpos = 0;
	while ((byte = fgetc(f)) != EOF) {
		if (byte == '=')
			continue;

		int bits[6];
		int num = revtable(byte);
		for (int k = 0; k < 6; k++) {
			bits[k] = (num >> (6 - k - 1)) & 1;
		}

		int i = 0;
		while (i < 6 && lastpos < 8) {
			savedbits[lastpos++] = bits[i++];
		}

		if (lastpos == 8) {
			int eightbitval = 0;
			for (int k = 0; k < 8; k++) {
				eightbitval = (eightbitval << 1) + savedbits[k];
			}
			printf("%c", eightbitval);

			lastpos = 0;
		}

		while (i < 6) {
			savedbits[lastpos++] = bits[i++];
		}
	}
	printf("\n");
}