#ifndef _H_ACTIONER_H
#define _H_ACTIONER_H

#include "data.h"
#include "planner.h"
#include "engine.h"
#include "respmaker.h"
#include "checker.h"
#include "informer.h"

extern Fnode* list[2];

void addWeight(int cur,int more);

Respond* executeAction(Action* action);

Respond* working();

#endif
