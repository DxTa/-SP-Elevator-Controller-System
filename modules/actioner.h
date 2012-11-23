#ifndef _H_ACTIONER_H
#define _H_ACTIONER_H

#include "data.h"
#include "planner.h"
#include "engine.h"
#include "respmaker.h"

extern int elevator[2];

int comparePosition(int cur,int des);

Respond* executeAction(Action* action);

Respond* working();

#endif
