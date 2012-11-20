#ifndef _H_ACTIONER_H
#define _H_ACTIONER_H

#include "data.h"
#include "planner.h"

extern int elevator[2];

Respond* executeAction(Action* action);

Respond* working();

#endif
