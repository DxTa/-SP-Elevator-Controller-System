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
	resp->respondType = RES_CLOSE_DOOR;
	return resp;
}

