#include "checker.h"

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

