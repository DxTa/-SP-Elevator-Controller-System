#ifndef _H_ACTIONER_H
#define _H_ACTIONER_H

#include "data.h"
#include "respmaker.h"

#include "door.h"
#include "planner.h"
#include "engine.h"
#include "checker.h"
#include "informer.h"
#include "displayer.h"
#include "alarmer.h"

extern Fnode* list[2];

Respond* executeAction(Action* action);

Respond* working();

#endif
