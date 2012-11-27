#include "actioner.h"

Fnode* list[2];
int elevator[2] = {20,20};
int eleWeight[2] = {0,0};
float eleDoor[2] = {0,0};
int blocker[2] = {0,0};

void addWeight(int cur,int more) {
	if(more < 0 && eleWeight[cur-1] <= 0 )
		return;
	eleWeight[cur-1] += more;
	printf("---Weight: %d\n",eleWeight[cur-1]);
}

void changeBlocker(int cur,int val) {
	blocker[cur-1] = val;
}


int checkWeight(int maxWeight, int weight) {
	if(weight <= maxWeight)
		return 0;
	else
		return 1;
}

int checkDoorOpen(int door) {
	if(door == 1)
		return 0;
	else
		return 1;
}

int checkDoorClose(int door) {
	if(door == 0)
		return 0;
	else
		return 1;
}

int checkDoorBlocker(int door) {
	if(door <= 0.5 && blocker[0] == 1)
		return 1;
	else
		return 0;
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
				/* printf("CUP"); */
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						/* check Door is close */
						if(checkDoorClose(eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						goDown(&elevator[0]);
						/* printf("---dang xuong %d---\n",elevator[0]); */
						break;
					case 1:
						/* check Door is close */
						if(checkDoorClose(eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						goUp(&elevator[0]);
						/* printf("---dang len %d---\n",elevator[0]); */
						break;
					case 0:
						dequeueAction(&list[0],ACT_CUP,action->key);
						dequeueAction(&list[0],ACT_FLOOR,action->key);
						if (comparePosition(elevator[0],120) == 0)
							dequeueAction(&list[0],ACT_CDOWN,action->key);
						printf("---den tang %d---\n",extractInt(action->key));
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_CDOWN:
				/* printf("CDOWN"); */
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						/* check Door is close */
						if(checkDoorClose(eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						goDown(&elevator[0]);
						/* printf("---dang xuong %d---\n",elevator[0]); */
						break;
					case 1:
						/* check Door is close */
						if(checkDoorClose(eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						goUp(&elevator[0]);
						/* printf("---dang len %d---\n",elevator[0]); */
						break;
					case 0:
						dequeueAction(&list[0],ACT_CDOWN,action->key);
						dequeueAction(&list[0],ACT_FLOOR,action->key);
						if (comparePosition(elevator[0],20) == 0)
							dequeueAction(&list[0],ACT_CUP,action->key);
						printf("---den tang %d---\n",extractInt(action->key));
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_FLOOR:
				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						/* check Door is close */
						if(checkDoorClose(eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						goDown(&elevator[0]);
						/* printf("---dang xuong %d---\n",elevator[0]); */
						break;
					case 1:
						/* check Door is close */
						if(checkDoorClose(eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						goUp(&elevator[0]);
						/* printf("---dang len %d---\n",elevator[0]); */
						break;
					case 0:
						dequeueAction(&list[0],ACT_FLOOR,action->key);
						if (comparePosition(elevator[0],20) == 0 ||comparePosition(elevator[0],120) == 0 || directOfElevator(list[0],elevator[0]) >= 1)
							dequeueAction(&list[0],ACT_CUP,action->key);
						if (comparePosition(elevator[0],20) == 0 ||comparePosition(elevator[0],120) == 0 || directOfElevator(list[0],elevator[0]) <= 1)
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
						/* printf("dong nay \n"); */
						return makeDCloseRespond(action->key);
					case 1:
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
						/* check weight */
						if(checkWeight(50,eleWeight[0]) == 1)
							return makeOverloadRespond(action->key);

						if(checkDoorBlocker(eleDoor[0]) == 1)
							return makeDoorCanNotCloseRespond(action->key);

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
			break;
		case ACT_DCLOSE:
			// giong ACT_DOPEN
			// action dong cua
			/* check weight */
			if(checkWeight(50,eleWeight[0]) == 1)
				return makeOverloadRespond(action->key);

			dequeueAction(&list[0],ACT_DOPEN,NULL);
			enqueueAction(&list[0],action,elevator[0]);
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
		case ACT_STOP:
			break;
		default:
			break;
	}
	return working();
}
