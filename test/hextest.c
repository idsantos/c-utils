/* File: hextest.c */
#include <stdio.h>
#include <string.h>
#include "modtest.h"
#include "modules.h"

#include "hex.h"


/* Declaration Section
 *-------------------------------------------------------------------
 */
#define STRSIZE 32

static void testhexstring(void);
static void testhexchar(void);


const struct modfunc hextest[] = {
   	{"hexchar", "get_hexchar", testhexchar},
	{"hexstring", "CreateHexString", testhexstring},
   	{NULL, NULL, NULL}
};

void testhexchar()
{
	int i, j;
	puts("charcase values:\n - lower case: 0\n - upper case: all other values");
	for (i = -1; i < 2; i++)
	{
		printf(" - using charcase value of %d\n", i);
		for (j = -1; j <= 16; j++)
		{
			printf("value: %d - char: %c\n", j, get_hexchar(j, i));
		}
	}
	puts(" completed testing get_hexchar()");
}

void testhexstring()
{
	char str[STRSIZE];
	int i, j;
	int size;

	if (STRSIZE < 24)
	{
		puts("STRSIZE is less than 24, This test is designed for a string size of 24 characters!, exiting ...");
		return;
	}
	memset(str, 0, sizeof(str[0])*STRSIZE);

	size = 8;
	puts("\n - testing with string size of 1");
	for (i = -1; i < 2; i++)
	{
		printf("- using %s char case (%d)\n", (i == 0)?"lower":"upper", i);
		CreateHexString(str, 1, i);
		printf("str: (%c) ", str[0]);
		for (j = 0; j < size; j++)
		{
			printf("%X ", (unsigned int)str[j]);
		}
		putchar('\n');
	}
	size = 16;
	printf("\n - testing with string size of %u\n", size);
	for (i = -1; i < 2; i++)
	{
		printf("- using %s char case (%d)\n", (i == 0)?"lower":"upper", i);
		CreateHexString(str, size, i);
		printf("str: (%s) ", str);
		for (j = 0; j < size+8; j++)
		{
			printf("%X ", (unsigned int)str[j]);
		}
		putchar('\n');
	}
		
	
}




