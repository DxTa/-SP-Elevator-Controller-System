#include "fqueue.h"

Fnode* newFnode(void*(*pfunction)()) {
	Fnode *node = (Fnode*)malloc(sizeof(Fnode));
	node->function = pfunction;
	node->next = NULL;
	return node;
}

void addFnode(Fnode* *list, void*(*pfunction)()) {
	Fnode *newNode = newFnode(pfunction);
	if (*list == NULL)
		*list = newNode;
	else {
		newNode->next = *list;
		*list = newNode;
	}
}
