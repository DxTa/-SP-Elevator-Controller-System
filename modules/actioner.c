#include "actioner.h"

Fnode* list[2];
int elevator[2] = {0,0};
int eleWeight[2] = {0,0};
float eleDoor[2] = {0,0};

void addWeight(int cur,int more) {
	if(more < 0 && eleWeight[cur-1] <= 0 )
		return;
	eleWeight[cur-1] += more;
	printf("---Weight: %d\n",eleWeight[cur-1]);
}

int comparePosition(int cur,int des) {
	if(cur > des)
		return -1;
	else if (cur < des)
		return 1;
	else
		return 0;
}

Respond* working() {
	if(list[0]) {
		Action *action = list[0]->val;
		switch(action->actionType) {
			case ACT_CUP:
				printf("CUP");
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						goDown(&elevator[0]);
						printf("-aa--dang xuong %d---\n",elevator[0]);
						break;
					case 1:
						goUp(&elevator[0]);
						printf("-aa--dang len %d---\n",elevator[0]);
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
					case -1 :
						goDown(&elevator[0]);
						printf("---dang xuong %d---\n",elevator[0]);
						break;
					case 1:
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
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						goDown(&elevator[0]);
						printf("---dang xuong %d---\n",elevator[0]);
						break;
					case 1:
						goUp(&elevator[0]);
						printf("---dang len %d---\n",elevator[0]);
						break;
					case 0:
						dequeueAction(&list[0],ACT_FLOOR,action->key);
						if (directOfElevator(list[0],elevator[0]) >= 1)
							dequeueAction(&list[0],ACT_CUP,action->key);
						if (directOfElevator(list[0],elevator[0]) <= 1)
							dequeueAction(&list[0],ACT_CDOWN,action->key);
						printf("---den tang %d---\n",extractInt(action->key));
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_DOPEN:
				switch(isDOpen(&eleDoor[0])) {
					case 0:
						//check j thi o day
						dequeueAction(&list[0],ACT_DOPEN,NULL);
						printf("dong nay \n");
						return makeDCloseRespond(action->key);
					case 1:
						printf("dang cho\n");
						break;
					case 2:
						openD(&eleDoor[0]);
						printf("dang mo %.2f \%....\n",eleDoor[0]);
						break;
				}
				break;
			case ACT_DCLOSE:
				switch(isDClose(&eleDoor[0])) {
					case 0:
						//check j thi o day
						dequeueAction(&list[0],ACT_DCLOSE,NULL);
						printf("---------%d\n",eleWeight[0]);
						printf("dong duoc roi\n");
						break;
					case 1:
						closeD(&eleDoor[0]);
						printf("dang dong %.2f \%....\n",eleDoor[0]);
						break;
				}
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
			// can phai check xem thang may co o tang` nao hay khong
			// neu khong thi deo cho mo? cua?
			/* printf("LIST BEFORE ENQUEUE %d\n",count(list[0])); */
			dequeueAction(&list[0],ACT_DCLOSE,NULL);
			enqueueAction(&list[0],action,elevator[0]);
			/* printf("LIST AFTER ENQUEUE %d\n",count(list[0])); */
			//return makeDOPENDoneRespond();
			break;
		case ACT_DCLOSE:
			// giong ACT_DOPEN
			// action dong cua
			dequeueAction(&list[0],ACT_DOPEN,NULL);
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
