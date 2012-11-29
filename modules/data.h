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
	ACT_STOP

} ActionType;

typedef enum {
	RESP_ARRIVAL,
	RESP_OVERLOAD,

	RESP_DOOR_CANNOT_CLOSE,
	RESP_INVALID_FLOOR,
	RESP_INVALID_BUTTON,
	RESP_DOOR_NOT_CLOSE,

	RESP_OPEN_DOOR,
	RESP_CLOSE_DOOR,

	RESP_FALLING
} RespondType;

typedef enum {
	CHECK_WEIGHT,
	CHECK_DOOR_OPEN,
	CHECK_DOOR_CLOSE,
	CHECK_DOOR_BLOCKER,
	CHECK_MOTOR_SPEED,
	CHECK_ON_FLOOR
} CheckType;

typedef enum {
	DISP_ARRIVAL,
	DISP_MOVEUP,
	DISP_MOVEDOWN,
	DISP_ALARM,
	DISP_BRAKE,
	DISP_WORK,
	DISP_OVERLOAD
} DisplayType;

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
	void* key;
	char *message;
} Respond;


extern char* curMessage;
extern Request *curReq;
extern Action *curAct;
extern Respond *curResp;
extern int blocker[2];
extern int maxSpeed;
extern int maxWeight;
extern char* schedule[2];

int* makeInt(int value);

void addWeight(int cur,int more);

int extractInt(void *val);

#endif
;
