/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "chained.h"

bool_t
xdr_lista (XDR *xdrs, lista *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->value))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nxt, sizeof (lista), (xdrproc_t) xdr_lista))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Lista (XDR *xdrs, Lista *objp)
{
	register int32_t *buf;

	 if (!xdr_lista (xdrs, objp))
		 return FALSE;
	return TRUE;
}
