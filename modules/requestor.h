#ifndef _H_REQUESTOR_H_
#define _H_REQUESTOR_H_

#include "data.h"

Action* makeCUPAction(void* key);
Action* makeCDOWNAction(void* key);
Action* makeFLOORAction(void* key);
Action* makeDOPENAction(void* key);
Action* makeDCLOSEAction(void* key);
Action* makeALARMAction(void* key);

Action* executeRequest(Request* request);

#endif
