/* File: runtest.c */
#include <stdio.h>
#include <stdlib.h>

#include "modtest.h"
#include "modules.h"

/* Declaration Section
 *-------------------------------------------------------------------
 */
static const struct modcmd cmdlist[] = 
{
	{"hex", hextest},
	{"vbrnd", vbrndtest},
	{"cutils", cutilstest},
	{"vbstring", vbstringtest},
	{ NULL, NULL }
};


/* Application Entry Point
 *-------------------------------------------------------------------
 */
int main(int argc, char **argv)
{
	struct args *args;

	printf("Executing \'%s\'\n", argv[0]);
	if (argc < 2)
	{
		printf("usage: %s <cmd> [func]\n", argv[0]);
		printcmdlist(cmdlist);
		return 0;
	}
	args = createargs(argv[1], (argc > 2)? argv[2] : NULL );
	/*
	printf("cmd is [%s]\n", args->cmd);
	printf("func is [%s]\n", (args->func != NULL)? args->func : "");
	*/
	exectestcmds(cmdlist, args);	
	

	freeargs(args);
	return 0;
}

