#include "alarmer.h"


char* alarmer(void* value) {
	char buff[100];
	sprintf(buff,"alarm %.0f\n",floor(extractInt(value)/400));
	printf("%s",buff);
	return strdup(buff);
}
