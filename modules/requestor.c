#include "requestor.h"

Action* executeRequest(Request* request) {
	if(request == NULL)
		return NULL;
	switch(request->requestType) {
		case REQ_CUP:
			return makeCUPAction(request->key);
		case REQ_CDOWN:
			return makeCDOWNAction(request->key);
		case REQ_FLOOR:
			return makeFLOORAction(request->key);
		case REQ_DOPEN:
			return makeDOPENAction(request->key);
		case REQ_DCLOSE:
			return makeDCLOSEAction(request->key);
		case REQ_ALARM:
			return makeALARMAction(request->key);
	}
	return NULL;
}

