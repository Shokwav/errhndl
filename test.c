/* This file has no copyright assigned and is placed in the Public Domain. */
#include <stdio.h>
#include <stdlib.h>
#include "errhndl.h"

enum { test_error = 1 };

int main(void){
	errinfo err;
	ERRTRY(err,
		ERRTHROW(err, test_error); /* Comment this out for no error */
		puts("No error");
	)ERRCATCH(err,
		printf("Caught error (type = %i)\n", GETERR(err));
	)

	ERRTHROW(err, test_error); /* Throwing outside of try block does nothing */

	return (EXIT_SUCCESS);
}
