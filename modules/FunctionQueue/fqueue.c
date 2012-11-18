#include "fqueue.h"

Fnode* newFnode(Action *act) {
	Fnode *node = (Fnode*)malloc(sizeof(Fnode));
	node->val = act;
	node->next = NULL;
	return node;
}

void addFnode(Fnode* *list, Action *act) {
	Fnode *newNode = newFnode(act);
	if (*list == NULL)
		*list = newNode;
	else {
		newNode->next = *list;
		*list = newNode;
	}
}

void addFnodeAt(Fnode* *list, Action *act, int offset) {
	Fnode *newNode = newFnode(act);
	Fnode *curr;
	if (*list == NULL)
		*list = newNode;
	else {
		Fnode *prev = NULL;
		curr = *list;
		int count = 0;
		while(curr != NULL && count != offset) {
			prev = curr;
			curr = curr->next;
			count++;
		}
		if (prev != NULL)
			prev->next = newNode;
		if (curr != NULL)
			newNode->next = curr;
		*list = newNode;
	}
}

void removeFnodeAtBack(Fnode* *list) {
	Fnode* temp;
	temp = *list;
	*list = (*list)->next;
	/* free(temp); */
}

void removeFnodeAtRear(Fnode* *list) {
	if (*list == NULL)
		return;
	Fnode *temp,*prev;
	prev = NULL;
	temp = *list;
	while(temp->next !=NULL) {
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL)
		*list = NULL;
	else
		prev->next = NULL;
	/* free(temp); */
}
