/* File: cutilstest.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "modtest.h"
#include "modules.h"
#include "cutils.h"

/* Declaration Section
 *-------------------------------------------------------------------
 */
#define STRSIZE 32

static char str[STRSIZE];

static void testhitenter(void);
static void testgetstr(void);
static void testgetnumber(void);
static void testgenlong(void);
static void testinitstr(void);
static void testcopystr(void);
static void testfindfirstzero(void);
static void testfindfirstspace(void);
static void testappendstr(void);
static void testinitparray(void);
static void testcopyparray(void);

void setparray(void **src, size_t size, void *value);



const struct modfunc cutilstest[] = {
	{"hitenter", "HitEnter", testhitenter},
	{"getstr", "get_input", testgetstr},
	{"getnum", "get_number", testgetnumber},
	{"genlong", "GenerateLong", testgenlong},
	{"initstr", "init_string", testinitstr},
	{"copystr", "copy_cstring", testcopystr},
	{"ffzero", "findfirstzero", testfindfirstzero},
	{"ffspace", "findfirstspace", testfindfirstspace},
	{"appendstr", "append_cstring", testappendstr},
	{"initparr", "init_parray", testinitparray},
	{"copyparr", "copy_parray", testcopyparray},
	{NULL, NULL, NULL}
};


/* Public (extern) Functions Section
 *-------------------------------------------------------------------
 */



/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */
void testhitenter(void)
{
	puts("testing HitEnter() function");
	printf("testing with empty string (no text - hit enter key to proceed\n");
	HitEnter(NULL);
	printf("testing with string \'Hit enter to continue! \'\n");
	HitEnter("Hit enter to continue! ");
}


void testgetstr()
{
	int ret;
	puts("testing get_input() function");
	
	memset(str, 0, sizeof(str));

	puts("testing with null pointer");
	ret = get_input(NULL, STRSIZE);
	printf("ret is %d\n", ret);
	printstr(str, STRSIZE, NULL);

	puts("testing with size of zero");
	ret = get_input(str, 0);
	printf("ret is %d\n", ret);
	printstr(str, STRSIZE, NULL);

	puts("testing with size of one");
	printf("input: ");
	ret = get_input(str, 1);
	printf("ret is %d\n", ret);
	printstr(str, STRSIZE, NULL);
	
	puts("testing with size of sixteen");
	printf("input: ");
	ret = get_input(str, 16);
	printf("ret is %d\n", ret);
	printstr(str, STRSIZE, NULL);
}

void testgetnumber()
{
	int ret;
	int value;
	puts("testing get_number() function");
	printf("input: ");
	ret = get_number(&value);
	printf("Is a valid number: %d\n", ret);
	printf("number is: %d\n", value);


}

void testgenlong()
{
	long num;
	int i;
	puts("testing GenerateLong() function");
	// TODO: defined what the values should be.
	// ----------------------------------------
	//
	for (i = 0; i < 5; i++)
	{
		num = GenerateLong();
		printf("number: %ld\n", num);
	}
}

void testinitstr()
{
	puts("testing function init_striing()");
	memset(str, '/', STRSIZE);
	printf("testing with memset using '/' (0x%X) as chracter\n", (unsigned int)'/');
	printstr(str, STRSIZE, NULL);
	
	if (init_string(str, STRSIZE, '-') != 1)
	{
		puts("init_string failed");
		return;
	}
	printf("testing with init_string using '-' (x%X) as character\n", (unsigned int)'-');
	printstr(str, STRSIZE, NULL);

}

void testcopystr()
{
	const char shortstr[] = "short string";
	const char longstr[] = "This is a very long string, should be longer than str[STRSIZE]";

	puts("testing function copy_cstring()");
	memset(str, '-', STRSIZE);
	
	puts("copying a short string");
	if (copy_cstring(str, STRSIZE, shortstr) != 1)
	{
		puts("copy_cstring failed\n");
		return;
	}
	printstr(str, STRSIZE, NULL);
	memset(str, '-', STRSIZE);

	puts("copying using a long string");
	copy_cstring(str, STRSIZE, longstr);
	printstr(str, STRSIZE, NULL);
}

void testfindfirstzero()
{
	size_t first;
	int ret;
	puts("testing function findfirstzero()");
	memset(str, 0, STRSIZE);
	strcpy(str, "123");
	
	puts("test string: '123\\0'"); 
	ret = findfirstzero(str, STRSIZE, &first);
	if (ret == 0)
	{
		puts("findfirstzero returned false");
		return;
	}
	printf("position of first zero: %u\n", first);
}

void testfindfirstspace()
{
	size_t pos;
	const char teststr[] = "test\0        ";
	puts("testing function findfirstspace()");
	if (findfirstspace(teststr, sizeof(teststr), &pos) != 1)
	{
		puts("findfirstspace returned 0");
		return;
	}
	printf("first space is located at position %u.\n", pos);
	printf("     [0123456789012345]\n");
	printf("str: [%s]\n", teststr);
}
void testappendstr()
{
	const char teststr[] = "testing";
	const char appendstr[] = " append string";
	puts("testing function append_cstring()");

	printf("copying \'%s\' to string array\n", teststr);
	strcpy(str, teststr);
	printstr(str, STRSIZE, NULL);

	printf("appending \'%s\' to test string\n", appendstr);
	if (append_cstring(str, STRSIZE, appendstr) != 1)
	{
		puts("append_cstring failed");
		return;
	}
	printf("str: %s\n", str);
	printstr(str, STRSIZE, NULL);
}

void testinitparray()
{
	char **pstr;
	const size_t psize = 16;
	puts("testing function init_parray()");

	pstr = malloc(sizeof(*pstr)*psize);
	if (pstr == NULL)
	{
		return;
	}

	puts("setting pointer array elements to '0x0a0b0c0d' using a loop");
	setparray((void **)pstr, psize, (void *)0x0a0b0c0d);

	printstr((void *)pstr, sizeof(*pstr)*psize, NULL);

	puts("\nsetting pointer array elements to '0xef' using memset");
	memset((void *)pstr, 0xef, sizeof(*pstr)*psize);
	printstr((void *)pstr, sizeof(*pstr)*psize, NULL);
}

void testcopyparray()
{
	char **pstr1, **pstr2;
	const size_t psize = 16;

	puts("testing function copy_parray()");
	
	puts("allokating memory to pstr1 and pstr2 array");
	pstr1 = malloc(sizeof(*pstr1)*psize);
	pstr2 = malloc(sizeof(*pstr2)*psize);
	if (pstr1 == NULL || pstr2 == NULL)
	{
		return;
	}
	puts("setting pstr1 array to NULL");
	setparray((void **)pstr1, psize, (void *)0);

	printf("setting pstr2 array to '0x0a0b0c0c' using %u elements\n", psize/2);
	setparray((void **)pstr2, psize, (void *)0);
	setparray((void **)pstr2, (psize/2), (void *)0x0a0b0c0d);
	
	printstr((void *)pstr1, sizeof(*pstr1)*psize, "pstr1:");

	printstr((void *)pstr2, sizeof(*pstr2)*psize, "pstr2:");
	
	copy_parray((void **)pstr1, psize, (const void **)pstr2);
	puts("result after copy_parray():");
	printstr((const char *)pstr1, sizeof(*pstr1)*psize, "pstr1:");

}




void setparray(void **src, size_t size, void *value)
{
	size_t i;
	for (i = 0; i < size; i++)
	{
		src[i] = value;
	}
}

