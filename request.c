#include "request.h"


Request* makeCUPRequest(void* key) {
	Request *req = (Request*)malloc(sizeof(Request));
	req->requestType = REQ_CUP;
	req->key = (int*)key;
	return req;
}

Request* makeCDOWNRequest(void* key) {
	Request *req = (Request*)malloc(sizeof(Request));
	req->requestType = REQ_CDOWN;
	req->key = (int*)key;
	return req;
}

Request* makeFLOORRequest(void* key) {
	Request *req = (Request*)malloc(sizeof(Request));
	req->requestType = REQ_FLOOR;
	req->key = (int*)key;
	return req;
}

Request* makeDOPENRequest(void* key) {
	Request *req = (Request*)malloc(sizeof(Request));
	req->requestType = REQ_DOPEN;
	req->key = key;
	return req;
}

Request* makeDCLOSERequest(void* key) {
	Request *req = (Request*)malloc(sizeof(Request));
	req->requestType = REQ_DCLOSE;
	req->key = key;
	return req;
}

Request* makeALARMRequest(void* key) {
	Request *req = (Request*)malloc(sizeof(Request));
	req->requestType = REQ_ALARM;
	req->key = key;
	return req;
}

Request* sendRequest(RequestType reqType,void* key) {
	switch(reqType) {
		case REQ_CUP:
			return makeCUPRequest(key);
		case REQ_CDOWN:
			return makeCDOWNRequest(key);
		case REQ_FLOOR:
			return makeFLOORRequest(key);
		case REQ_DOPEN:
			return makeDOPENRequest(key);
		case REQ_DCLOSE:
			return makeDCLOSERequest(key);
		case REQ_ALARM:
			return makeALARMRequest(key);
	}
	return NULL;
}
