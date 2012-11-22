#ifndef _H_ACTIONER_H
#define _H_ACTIONER_H

#include "data.h"
#include "planner.h"
#include "engine.h"

extern int elevator[2];


Respond* makeArrivalRespond(void *key);

Respond* executeAction(Action* action);

int comparePosition(int cur,int des);

Respond* working();

#endif
