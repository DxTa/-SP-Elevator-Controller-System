#include "data.h"

int* makeInt(int value) {
	int *in = (int*)malloc(sizeof(int));
	*in = value;
	return in;
}
