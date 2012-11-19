#ifndef _H_DATA_H_
#define _H_DATA_H_

#include <stdlib.h>

typedef enum {
	REQ_CUP,
	REQ_CDOWN,
	REQ_FLOOR,
	REQ_DOPEN,
	REQ_DCLOSE,
	REQ_ALARM,

} RequestType;

typedef enum {
	ACT_CUP,	//car up
	ACT_CDOWN,	//car down
	ACT_FLOOR,
	ACT_DOPEN,
	ACT_DCLOSE,
	ACT_ALARM,
	ACT_BREAK,
	ACT_LDIRECTION, //led for direction
	ACT_LFLOOR,	//led for floor number
	ACT_LMESSAGE, //led for show message

} ActionType;

typedef enum {
	ERR_CUP,
	ERR_CDOWN,
	ERR_DOPEN,
	ERR_FLOOR,
	ERR_DCLOSE,
	ERR_ALARM,
} RespondType;

typedef struct Request {
	RequestType requestType;
	void* key;
} Request;

typedef struct Action {
	ActionType actionType;
	void* key;
} Action;

typedef struct Respond {
	RespondType respondType;
} Respond;


extern char* curMessage;

int* makeInt(int value);

#endif
;
