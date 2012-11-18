#include "responder.h"
#define NUM_OF_RESPONDS 10

// se co nhung loi k thuc hien trong nay, vi du nhu loi dut cap, 
// cac loi do se dc xu li bang phuong phap co khi, dung phan cung
struct Respond responds[10] = {
	// co vat can khong cho cua dong
  {RES_DOOR_CANNOT_CLOSE, "Door cannot close."},
  // loi khi tang o ngoai range
  {RES_INVALID_FLOOR, "Floor cannot be reached."},
  // button khi o ngoai thang may, chi co the len tren hoac xuong 
  // duoi (0 hoac 1)
  {RES_INVALID_BUTTON, "Button is not determined."},
  // qua nhieu nguoi trong thang may
  {RES_OVERLOAD}, "Overload."}
};

// in ra thong bao loi, tam thoi dung chuong trinh. 
// TODO: chuoi cac hoat dong khi gap error
void error(RespondType res) {
  int i;
  for (i = 0 ; i < NUM_OF_RESPONDS; i++) 
    if (responds[i].respondType == res) {
      //printf("%s\n", responds[i].message);
      exit(0);
    }
}

Action* executeRespond(Respond* respond) {
	switch(respond->respondType) {
		case RES_DOOR_CANNOT_CLOSE
			error(RES_DOOR_CANNOT_CLOSE);
			// mo cua o vi tri hien tai, can bien current position
			return makeDOPENAction();
			break;
		case RES_INVALID_FLOOR
			error(RES_INVALID_FLOOR);
			// bo request nay di, xu li request tiep trong queue
			break;
		case RES_INVALID_BUTTON
			error(RES_INVALID_BUTTON);
			// bo request nay di, xu li request tiep trong queue
			break;
		case ERR_OVERLOAD
			error(RES_OVERLOAD);
			return makeDOPENAction();
			break;
		default:
			break;
	}
	return NULL;
}
