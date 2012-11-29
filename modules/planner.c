#include "planner.h"

//phan chia muc do uu tien cua action
int getLvlAct(Action *act) {
	switch(act->actionType) {
		case ACT_CUP:
		case ACT_CDOWN:
		case ACT_FLOOR:
			return 1;
		case ACT_ALARM:
		case ACT_BREAK:
			return 4;
		case ACT_DOPEN:
			return 3;
		case ACT_DCLOSE:
			return 2;
		default:
			return -1;
	}
}

int isLastDesTop(Fnode *list, int el, int state) {
	if (state >= 0 && directOfElevator(list,el) <= 0)
		return 0;
}

int isLastDesBot(Fnode *list, int el, int state) {
	if (state <= 0 && directOfElevator(list,el) >= 0)
		return 0;
}

//ham nay ho~ tro cho viec bo? qua nhung~ action khong can thiet
//trong xu ly
int skip(Fnode* list,Fnode* *curr,int lvl) {
	Fnode *temp;
	temp = list;
	int count = 0;

	if (list == NULL)
		return 0;
	else {
		while(temp != NULL && getLvlAct(temp->val) >= lvl) {
			temp = temp-> next;
			count++;
		}
		*curr = temp;
		return count;
	}
}

//kiem tra su ton tai cua mot action
//neu key == NULL thi se dem' so luong ActionType co trong list
int checkExistAct(Fnode *list, ActionType type, void *key) {
	Fnode *curr;
	curr = list;
	int count = 0;
	if (key == NULL) {
		while(curr != NULL) {
			if (curr->val->actionType == type) {
				count++;
			}
			curr = curr->next;
		}

	}
	else {
		while(curr != NULL) {
			if (curr->val->actionType == type && extractInt(curr->val->key) == extractInt(key))
				count++;
			curr = curr->next;
		}
	}


	return count;
}

