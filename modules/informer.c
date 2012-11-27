/* Cai nay la sensor nhe , chac chi tra lai may cai int thoi
 *
 */
#include "informer.h"

int elevator[2] = {20,20};
int eleWeight[2] = {0,0};
float eleDoor[2] = {0,0};

int comparePosition(int cur,int des) {
	if(cur > des)
		return -1;
	else if (cur < des)
		return 1;
	else
		return 0;
}
