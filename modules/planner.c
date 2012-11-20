#include "planner.h"
//tat ca cac bien `int el` la de xac dinh dieu khien thang may nao
//chua dung j nhieu
//nhung chac la se dung`

void enqueueAction(Fnode** list, Action *act, int el) {
	Fnode* curr;
	int index = 0;
	switch(act->actionType) {
		case ACT_BREAK:
			if ((*list)->val->actionType != ACT_BREAK)
				addFnode(list,act);
			break;
		case ACT_CUP:
			curr = NULL;
			index = 0;
			if ((*list != NULL) && (*list)->val->actionType == ACT_BREAK) {
				curr = (*list)->next;
				index++;
			}
			else curr = *list;
			while(1) {
				if (el == extractInt(act->key))
					break;
				else if (curr == NULL) {
					addFnodeAt(list,act,index);
					break;
				}
				else if ( ((el <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->val->key))) ||
						((curr->next != NULL) && (extractInt(curr->val->key) <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->next->val->key)))) {
					addFnodeAt(list,act,index);
					break;

				}
				else {
					curr = curr->next;
					index++;
					continue;

				}
			}
			break;
		case ACT_CDOWN:
			curr = NULL;
			index=0;
			if ((*list != NULL) && (*list)->val->actionType == ACT_BREAK) {
				curr = (*list)->next;
				index++;
			}
			else {
				curr = *list;
			}

			while(1) {
				if (el == extractInt(act->key))
					break;
				else if (curr == NULL) {
					addFnodeAt(list,act,index);
					break;
				}
				else if (((el >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->val->key))) ||
						((curr->next != NULL) && (extractInt(curr->val->key) >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->next->val->key))) ) {
					addFnodeAt(list,act,index);
					break;
				}
				else {
					curr = curr->next;
					index++;
					continue;
				}
			}
			break;
		case ACT_FLOOR:
			curr = NULL;
			index=0;
			if ((*list != NULL) && (*list)->val->actionType == ACT_BREAK) {
				curr = (*list)->next;
				index++;
			}
			else curr = *list;
			while(1) {
				if (el == extractInt(act->key))
					break;
				else if (curr == NULL) {
					addFnodeAt(list,act,index);
					break;
				}
				else if ( ((el <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->val->key))) ||
						((el >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->val->key))) ||
						((curr->next != NULL) && (extractInt(curr->val->key) <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->next->val->key))) ||
					((curr->next != NULL) && (extractInt(curr->val->key) >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->next->val->key))) ) {
						addFnodeAt(list,act,index);
						break;

					}
				else {
					curr = curr->next;
					index++;
					continue;

				}
			}
			break;
	}
}

//ham nay se duoc goi khi thang may den 1 tang
//no se loai bo cac action thua` thai~ khoi lich trinh
/* void dequeueAction(Fnode* *list, int floor, int el) { */
	/* Fnode *curr,*prev,*temp; */
	/* curr = *list; */
	/* prev = NULL; */
	/* while(1){ */
		/* switch(1) { */
			/* case (curr == NULL): */
				/* break; */
			/* case (curr->val->actionType == ACT_FLOOR && extractInt(curr->val->key) == floor): */
			/* case (directOfElevator(*list,el) == 1 && curr->val->actionType == ACT_CUP && extractInt(curr->val->key) == floor): */
			/* case (directOfElevator(*list,el) == -1 && curr->val->actionType == ACT_CDOWN && extractInt(curr->val->key) == floor): */
			/* case (directOfElevator(*list,el) == 0 && extractInt(curr->val->key) == floor): */
				/* if (prev == NULL) { */
					/* *list = curr->next; */
					/* temp = curr; */
					/* curr = curr->next; */
					/* [> free(temp); <] */
				/* } */
				/* else { */
					/* prev->next = curr->next; */
					/* temp = curr; */
					/* curr = curr->next; */
					/* [> free(temp); <] */
				/* } */
				/* continue; */
			/* default: */
				/* prev = curr; */
				/* curr = curr->next; */
				/* continue; */
		/* } */
		/* break; */
	/* } */
/* } */

Fnode* nextDes(Fnode *list, int el,Fnode *now) {
	Fnode *curr;
	if (now == NULL)
		curr = list;
	else
		curr = now->next;
	while(curr != NULL) {
		if (curr != ACT_BREAK && extractInt(curr->val->key) != extractInt(now->val->key) && extractInt(curr->val->key) != el)
			break;
		else
			curr = curr->next;
	}
	return curr;
}

int directOfElevator(Fnode *list, int el) {
	Fnode* des;
	des = nextDes(list,el,NULL);
	if (extractInt(des->val->key) < el)
		return -1; //go down
	else if (extractInt(des->val->key) > el)
		return 1; //go up
	else
		return 0; //go no where
}
