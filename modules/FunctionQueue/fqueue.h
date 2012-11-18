#ifndef _H_FQUEUE_H_
#define _H_FQUEUE_H_

#include <stdlib.h>
#include "../data.h"

typedef struct Fnode {
	Action *val;
	struct Fnode* next;
} Fnode;


Fnode* newFnode(Action *act);
void addFnode(Fnode** list, Action *act);
void addFnodeAt(Fnode* *list, Action *act, int offset);
void removeFnodeAtBack(Fnode* *list);
void removeFnodeAtRear(Fnode* *list);

#endif
