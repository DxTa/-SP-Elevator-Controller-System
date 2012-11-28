#include "actioner.h"

Fnode* list[2];
//for show the current direction of elevator
//1 --> up. -1 --> down. 0 -->stand still
//useful for led display and for tracking previous state
int state[2];

Respond* working() {
	if(list[0]) {
		Action *action = list[0]->val;
		switch(action->actionType) {
			case ACT_ALARM:
				alarmer(makeInt(elevator[0]));
				curMessage = display(DISP_ALARM,makeInt(elevator[0]));
				break;
			case ACT_BREAK:
				brake();
				break;
			case ACT_CUP:
				/* check falling */
				if(check(CHECK_MOTOR_SPEED,Motorspeed) == 1)
					return makeFallingRespond(makeInt(elevator[0]));

				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						/* check Door is close */
						if(check(CHECK_DOOR_CLOSE,eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						curMessage = display(DISP_MOVEDOWN,makeInt(elevator[0]));
						goDown(&elevator[0]);
						state[0] = -1;
						break;
					case 1:
						/* check Door is close */
						if(check(CHECK_DOOR_CLOSE,eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						curMessage = display(DISP_MOVEUP,makeInt(elevator[0]));
						goUp(&elevator[0]);
						state[0] = 1;
						break;
					case 0:
						curMessage = display(DISP_ARRIVAL,action->key);
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_CDOWN:
				/* check falling */
				if(check(CHECK_MOTOR_SPEED,Motorspeed) == 1)
					return makeFallingRespond(makeInt(elevator[0]));

				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						/* check Door is close */
						if(check(CHECK_DOOR_CLOSE,eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						curMessage = display(DISP_MOVEDOWN,makeInt(elevator[0]));
						goDown(&elevator[0]);
						state[0] = -1;
						break;
					case 1:
						/* check Door is close */
						if(check(CHECK_DOOR_CLOSE,eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						curMessage = display(DISP_MOVEUP,makeInt(elevator[0]));
						goUp(&elevator[0]);
						state[0] = 1;
						break;
					case 0:
						curMessage = display(DISP_ARRIVAL,action->key);
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_FLOOR:
				/* check falling */
				if(check(CHECK_MOTOR_SPEED,Motorspeed) == 1)
					return makeFallingRespond(makeInt(elevator[0]));

				switch(comparePosition(elevator[0],extractInt(action->key))) {
					case -1 :
						/* check Door is close */
						if(check(CHECK_DOOR_CLOSE,eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						curMessage = display(DISP_MOVEDOWN,makeInt(elevator[0]));
						goDown(&elevator[0]);
						state[0] = -1;
						break;
					case 1:
						/* check Door is close */
						if(check(CHECK_DOOR_CLOSE,eleDoor[0]) == 1)
							return makeDoorNotCloseRespond(action->key);

						curMessage = display(DISP_MOVEUP,makeInt(elevator[0]));
						goUp(&elevator[0]);
						state[0] = 1;
						break;
					case 0:
						curMessage = display(DISP_ARRIVAL,action->key);
						return makeArrivalRespond(action->key);
				}
				break;
			case ACT_DOPEN:
				state[0] = directOfElevator(list[0],elevator[0]);
				switch(isDOpen(&eleDoor[0])) {
					case 0:
						//check j thi o day
						dequeueAction(&list[0],ACT_DOPEN,NULL);
						return makeDCloseRespond(action->key);
					case 1:
						break;
					case 2:
						openD(&eleDoor[0]);
						printf("dang mo %.2f \%\n",eleDoor[0]);
						break;
				}
				break;
			case ACT_DCLOSE:
				switch(isDClose(&eleDoor[0])) {
					case 0:
						//check j thi o day
						dequeueAction(&list[0],ACT_DCLOSE,NULL);
						printf("dong duoc roi\n");
						break;
					case 1:
						/* check weight */
						if(check(CHECK_WEIGHT,eleWeight[0]) == 1)
							return makeOverloadRespond(action->key);

						if(check(CHECK_DOOR_BLOCKER,eleDoor[0]) == 1) {
							dequeueAction(&list[0],ACT_DCLOSE,NULL);
							return makeDoorCanNotCloseRespond(action->key);
						}

						closeD(&eleDoor[0]);
						printf("dang dong %.2f \%\n",eleDoor[0]);
						break;
				}
				break;
		}
		if(checkMotorSpeed(Motorspeed) == 0)
			dequeueAction(&list[0],ACT_BREAK,NULL);
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
			enqueueAction(&list[0],action,elevator[0],state[0]);
			break;
		case ACT_DOPEN:
			enqueueAction(&list[0],action,elevator[0],state[0]);
			break;
		case ACT_DCLOSE:
			/* check weight */
			if(check(CHECK_WEIGHT,eleWeight[0]) == 1)
				return makeOverloadRespond(action->key);
			enqueueAction(&list[0],action,elevator[0],state[0]);
			break;
		case ACT_ALARM:
			if (checkExistAct(list[0],ACT_ALARM,NULL) > 0 ) {
				dequeueAction(&list[0],ACT_ALARM,NULL);
				curMessage = display(DISP_WORK,makeInt(elevator[0]));
			}
			else
				enqueueAction(&list[0],action,elevator[0],state[0]);
			break;
		case ACT_BREAK:
			enqueueAction(&list[0],action,elevator[0],state[0]);
			break;
		case ACT_STOP:
			break;
		default:
			break;
	}
	return working();
}
