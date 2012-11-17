#include "error.h"
#define NUM_OF_ERRORS 10

// se co nhung loi k thuc hien trong nay, vi du nhu loi dut cap, 
// cac loi do se dc xu li bang phuong phap co khi, dung phan cung
struct Error errors[10] = {
	// co vat can khong cho cua dong
  {ERR_DOOR_CANNOT_CLOSE, "Door cannot close."},
  // loi khi tang o ngoai range
  {ERR_INVALID_FLOOR, "Floor cannot be reached."},
  // button khi o ngoai thang may, chi co the len tren hoac xuong 
  // duoi (0 hoac 1)
  {ERR_INVALID_BUTTON, "Button is not determined."},
  // qua nhieu nguoi trong thang may
  {ERR_OVERLOAD}, "Overload."}
};

// in ra thong bao loi, tam thoi dung chuong trinh. 
// TODO: chuoi cac hoat dong khi gap error
void error(ErrorType err) {
  int i;
  for (i = 0 ; i < NUM_OF_ERRORS; i ++) 
    if (errors[i].errorType == err) {
      printf("%s\n", errors[i].message);
      exit(0);
    }
}

Action* executeError(Error* err) {
	switch(err->errorType) {
		case ERR_DOOR_CANNOT_CLOSE
			error(ERR_DOOR_CANNOT_CLOSE);
			// mo cua o vi tri hien tai, can bien current position
			return makeDOPENAction();
			break;
		case ERR_INVALID_FLOOR
			error(ERR_INVALID_FLOOR);
			// bo request nay di, xu li request tiep trong queue
			break;
		case ERR_INVALID_BUTTON
			error(ERR_INVALID_BUTTON);
			// bo request nay di, xu li request tiep trong queue
			break;
		case ERR_OVERLOAD
			error(ERR_OVERLOAD);
			return makeDOPENAction();
			break;
		default:
			break;
	}
	return NULL;
}
