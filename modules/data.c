#include "data.h"

char* curMessage;

int* makeInt(int value) {
	int *in = (int*)malloc(sizeof(int));
	*in = value;
	return in;
}
