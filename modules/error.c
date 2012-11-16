#include "error.h"

Action* executeError(Error* err) {
	switch(err->errorType) {
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
