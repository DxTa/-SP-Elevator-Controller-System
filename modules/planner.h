#ifndef _H_PLANNER_H
#define _H_PLANNER_H

#include "data.h"
#include "./FunctionQueue/fqueue.h"

void enqueueAction(Fnode** list, Action *act, int el, int state);
void dequeueAction(Fnode* *list, ActionType type, void* key);
Fnode* nextDes(Fnode *list, int el, Fnode *now);
int directOfElevator(Fnode *list, int el);
int checkExistAct(Fnode *list, ActionType type, void *key);
char* scheduleTraverse(Fnode *list);
int count(Fnode* l);

#endif
