#include "responder.h"
#include <stdio.h>
#define NUM_OF_RESPONDS 10

struct Respond responds[10] = {
	// co vat can khong cho cua dong
  {RESP_DOOR_CANNOT_CLOSE, "", "Door cannot close."},
  // loi khi tang o ngoai range
  {RESP_INVALID_FLOOR, "", "Floor cannot be reached."},
  // button khi o ngoai thang may, chi co the len tren hoac xuong
  // duoi (0 hoac 1)
  {RESP_INVALID_BUTTON, "", "Button is not determined."},
  // qua nhieu nguoi trong thang may
  {RESP_OVERLOAD, "", "Overload."},

  {RESP_OPEN_DOOR, "", "Open door"},
  {RESP_CLOSE_DOOR, "", "Close door"},
  {RESP_DOOR_NOT_CLOSE,"","Door not Close"},
  {RESP_FALLING,"","FALLLING"}
};

// TODO: chuoi cac hoat dong khi gap error
void error(RespondType res) {
  int i;
  for (i = 0 ; i < NUM_OF_RESPONDS; i++)
    if (responds[i].respondType == res) {
      printf("%s\n", responds[i].message);
      //exit(0);
    }
}

Action* executeRespond(Respond* respond) {
	switch(respond->respondType) {
		case RESP_ARRIVAL:
			return makeDOPENAction(respond->key);
			break;
		case RESP_DOOR_CANNOT_CLOSE:
			error(RESP_DOOR_CANNOT_CLOSE);
			return makeDOPENAction(respond->key);
			break;
		case RESP_INVALID_FLOOR:
			error(RESP_INVALID_FLOOR);
			//TODO: bo request nay di, xu li request tiep trong queue
			break;
		case RESP_INVALID_BUTTON:
			error(RESP_INVALID_BUTTON);
			//TODO: bo request nay di, xu li request tiep trong queue
			break;
		case RESP_OVERLOAD:
			error(RESP_OVERLOAD);
			return makeDOPENAction(respond->key);
			break;
		case RESP_DOOR_NOT_CLOSE:
			error(RESP_DOOR_NOT_CLOSE);
			return makeDOPENAction(respond->key);
			break;

			// respond khi ng dung bam nut mo hoac dong thang may
		case RESP_OPEN_DOOR:
			return makeDOPENAction(respond->key);
			break;
		case RESP_CLOSE_DOOR:
			return makeDCLOSEAction(respond->key);
			break;

		case RESP_FALLING:
			return makeBREAKAction(respond->key);
			break;

		default:
			break;
	}
	return NULL;
}
