#include "alarmer.h"


char* alarmer(void* value) {
	char buff[100];
	sprintf(buff,"alarm");
	return strdup(buff);
}
