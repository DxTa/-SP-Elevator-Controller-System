#ifndef _H_DOOR_H_
#define _H_DOOR_H_

#include "data.h"

extern float wait_time;

void openD(float *pos);
void closeD(float *pos);
int isDOpen(float *pos);
int isDClose(float *pos);

#endif
