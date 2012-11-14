#include "elevator.h"

Action* executeRequest(Request* request) {
	if(request == NULL)
		return NULL;
	// check hang ho xong goi action
	switch(request->requestType) {
		case REQ_CUP:
			break;
		case REQ_CDOWN:
			break;
		case REQ_FLOOR:
			break;
		case REQ_DOPEN:
			break;
		case REQ_DCLOSE:
			break;
		case REQ_ALARM:
			break;
	}
}

