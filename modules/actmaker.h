#ifndef _H_ACTMAKER_H
#define _H_ACTMAKER_H

#include "data.h"

Action* makeCUPAction(void* key);
Action* makeCDOWNAction(void* key);
Action* makeFLOORAction(void* key);
Action* makeDOPENAction(void* key);
Action* makeDCLOSEAction(void* key);
Action* makeALARMAction(void* key);
Action* makeSTOPAction(void* key);


#endif
