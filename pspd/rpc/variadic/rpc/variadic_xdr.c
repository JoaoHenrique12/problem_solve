/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "variadic.h"

bool_t
xdr_vetint (XDR *xdrs, vetint *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->vetint_val, (u_int *) &objp->vetint_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}
