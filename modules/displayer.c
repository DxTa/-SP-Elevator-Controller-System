#include "displayer.h"


char* display(int display,void* value) {
	char buff[100];
	switch(display) {
		case DISP_ARRIVAL:
			sprintf(buff,"%d",extractInt(value));
			printf("%s",buff);
			return strdup(buff);
		case DISP_MOVEUP:
			sprintf(buff,"^ %.0f",floor(extractInt(value)/400));
			printf("%s",buff);
			return strdup(buff);
		case DISP_MOVEDOWN:
			sprintf(buff,"V %.0f",floor(extractInt(value)/400));
			printf("%s",buff);
			return strdup(buff);
	}
	return "";
}
