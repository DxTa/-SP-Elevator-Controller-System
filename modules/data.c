#include "data.h"

char* curMessage;
Request *curReq;
Action *curAct;
Respond *curResp;

int* makeInt(int value) {
	int *in = (int*)malloc(sizeof(int));
	*in = value;
	return in;
}

int extractInt(void* val) {
	return *((int*)val);
}
