#include "actioner.h"

int elevator[2] = {0,0};
Fnode* list[2];

Respond* working() {
	if(list[0]) {
		Action *action = list[0]->val;
		switch(action->actionType) {
			case ACT_CUP:
				printf("CUP");
				if(elevator[0] != extractInt(action->key)) {
					if(elevator[0] < extractInt(action->key))
						elevator[0] += 1;
					else
						elevator[0] -= 1;
					printf("---dang len %d---\n",elevator[0]);
				} else {
					printf("---den tang %d---\n",extractInt(action->key));
					dequeueAction(&list[0],elevator[0]);
					printf("LIST %d\n",count(list[0]));
				}
				break;
			case ACT_CDOWN:
				printf("CDOWN");
				if(elevator[0] != extractInt(action->key)) {
					if(elevator[0] < extractInt(action->key))
						elevator[0] += 1;
					else
						elevator[0] -= 1;
					printf("---dang len %d---\n",elevator[0]);
				} else {
					printf("---den tang %d---\n",extractInt(action->key));
					dequeueAction(&list[0],elevator[0]);
					printf("LIST %d\n",count(list[0]));
				}
				break;
			case ACT_FLOOR:
				printf("---dang ... ----\n");
				break;
		}
	}
	return NULL;
}

Respond* executeAction(Action* action) {
	if(action == NULL)
		return working();

	switch(action->actionType) {
		case ACT_CUP:
		case ACT_CDOWN:
		case ACT_FLOOR:
			printf("ALOHA\n");
			printf("LIST BEFORE ENQUEUE %d\n",count(list[0]));
			enqueueAction(&list[0],action,elevator[0]);
			printf("LIST AFTER ENQUEUE %d\n",count(list[0]));
			break;
		case ACT_DOPEN:
			break;
		case ACT_DCLOSE:
			break;
		case ACT_ALARM:
			break;
		case ACT_BREAK:
			break;
		case ACT_LDIRECTION:
			break;
		case ACT_LFLOOR:
			break;
		case ACT_LMESSAGE:
			break;
		default:
			break;
	}
	return working();
}