//ham nay deo check su ton tai cua action truoc
//neu ton tai thi khong add them
//trong nay da bao gom tinh toan routing va muc do uu tien
//thuc hien action
void enqueueAction(Fnode** list, Action *act, int el, int state) {
	Fnode *curr,*temp;
	int index = 0;
	switch(act->actionType) {
		case ACT_DOPEN:
			dequeueAction(&list[0],ACT_DCLOSE,NULL);
			if (isLastDesBot(*list,el,state) == 0 || isLastDesTop(*list,el,state) == 0) {
				dequeueAction(list,ACT_CUP,act->key);
				dequeueAction(list,ACT_FLOOR,act->key);
				dequeueAction(list,ACT_CDOWN,act->key);
			}
			else {
				if (directOfElevator(*list,el) >= 0) {
					dequeueAction(list,ACT_CUP,act->key);
					dequeueAction(list,ACT_FLOOR,act->key);
				}
				else if (directOfElevator(*list,el) <= 0) {
					dequeueAction(list,ACT_CDOWN,act->key);
					dequeueAction(list,ACT_FLOOR,act->key);
				}
			}

			if (checkExistAct(*list, ACT_DOPEN, NULL) > 0)
				break;
			index = skip(*list,&curr,getLvlAct(act) + 1);
			addFnodeAt(list,act,index);
			break;
		case ACT_DCLOSE:
			dequeueAction(&list[0],ACT_DOPEN,NULL);
			if (checkExistAct(*list, ACT_DCLOSE, NULL) > 0)
				break;
			index = skip(*list,&curr,getLvlAct(act) + 1);
			addFnodeAt(list,act,index);
			break;
		case ACT_BREAK:
			if (checkExistAct(*list, ACT_BREAK, NULL) > 0)
				break;
			index = skip(*list,&curr,getLvlAct(act) + 1);
			addFnodeAt(list,act,index);
			break;
		case ACT_ALARM:
			if (checkExistAct(*list, ACT_ALARM, NULL) > 0)
				break;
			index = skip(*list,&curr,getLvlAct(act) + 1);
			addFnodeAt(list,act,index);
			break;
		case ACT_CUP:
			if (checkExistAct(*list, act->actionType, act->key) > 0)
				break;
			curr = NULL;
			index = skip(*list,&curr,getLvlAct(act)+1);
			while(1) {
				if (el == extractInt(act->key)) {
					if (directOfElevator(*list,el) >= 0)
						if (*list == NULL || (*list)->val->actionType != ACT_DOPEN)
							addFnodeAt(list,act,index);
					if ((*list)->val->actionType == ACT_DCLOSE)
						removeFnodeAtBack(list);
					break;
				}
				else if (curr == NULL) {
					addFnodeAt(list,act,index);
					break;
				}
				else if (
						((el <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->val->key))) ||
						((curr->val->actionType == ACT_CUP) && (extractInt(act->key) <= extractInt(curr->val->key))) ||
						((el <= extractInt(curr->val->key)) && (curr->val->actionType == ACT_CDOWN) && (extractInt(act->key) >= extractInt(curr->val->key)))
						) {
					addFnodeAt(list,act,index);
					break;
				}
				else if (
						((curr->next != NULL) && (extractInt(curr->val->key) <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->next->val->key))) ||
						((el <= extractInt(act->key)) && (curr->next != NULL) && (extractInt(curr->next->val->key) == extractInt(curr->val->key) && curr->next->val->actionType != ACT_CUP))
						) {
					index++;
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
			if (checkExistAct(*list, act->actionType, act->key) > 0)
				break;
			curr = NULL;
			index=0;
			index = skip(*list,&curr,getLvlAct(act)+1);
			while(1) {
				if (el == extractInt(act->key)) {
					if (directOfElevator(*list,el) <= 0)
						if (*list == NULL || (*list)->val->actionType != ACT_DOPEN)
							addFnodeAt(list,act,index);
					if ((*list)->val->actionType == ACT_DCLOSE)
						removeFnodeAtBack(list);
					break;
				}
				else if (curr == NULL) {
					addFnodeAt(list,act,index);
					break;
				}
				else if (
						((el >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->val->key))) ||
						((curr->val->actionType == ACT_CDOWN) && (extractInt(act->key) >= extractInt(curr->val->key))) ||
						((el >= extractInt(curr->val->key)) && (curr->val->actionType == ACT_CUP) && (extractInt(act->key) <= extractInt(curr->val->key)))
						){
					addFnodeAt(list,act,index);
					break;
				}
				else if (
						((curr->next != NULL) && (extractInt(curr->val->key) >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->next->val->key))) ||
						((el >= extractInt(act->key)) && (curr->next != NULL) && (extractInt(curr->next->val->key) == extractInt(curr->val->key) && curr->next->val->actionType != ACT_CDOWN))
						){
					index++;
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
			if (checkExistAct(*list, act->actionType, act->key) > 0)
				break;
			curr = NULL;
			index=0;
			index = skip(*list,&curr,getLvlAct(act)+1);
			while(1) {
				if (el == extractInt(act->key))
					break;
				else if (curr == NULL) {
					addFnodeAt(list,act,index);
					break;
				}
				else if ( ((el <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->val->key))) ||
						((el >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->val->key))) ) {
					addFnodeAt(list,act,index);
					break;
				}
				else if (
						((curr->next != NULL) && (extractInt(curr->val->key) <= extractInt(act->key)) && (extractInt(act->key) <= extractInt(curr->next->val->key))) ||
						((curr->next != NULL) && (extractInt(curr->val->key) >= extractInt(act->key)) && (extractInt(act->key) >= extractInt(curr->next->val->key))) ) {
					index++;
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

//if key == NULL, loai bo tat ca cac action chi? dua them ActionType
void dequeueAction(Fnode* *list, ActionType type, void* key) {
	Fnode *curr,*prev;
	curr = *list;
	prev = NULL;

	if (key == NULL) {
		while(curr != NULL) {
			if (curr->val->actionType == type) {
				if (prev == NULL) {
					*list = curr->next;
					curr = *list;
					/* free curr */
				}
				else {
					prev->next = curr->next;
					curr = curr->next;
					/* free curr */
				}
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
	else {
		while(curr != NULL) {
			if (curr->val->actionType == type && extractInt(curr->val->key) == extractInt(key)) {
				if (prev == NULL) {
					*list = curr->next;
					curr = *list;
					/* free curr */
				}
				else {
					prev->next = curr->next;
					curr = curr->next;
					/* free curr */
				}
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

//find the next action that move the car from `Fnode * curr`
//if curr == NULL search from the beginning
Fnode* nextDes(Fnode *list, int el,Fnode *curr) {
	if (list == NULL) return NULL;
	Fnode *temp;
	int index = skip(list,&temp,2);

	while (temp != NULL && curr != NULL) {
		if (temp == curr)
			break;
		else
			temp = temp->next;
	}
	if (temp != curr && curr != NULL)
		return NULL;
	while(temp != NULL) {
		if (getLvlAct(temp->val) == 1 && extractInt(temp->val->key) != el)
			break;
		else
			temp = temp->next;
	}
	return temp;
}

//show the curr direction of elevator
int directOfElevator(Fnode *list, int el) {
	Fnode* des;
	des = nextDes(list,el,NULL);
	if (des == NULL) {
		return 0;
	}
	else if (extractInt(des->val->key) < el)
		return -1; //go down
	else if (extractInt(des->val->key) > el)
		return 1; //go up
	else return 0;
}
