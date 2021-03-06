/*-------------------------------------------------------------------------
 *
 * dynloader.c--
 *    dynamic loader for HP-UX using the shared library mechanism
 *
 * Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *    $Header: /usr/local/cvsroot/postgres95/src/backend/port/hpux/dynloader.c,v 1.1.1.1 1996/07/09 06:21:43 scrappy Exp $
 *
 *  NOTES
 *	all functions are defined here -- it's impossible to trace the 
 *	shl_* routines from the bundled HP-UX debugger.
 *
 *-------------------------------------------------------------------------
 */
/* System includes */
#include <stdio.h>
#include <a.out.h>
#include <dl.h>
#include "c.h"
#include "fmgr.h"
#include "utils/dynamic_loader.h"
#include "port-protos.h"

void *
pg_dlopen(char *filename)
{
    shl_t handle = shl_load(filename, BIND_DEFERRED, 0);

    return((void *) handle);
}

func_ptr
pg_dlsym(void *handle, char *funcname)
{
    func_ptr f;

    if (shl_findsym((shl_t *) &handle, funcname, TYPE_PROCEDURE, &f) == -1) {
	f = (func_ptr) NULL;
    }
    return(f);
}

void
pg_dlclose(void *handle)
{
    shl_unload((shl_t) handle);
}

char *
pg_dlerror()
{
    static char errmsg[]= "shl_load failed";
    return errmsg;
}
