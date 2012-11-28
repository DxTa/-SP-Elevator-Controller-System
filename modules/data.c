#include "data.h"
#include "informer.h"

char* curMessage = "";
Request *curReq;
Action *curAct;
Respond *curResp;
int maxSpeed = 2;
int maxWeight = 50;
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

void addWeight(int cur,int more) {
	if(more < 0 && eleWeight[cur-1] <= 0 )
		return;
	eleWeight[cur-1] += more;
	printf("---Weight: %d\n",eleWeight[cur-1]);
}
