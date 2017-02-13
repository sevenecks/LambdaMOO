/******************************************************************************

     Martian's MOO Extension Pack

  Copyright 1996, 1997, 1998, 2000 Midgard Systems and Adam "Martian" Smyth

  Permission is granted to freely distribute and use this file for any
  non-commercial application. Commercial and Government users may also use
  it freely, but must inform the author prior to use.
  Permission is granted to change this file to suit a particular application,
  so long as a copy of the changes is provided to the original author.

  If you use this, lemme know. If you think it sucks, lemme know.
  If you want something changed, lemme know. If something doesn't
  work, lemme know.

  The latest version of this file is available at
    http://www.martian.at/Code/MOO/extensions/ext-martian.c

  Martian
  martian@midgard.org
 *****************************************************************************/

#include "bf_register.h"
#include "functions.h"
#include "my-unistd.h"

#include "exceptions.h"
#include "log.h"
#include "net_multi.h"
#include "storage.h"
#include "tasks.h"
#include "utils.h"
#include "db.h"
#include "list.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my-string.h"
#include "my-stdlib.h"
#include "db.h"
#include "db_private.h"
#include "numbers.h"
#include "random.h"
#include "structures.h"
#include "log.h"

#include "time_percise.h"

/* BASED ON bf_us_time from ext-martian.c - which is why the copyright is here :) */
static package
bf_time_percise(Var arglist, Byte next, void *vdata, Objid progr) {
        Var r;
        struct timeval *tv = (struct timeval *)malloc(sizeof(struct timeval));
        struct timezone *tz=0;

        gettimeofday(tv,tz);

        r=new_float( ( (double)tv->tv_sec) + ( (double)tv->tv_usec / 1000000 ) );

        free(tv);
        free_var(arglist);
        return make_var_pack(r);
}

void
register_timepercise(void)
{
#if EXT_TIME_PERCISE

  register_function("time_percise", 0, 0, bf_time_percise);

#endif
}
