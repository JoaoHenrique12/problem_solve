/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "chained.h"

#include <stdio.h>
#include <stdlib.h>


void print_list(Lista* l)
{
  while (l) {
    printf("%d ", l->value);
    l = l->nxt;
  }
  printf("\n");
}

int * somal_1_svc(Lista *argp, struct svc_req *rqstp)
{
	static int  result;
	result = 0;

	Lista* begin = (Lista*) malloc(sizeof(Lista));
	begin = argp;

	print_list(argp);
	argp = begin;
  while (argp) {
    result += argp->value;
    argp = argp->nxt;
  }
  printf("sum: %d\n", result);
	argp = begin;

	return &result;
}
