#include "displayer.h"


char* display(int display,void* value) {
	char buff[100];
	switch(display) {
		case DISP_ARRIVAL:
			sprintf(buff,"%d",extractInt(value)/20);
			return strdup(buff);
		case DISP_MOVEUP:
			sprintf(buff,"^ %.0f",floor(extractInt(value)/400));
			return strdup(buff);
		case DISP_MOVEDOWN:
			sprintf(buff,"V %.0f",floor(extractInt(value)/400));
			return strdup(buff);
		case DISP_WORK:
			sprintf(buff,"%.0f",floor(extractInt(value)/400));
			return strdup(buff);
		case DISP_ALARM:
			sprintf(buff,"Alarm");
			return strdup(buff);
		case DISP_BRAKE:
			sprintf(buff,"Braking");
			return strdup(buff);
		case DISP_OVERLOAD:
			sprintf(buff,"OVERLOAD");
			return strdup(buff);
	}
	return "";
}
