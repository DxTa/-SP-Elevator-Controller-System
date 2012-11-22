#include "responder.h"
#define NUM_OF_RESPONDS 10

// se co nhung loi k thuc hien trong nay, vi du nhu loi dut cap,
// cac loi do se dc xu li bang phuong phap co khi, dung phan cung
struct Respond responds[10] = {
	// co vat can khong cho cua dong
  {RES_DOOR_CANNOT_CLOSE, "", "Door cannot close."},
  // loi khi tang o ngoai range
  {RES_INVALID_FLOOR, "", "Floor cannot be reached."},
  // button khi o ngoai thang may, chi co the len tren hoac xuong
  // duoi (0 hoac 1)
  {RES_INVALID_BUTTON, "", "Button is not determined."},
  // qua nhieu nguoi trong thang may
  {RES_OVERLOAD, "", "Overload."},

  {RES_OPEN_DOOR, "", "Open door"},
  {RES_CLOSE_DOOR, "", "Close door"}
};

Respond* makeDoorCannotCloseRespond() {
	Respond* r = (Respond*)malloc(sizeof(Respond));
	r->respondType = RES_DOOR_CANNOT_CLOSE;
	return r;
}

Respond* makeDOPENDoneRespond() {
	Respond* r = (Respond*)malloc(sizeof(Respond));
	r->respondType = RES_OPEN_DOOR;
	return r;
}

Respond* makeDCLOSEDoneRespond() {
	Respond* r = (Respond*)malloc(sizeof(Respond));
	r->respondType = RES_CLOSE_DOOR;
	return r;
}

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
    case RES_DOOR_CANNOT_CLOSE:
			error(RES_DOOR_CANNOT_CLOSE);
			return makeDOPENAction(respond->key);
			break;
    case RES_INVALID_FLOOR:
			error(RES_INVALID_FLOOR);
			//TODO: bo request nay di, xu li request tiep trong queue
			break;
    case RES_INVALID_BUTTON:
			error(RES_INVALID_BUTTON);
			//TODO: bo request nay di, xu li request tiep trong queue
			break;
    case RES_OVERLOAD:
			error(RES_OVERLOAD);
			return makeDOPENAction(respond->key);
			break;

		// respond khi ng dung bam nut mo hoac dong thang may
	case RES_OPEN_DOOR:
			return makeDOPENAction(respond->key);
			break;
	case RES_CLOSE_DOOR:
			return makeDCLOSEAction(respond->key);
			break;

	default:
			break;
	}
	return NULL;
}
