#include "data.h"
#include "request.h"
#include "elevator.h"
#include "action.h"

int main() {
	// se co chay timer.

	/*                          --------- Sensor(2 kieu) --------
	                            |								|
								|								|
	        sendRequest         |            sendAction         |      sendError
	request ------------> RequestManager ------------------> action ----------------> errorHandler
														        ^ 						  |
																|     sendAction          |
										     					---------------------------

	*/
	// chac la run kieu the nay
	/* err = executeAction(executeRequest(sendRequest(reqType,key))); */
	/* while(err) { */
		/* err = executeAction(executeError(err)); */
	/* } */

	Request *test;
	int* a = (int*)malloc(sizeof(int));
	*a = 5;
	test = makeCUPRequest(a);
	printf("%d\n",*((int*)test->key));
	return 0;
}
