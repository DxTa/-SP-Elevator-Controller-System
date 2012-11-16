#ifndef _H_FQUEUE_H_
#define _H_FQUEUE_H_

#include <stdlib.h>

typedef struct Fnode {
	void* (*function)();
	struct Fnode* next;
} Fnode;


Fnode* currFnode;

Fnode* newFnode(void*(*pfunction)());
void addFnode(Fnode** list, void*(*pfunction)());

#endif
