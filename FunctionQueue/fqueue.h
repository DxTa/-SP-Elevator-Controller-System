#ifndef _H_FQUEUE_H_
#define _H_FQUEUE_H_

#include <stdlib.h>

typedef struct Fnode {
	Action val;
	struct Fnode* next;
} Fnode;


Fnode* currFnode;

Fnode* newFnode(Action act);
void addFnode(Fnode** list, Action act);

#endif
