/* File: template.c */
#include <stdio.h>
#include "modtest.h"
#include "modules.h"

/* TODO: add additional header files here */


/* Declaration Section
 *-------------------------------------------------------------------
 */

static void testfunc(void);


const struct modfunc templtest[] = {
   	{"func", "<function name>", testfunc},
   	{NULL, NULL, NULL}
};


void testfunc()
{
	puts(" -> testing function <function name>() <-\n");
}

