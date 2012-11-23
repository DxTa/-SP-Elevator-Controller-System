#include "actioner.h"

int elevator[2] = {0,0};
Fnode* list[2];

Respond* makeArrivalRespond(void *key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RESP_ARRIVAL;
	return resp;
}

Respond* makeDCloseRespond(void *key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RES_CLOSE_DOOR;
	return resp;
}

int comparePosition(int cur,int des) {
	if(cur > des)
		return 1;
	else if (cur < des)
		return -1;
	else
		return 0;
}

void makeTimeout(int duration) {
	int i=0;
	for (i=0; i<duration; i++)
		if (i%100 == 0)
			printf(".\n");
	return 0;
}


Respond* working() {
	if(list[0]) {
		Action *action = list[0]->val;
		switch(action->actionType) {
			case ACT_CUP:
				printf("CUP");
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case 1 :
						goDown(&elevator[0]);
						printf("---dang xuong %d---\n",elevator[0]);
						break;
					case -1:
						goUp(&elevator[0]);
						printf("---dang len %d---\n",elevator[0]);
						break;
					case 0:
						dequeueAction(&list[0],ACT_CUP,action->key);
						dequeueAction(&list[0],ACT_FLOOR,action->key);
						printf("---den tang %d---\n",extractInt(action->key));
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_CDOWN:
				printf("CDOWN");
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case 1 :
						goDown(&elevator[0]);
						printf("---dang xuong %d---\n",elevator[0]);
						break;
					case -1:
						goUp(&elevator[0]);
						printf("---dang len %d---\n",elevator[0]);
						break;
					case 0:
						dequeueAction(&list[0],ACT_CDOWN,action->key);
						dequeueAction(&list[0],ACT_FLOOR,action->key);
						printf("---den tang %d---\n",extractInt(action->key));
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_FLOOR:
				printf("---dang ... ----\n");
				break;
			case ACT_DOPEN:
				printf("\n---mo cua %d----\n",elevator[0]);
				dequeueAction(&list[0],ACT_DOPEN,NULL);
				makeTimeout(1000);
				return makeDCloseRespond(action->key);
				break;
			case ACT_DCLOSE:
				printf("\n---dong cua %d----\n",elevator[0]);
				dequeueAction(&list[0],ACT_DCLOSE,NULL);
				break;
		}
	}
	return NULL;
}

Respond* executeAction(Action* action) {
	if(action == NULL)
		return working();
	switch(action->actionType) {
		case ACT_CUP:
		case ACT_CDOWN:
		case ACT_FLOOR:
			printf("LIST BEFORE ENQUEUE %d\n",count(list[0]));
			enqueueAction(&list[0],action,elevator[0]);
			printf("LIST AFTER ENQUEUE %d\n",count(list[0]));
			break;
		case ACT_DOPEN:
			printf("---add action mo cua %d-----(moi toi chua dc xu ly)\n", elevator[0]);
			/* printf("LIST BEFORE ENQUEUE %d\n",count(list[0])); */
			enqueueAction(&list[0],action,elevator[0]);
			/* printf("LIST AFTER ENQUEUE %d\n",count(list[0])); */
			//return makeDOPENDoneRespond();
			break;
		case ACT_DCLOSE:
			// action dong cua
			enqueueAction(&list[0],action,elevator[0]);
			// if co loi, return makeDoorCannotCloseRespond()
			//return makeDCLOSEDoneRespond();
			break;
		case ACT_ALARM:
			break;
		case ACT_BREAK:
			break;
		case ACT_LDIRECTION:
			break;
		case ACT_LFLOOR:
			break;
		case ACT_LMESSAGE:
			break;
		default:
			break;
	}
	return working();
}
