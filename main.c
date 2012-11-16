#include <stdio.h>
#include "data.h"
#include "request.h"
#include "elevator.h"
#include "action.h"


int main() {
	// se co chay timer.

	/*                                                       planner
	                            							   | |
	        sendRequest                      sendAction        | |     sendError
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

	return 0;
}
