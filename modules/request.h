#ifndef _H_REQUEST_H
#define _H_REQUEST_H

#include "data.h"

Request* makeCUPRequest(void*);
Request* makeCDOWNRequest(void*);
Request* makeFLOORRequest(void*);
Request* makeDOPENRequest(void*);
Request* makeDCLOSERequest(void*);
Request* makeALARMRequest(void*);

Request* sendRequest(RequestType reqType,void* value);

#endif

