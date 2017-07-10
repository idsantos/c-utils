/* modtest.c */
#include <stdio.h>
#include <string.h>
#include "modtest.h"

/* Declaration Section
 *-------------------------------------------------------------------
 */



/* Public (extern) Functions Section
 *-------------------------------------------------------------------
 */
void printcmdlist(const struct modcmd *cmdlist)
{
	const struct modcmd *item;
	if (cmdlist == NULL)
	{
		return;
	}
	item = cmdlist;
	puts("List of modules (cmds)");
	while (item->name != NULL)
	{
		printf(" -> %s\n", item->name);
		item++;
	}
}

void printfunclist(const struct modfunc *funclist)
{
	const struct modfunc *item;
	
	if (funclist == NULL)
	{
		return;
	}
	item = funclist;
	puts("List of functions (func)");
	while (item->func != NULL)
	{
		printf(" -> %s \t(%s())\n", item->func, item->name);
		item++;
	}
}

void exectestcmds(const struct modcmd *cmdlist, struct args *args)
{
	const struct modcmd *item;

	//puts("Executing: exectestcmds()");
	if (cmdlist == NULL || args == NULL)
	{
		return;
	}
	item = cmdlist;
	while (item->name != NULL)
	{
		//printf("cmd: %s\n", item->name);
		if (strcmp(item->name, args->cmd) == 0)
		{
			//printf("\nTesting module [%s]\n", item->name);
			exectestfunc(item->funclist, args->func);
			return;
		}
		item++;
	}
	/* found no match!, print list of modules so the user has a chance 
	 * to see which modules are avalable for testing */
	printcmdlist(cmdlist);
}


void exectestfunc(const struct modfunc *funclist, const char *func)
{
	const struct modfunc *item;
	//puts("Executing: exectestfunc()");
	
	if (func == NULL)
	{
		printfunclist(funclist);
		return;
	}
	item = funclist;
	while (item->func != NULL)
	{
		//printf("func: %s [ %s() ]\n", item->func, item->name);
		if (strcmp(item->func, func) == 0)
		{
			/* found a match */
			//printf("Testing function %s()\n", item->name);
			if (item->f != NULL)
			{
				item->f();
			}	
			return;
		}
		item++;
	}
	/* found no match!, print list of functions  so the user has a chance 
	 * to see which functions are avalable for testing */
	printfunclist(funclist);
}
/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */

