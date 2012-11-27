#include "actmaker.h"

Action* makeCUPAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_CUP;
	act->key = (int*)key;
	printf("Action : ACT_CUP %d\n",*((int*)key));
	return act;
}

Action* makeCDOWNAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_CDOWN;
	act->key = (int*)key;
	printf("Action : ACT_CDOWN %d\n",*((int*)key));
	return act;
}

Action* makeFLOORAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_FLOOR;
	act->key = key;
	printf("Action : ACT_FLOOR %d\n",*((int*)key));
	return act;
}

Action* makeDOPENAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_DOPEN;
	act->key = key;
	printf("\nAction : ACT_DOPEN %d\n",*((int*)key));
	return act;
}

Action* makeDCLOSEAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_DCLOSE;
	act->key = key;
	return act;
}

Action* makeALARMAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_ALARM;
	act->key = key;
	return act;
}

Action* makeSTOPAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_STOP;
	act->key = key;
	return act;
}

