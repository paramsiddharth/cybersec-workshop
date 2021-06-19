#include <stdint.h>

char table(uint8_t val) {
	switch ((int)val) {
		case 0 ... 25:
			return 'A' + (int)val;
		case 26 ... 51:
			return 'a' + (int)(val - 26);
		case 52 ... 61:
			return '0' + (int)(val - 52);
		case 62:
			return '+';
		case 63:
			return '/';
		default:
			return '=';
	}
}

int revtable(char sixbitval) {
	switch (sixbitval) {
		case 'A' ... 'Z':
			return (int)sixbitval - 'A';
		case 'a' ... 'z':
			return 26 + (int)(sixbitval) - 'a';
		case '0' ... '9':
			return 52 + (int)(sixbitval) - '0';
		case '+':
			return 62;
		case '/':
			return 63;
		default:
			return -1;
	}
}