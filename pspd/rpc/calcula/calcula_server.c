/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcula.h"
#include <stdio.h>

int * add_100_svc(operandos *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */
	result = argp->x + argp->y;

	printf("oerandos: %d + %d = %d\n", argp->x, argp->y, result);

	return &result;
}

int * sub_100_svc(operandos *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	result = argp->x - argp->y;
	printf("oerandos: %d - %d = %d\n", argp->x, argp->y, result);

	return &result;
}