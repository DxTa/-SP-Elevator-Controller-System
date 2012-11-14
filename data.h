#ifndef _H_DATA_H_
#define _H_DATA_H_

#include <stdio.h>
#include <malloc.h>

typedef enum {
	REQ_CUP,
	REQ_CDOWN,
	REQ_FLOOR,
	REQ_DOPEN,
	REQ_DCLOSE,
	REQ_ALARM,

} RequestType;

typedef enum {
	ACT_CUP,
	ACT_CDOWN,
	ACT_FLOOR,
	ACT_DOPEN,
	ACT_DCLOSE,
	ACT_ALARM,

} ActionType;

typedef enum {
	ERR_CUP,
	ERR_CDOWN,
	ERR_DOPEN,
	ERR_FLOOR,
	ERR_DCLOSE,
	ERR_ALARM,
} ErrorType;

typedef struct {
	RequestType requestType;
	void* key;
} Request;

typedef struct _Action {
	ActionType actionType;
	void* key;
} Action;

typedef struct _Error {
	ErrorType errorType;
} Error

#endif
