#include "actioner.h"

int elevator[2];

Respond* executeAction(Action* action) {
	switch(action->actionType) {
		case ACT_CUP:
			break;
		case ACT_CDOWN:
			break;
		case ACT_FLOOR:
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
	return NULL;
}
