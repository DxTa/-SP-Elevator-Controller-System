#include "responder.h"

Action* executeRespond(Respond* respond) {
	switch(respond->respondType) {
		case ERR_CUP:
			break;
		case ERR_CDOWN:
			break;
		case ERR_FLOOR:
			break;
		case ERR_DOPEN:
			break;
		case ERR_DCLOSE:
			break;
		case ERR_ALARM:
			break;
	}
	return NULL;
}
