#ifndef _H_PLANNER_H
#define _H_PLANNER_H

#include "data.h"
#include "./FunctionQueue/fqueue.h"

void enqueueAction(Fnode** list, Action *act, int el);
void dequeueAction(Fnode* *list, int el);
Fnode* nextDes(Fnode *list, int el, Fnode *now);
int directOfElevator(Fnode *list, int el);

#endif
