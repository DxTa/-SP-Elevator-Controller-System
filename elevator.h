#ifndef _H_ELEVATOR_H_
#define _H_ELEVATOR_H_

#include "data.c"

Action* makeCUPAction(void* key);
Action* makeCDOWNAction(void* key);
Action* makeFLOORAction(void* key);
Action* makeDOPENAction(void* key);
Action* makeDCLOSEAction(void* key);
Action* makeALARMAction(void* key);

Action* executeRequest(Request* request);

#endif
