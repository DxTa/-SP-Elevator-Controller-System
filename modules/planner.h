#ifndef _H_ACTION_H
#define _H_ACTION_H

#include "data.h"
#include "./FunctionQueue/fqueue.h"

void enqueueAction(Fnode** list, Action *act, int el);
void dequeueAction(Fnode* *list, int floor, int el);
Fnode* nextDes(Fnode *list, int el, Fnode *now);
int directOfElevator(Fnode *list, int el);

#endif
