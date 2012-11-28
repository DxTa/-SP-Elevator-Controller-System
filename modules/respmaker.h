#ifndef _H_ACTMAKER_H
#define _H_ACTMAKER_H

#include "data.h"

Respond* makeArrivalRespond(void *key);
Respond* makeDCloseRespond(void *key);
Respond* makeDoorNotCloseRespond(void* key);
Respond* makeDoorCanNotCloseRespond(void* key);
Respond* makeOverloadRespond(void* key);
Respond* makeFallingRespond(void* key);

#endif

