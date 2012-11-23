#include "door.h"

const float door_speed = 0.003;

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
		return 0;
	}
	else return 1;
}

int isDClose(float *pos) {
	if (*pos <= 0) {
		*pos = 0;
		return 0;
	}
	else return 1;
}

;
