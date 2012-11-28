#include "checker.h"

int checkWeight(int maxWeight, int weight) {
	if(weight <= maxWeight)
		return 0;
	else
		return 1;
}

int checkDoorOpen(double door) {
	if(door == 1)
		return 0;
	else
		return 1;
}

int checkDoorClose(double door) {
	if(door == 0)
		return 0;
	else
		return 1;
}

int checkDoorBlocker(double door) {
	if(blocker[0] == 1)
		return 1;
	else
		return 0;
}

int checkMotorSpeed(double speed) {
	if(speed > maxSpeed)
		return 1;
	else
		return 0;
}

int checkOnFloor(int state) {
	if(state == 0)
		return 0;
	else
		return 1;
}


int check(int checker,double val) {
	switch(checker) {
		case CHECK_WEIGHT:
			return checkWeight(maxWeight,val);
		case CHECK_DOOR_OPEN:
			return checkDoorOpen(val);
		case CHECK_DOOR_CLOSE:
			return checkDoorClose(val);
		case CHECK_DOOR_BLOCKER:
			return checkDoorBlocker(val);
		case CHECK_MOTOR_SPEED:
			return checkMotorSpeed(val);
		case CHECK_ON_FLOOR:
			return checkOnFloor(val);
	}

}
