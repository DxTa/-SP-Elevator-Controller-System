#ifndef _H_DATA_H_
#define _H_DATA_H_

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
	ACT_DOPEN,
	ACT_DCLOSE,
	ACT_ALARM,

} ActionType;

typedef enum {
	ERR_CUP,
	ERR_CDOWN,
	ERR_DOPEN,
	ERR_DCLOSE,
	ERR_ALARM,
} ErrorType;

typedef _Request {
	RequestType requestType;
	void* key;
} Request;

typedef _Action {
	ActionType actionType;
	void* key;
} Action;

typedef _Error {
	ErrorType errorType;
} Error

#endif
