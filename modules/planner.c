//tat ca cac bien `int el` la de xac dinh dieu khien thang may nao
//chua dung j nhieu
//nhung chac la se dung`

void enqueueAction(Fnode** list, Action *act, int el) {
	switch(act->ActionType) {
		case ACT_BREAK:
			if ((*list)->val->ActionType != ACT_BREAK)
				addFnode(list,act);
			break;
		case ACT_CUP:
			Fnode* curr;
			int index=0;
			if ((*list != NULL) && (*list)->val->ActionType == ACT_BREAK) {
				curr = (*list)->next;
				index++;
			}
			else curr = *list;
			while(true) {
				switch(true) {
					case (elevator[el] == act->key):
						break;
					case (curr == NULL):
						addFnodeAt(list,act,index);
						break;
					case ((elevator[el] <= (int)act->key) && ((int)act->key <= (int)curr->val->key)):
					case ((curr->next != NULL) && ((int)curr->val->key <= (int)act->key) && ((int)act->key <= (int)curr->next->val->key)):
						addFnodeAt(list,act,index);
						break;
					default:
						curr = curr->next;
						index++;
						continue;
				}
				break;
			}
			break;
		case ACT_CDOWN:
			Fnode* curr;
			int index=0;
			if ((*list != NULL) && (*list)->val->ActionType == ACT_BREAK) {
				curr = (*list)->next;
				index++;
			}
			else curr = *list;
			while(true) {
				switch(true) {
					case (elevator[el] == act->key):
						break;
					case (curr == NULL):
						addFnodeAt(list,act,index);
						break;
					case ((elevator[el] >= (int)act->key) && ((int)act->key >= (int)curr->val->key)):
					case ((curr->next != NULL) && ((int)curr->val->key >= (int)act->key) && ((int)act->key >= (int)curr->next->val->key)):
						addFnodeAt(list,act,index);
						break;
					default:
						curr = curr->next;
						index++;
						continue;
				}
				break;
			}
		case ACT_FLOOR:
			Fnode* curr;
			int index=0;
			if ((*list != NULL) && (*list)->val->ActionType == ACT_BREAK) {
				curr = (*list)->next;
				index++;
			}
			else curr = *list;
			while(true) {
				switch(true) {
					case (elevator[el] == act->key):
						break;
					case (curr == NULL):
						addFnodeAt(list,act,index);
						break;
					case ((elevator[el] <= (int)act->key) && ((int)act->key <= (int)curr->val->key)):
					case ((elevator[el] >= (int)act->key) && ((int)act->key >= (int)curr->val->key)):
					case ((curr->next != NULL) && ((int)curr->val->key <= (int)act->key) && ((int)act->key <= (int)curr->next->val->key)):
					case ((curr->next != NULL) && ((int)curr->val->key >= (int)act->key) && ((int)act->key >= (int)curr->next->val->key)):
						addFnodeAt(list,act,index);
						break;
					default:
						curr = curr->next;
						index++;
						continue;
				}
				break;
			}
	}
}

//ham nay se duoc goi khi thang may den 1 tang
//no se loai bo cac action thua` thai~ khoi lich trinh
void dequeueAction(Fnode* *list, int floor, int el) {
	Fnode *curr,*prev,*temp;
	curr = *list;
	prev = NULL;
	while(true){
		switch(true) {
			case (curr == NULL):
				break;
			case (curr->val->ActionType == ACT_FLOOR && (int)curr->val->key == floor):
			case (directOfElevator(*list,el) == 1 && curr->val->ActionType == ACT_CUP && (int)curr->val->key == floor):
			case (directOfelevator(*list,el) == -1 && curr->val->ActionType == ACT_CDOWN && (int)curr->val->key == floor):
				if (prev == NULL) {
					*list = curr->next;
					temp = curr;
					curr = curr->next;
					/* free(temp); */
				}
				else {
					prev->next = curr->next;
					temp = curr;
					curr = curr->next;
					/* free(temp); */
				}
				continue;
			default:
				prev = curr;
				curr = curr->next;
				continue;
		}
		break;
	}
}

Fnode* nextDes(Fnode *list, int el) {
	Fnode* curr;
	curr = list;
	while(curr != NULL) {
		if (curr != ACT_BREAK)
			break;
		else
			curr = curr->next;
	}
	return curr;
}

int directOfElevator(Fnode *list, int el) {

	return 0;
}
