#include "requestor.h"

Action* makeCUPAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_CUP;
	act->key = (int*)key;
	printf("Requestor : ACT_CUP %d\n",*((int*)key));
	return act;
}

Action* makeCDOWNAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_CDOWN;
	act->key = (int*)key;
	printf("Requestor : ACT_CDOWN %d\n",*((int*)key));
	return act;
}

Action* makeFLOORAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_FLOOR;
	act->key = key;
	printf("Requestor : ACT_FLOOR %d\n",*((int*)key));
	return act;
}

Action* makeDOPENAction(void* key) {
	Action* act = (Action*)malloc(sizeof(Action));
	act->actionType = ACT_DOPEN;
	act->key = key;
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

Action* executeRequest(Request* request) {
	if(request == NULL)
		return NULL;
	switch(request->requestType) {
		case REQ_CUP:
			return makeCUPAction(request->key);
		case REQ_CDOWN:
			return makeCDOWNAction(request->key);
		case REQ_FLOOR:
			return makeFLOORAction(request->key);
		case REQ_DOPEN:
			return makeDOPENAction(request->key);
		case REQ_DCLOSE:
			return makeDCLOSEAction(request->key);
		case REQ_ALARM:
			return makeALARMAction(request->key);
	}
	return NULL;
}

