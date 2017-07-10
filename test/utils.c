/* utils.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>
#include "utils.h"

/* Declaration Section
 *-------------------------------------------------------------------
 */
static char *dupstr(const char *src);



/* Public (extern) Functions Section
 *-------------------------------------------------------------------
 */
struct args *createargs(const char *cmd, const char *func)
{
	struct args *new;
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		puts("memalloc error occurred");
		return NULL;
	}
	new->cmd = dupstr(cmd);
	new->func = dupstr(func);
	if (new->cmd == NULL)
	{
		freeargs(new);
		return NULL;
	}
	tolowchar(new->cmd);
	tolowchar(new->func);

	return new;

}

void freeargs(struct args *args)
{
	if (args == NULL)
	{
		return;
	}
	if (args->cmd != NULL)
	{
		free(args->cmd);
	}
	if (args->func != NULL)
	{
		free(args->func);
	}
	free(args);
}

void printtestmsg(const char *msg)
{
	if (msg == NULL)
	{
		return;
	}
	printf(" testing %s()\n", msg);
	puts("--------------------------------------------------------------\n");
}

void printstr(const char *src, const size_t size, const char *name)
{
	size_t i;
	if (name != NULL)
	{
		puts(name);
	}
	
	if (src == NULL || size == 0)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		if ((i % 16) == 0 && i > 0)
		{
			putchar('\n');
		}
		if ((i % 8) == 0)
		{
			putchar(' ');
		}
		if ((i % 4) == 0)
		{
			putchar(' ');
		}
		printf("%.2X ", (src[i] & 0xff)  );
	}
	putchar('\n');
}

char *tolowchar(char *src)
{
	char *pc;
	if (src == NULL)
	{
		return NULL;
	}
	pc = src;
	while (*pc != '\0')
	{
		*pc = tolower(*pc);
		pc++;
	}
	return src;
}

char *toupperchar(char *src)
{
	char *pc;
	if (src == NULL)
	{
		return NULL;
	}
	pc = src;
	while (*pc != '\0')
	{
		*pc = toupper(*pc);
		pc++;
	}
	return src;
}


/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */
char *dupstr(const char *src)
{
	size_t len, size;
	char *pc;

	if (src == NULL)
	{
		return NULL;
	}
	len = strlen(src);
	size = sizeof(*pc)*len;
	pc = malloc(size+1);	// +1 for the terminating zero
	if (pc == NULL)
	{
		puts("memallocation error occurred");
		return NULL;
	}
	memset(pc, 0, size+1);	// +1 for the terminating zero
	strncpy(pc, src, len);	// best practice, don't include the '\0'

	return pc;
}

