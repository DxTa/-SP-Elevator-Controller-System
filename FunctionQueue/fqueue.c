#include "fqueue.h"

Fnode* newFnode(Action act) {
	Fnode *node = (Fnode*)malloc(sizeof(Fnode));
	node->val = act;
	node->next = NULL;
	return node;
}

void addFnode(Fnode* *list, Action act) {
	Fnode *newNode = newFnode(act);
	if (*list == NULL)
		*list = newNode;
	else {
		newNode->next = *list;
		*list = newNode;
	}
}

void addFnode(Fnode* *list, Action act, int offset) {
	Fnode *newNode = newFnode(act);
	if (*list == NULL)
		*list = newNode;
	else {
		Fnode *prev = NULL;
		currFnode = *list;
		int count = 0;
		while(currFnode != NULL && count != offset) {
			prev = currFnode;
			currFnode = currFnode->next;
			count++;
		}
		if (prev != NULL)
			prev->next = newNode;
		if (currFnode != NULL)
			newNode->next = currFnode;
		*list = newNode;
	}
}
