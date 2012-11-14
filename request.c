#include "request.h"

Request* sendRequest(RequestType reqType,void* key) {
	switch(reqType) {
		case REQ_CUP:
			return makeCUPRequest(key);
		case REQ_CDOWN:
			return makeCDOWNRequest(key);
		case REQ_FLOOR:
			return makeFLOORRequest(key);
		case REQ_DOPEN:
			return makeDOPENRequet(key);
		case REQ_DCLOSE:
			return makeDCLOSERequest(key);
		case REQ_ALARM:
			return makeALARMRequest(key);
	}
	return NULL;
}
