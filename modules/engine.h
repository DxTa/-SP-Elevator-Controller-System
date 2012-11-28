#ifndef _H_ENGINE_H
#define _H_ENGINE_H

#include "data.h"

void goUp(int *pos);

void goDown(int *pos);

void brake();

void speedUp(int val);

extern double Motorspeed;

#endif
