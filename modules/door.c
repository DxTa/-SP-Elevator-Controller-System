#include "door.h"

const float door_speed = 0.04;
float wait_time = 4;

void openD(float *pos) {
	if (*pos < 1)
		*pos += door_speed;
}

void closeD(float *pos) {
	if (*pos > 0)
		*pos -= door_speed;
}

int isDOpen(float *pos) {
	if (*pos >= 1) {
		*pos = 1;
		if(wait_time <=  0) {
			wait_time = 3;
			return 0;
		} else {
			wait_time -= door_speed;
			return 1;
		}
	}
	else return 2;
}

int isDClose(float *pos) {
	if (*pos <= 0) {
		*pos = 0;
		return 0;
	}
	else return 1;
}

;
