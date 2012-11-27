#include "data.h"

char* curMessage;
Request *curReq;
Action *curAct;
Respond *curResp;
int blocker[2] = {0,0};

int* makeInt(int value) {
	int *in = (int*)malloc(sizeof(int));
	*in = value*20;
	return in;
}

int extractInt(void* val) {
	return *((int*)val);
}

void changeBlocker(int cur,int val) {
	blocker[cur-1] = val;
}
