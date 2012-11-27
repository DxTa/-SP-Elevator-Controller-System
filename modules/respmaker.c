#include "respmaker.h"


Respond* makeArrivalRespond(void *key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RESP_ARRIVAL;
	return resp;
}

Respond* makeDCloseRespond(void *key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RESP_CLOSE_DOOR;
	return resp;
}

Respond* makeOverloadRespond(void* key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RESP_OVERLOAD;
	return resp;
}

Respond* makeDoorNotCloseRespond(void* key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RESP_DOOR_NOT_CLOSE;
	return resp;
}

Respond* makeDoorCanNotCloseRespond(void* key) {
	Respond* resp = (Respond*)malloc(sizeof(Respond));
	resp->key = key;
	resp->respondType = RESP_DOOR_CANNOT_CLOSE;
	return resp;
}

