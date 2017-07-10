/* File: vbstrtest.c */
#include <stdio.h>
#include <string.h>
#include "modtest.h"
#include "modules.h"

#include "vbstring.h"


/* Declaration Section
 *-------------------------------------------------------------------
 */
#define STR_SIZE 32

static char str[STR_SIZE];

void initvbstrtest(void);
void tocstrtest(void);
void tovbstrtest(void);
void copyvbstrtest(void);
void appendvbstrtest(void);


const struct modfunc vbstringtest[] = {
	{"initvbstr", "init_vbstring", initvbstrtest},
   	{"tocstr", "ToCStyleArray", tocstrtest},
	{"tovbstr", "ToVBStyleString", tovbstrtest},
	{"copyvbstr", "copy_vbstring", copyvbstrtest},
	{"appendvbstr", "append_vbstring", appendvbstrtest},
   	{NULL, NULL, NULL}
};


void initvbstrtest(void)
{
	int ret;
	puts("init vbstring test");
	memset(str, 0, STR_SIZE);
	printstr(str, STR_SIZE, "str (memset initalized)");
	puts("testing with a null pointer");
	ret = init_vbstring(NULL, STR_SIZE);
	printf("return value is %d\n", ret);
	puts("testing with zero size");
	ret = init_vbstring(str, 0);
	printf("return value is %d\n", ret);
	printstr(str, STR_SIZE, NULL);
	puts("testing with valid data");
	ret = init_vbstring(str, STR_SIZE);
	printf("return is %d\n", ret);
	printstr(str, STR_SIZE, "\nstr: (init_vbstring initialized)");
}

void tocstrtest()
{	
	puts("testing function ToCStyleArray()");
	memset(str, ' ', STR_SIZE);
	str[STR_SIZE-1] = '\0';
	//memcpy(str, "testing", strlen("testing"));
	printf("str: [%s]\n", str);
	printstr(str, STR_SIZE, NULL);

	ToCStyleArray(str, STR_SIZE);
	printf("str: [%s]\n", str);
	printstr(str, STR_SIZE, NULL);
}

void tovbstrtest()
{
	printf("testing function %s()\n", vbstringtest[2].name);
	memset(str, 0, STR_SIZE);
	//strcpy(str, "testing ...");
	memset(str, '_', (STR_SIZE-1));
	ToVBStyleString(str, STR_SIZE);
	printf("str: [%s]\n", str);
	printstr(str, STR_SIZE, NULL);
}

void copyvbstrtest()
{
	char *pstr;
	puts("testing function copy_vbstring()");
	memset(str, 0, STR_SIZE);
	pstr = copy_vbstring(str, STR_SIZE, "testing ...");
	printf("str: [%s] (%p)\n", str, pstr);
	printstr(str, STR_SIZE, NULL);
}

void appendvbstrtest()
{
	char *pstr;
	const char originalstr[] = "original.";
	const char teststr[] = "(string.)";
	puts("testing function append_vbstring()");
	memset(str, ' ', (STR_SIZE - 1));
	str[STR_SIZE-1] = '\0';
	memcpy(str, originalstr, sizeof(originalstr));
	str[sizeof(originalstr)-1] = ' ';
	printstr(str, STR_SIZE, "teststr:");
	pstr = append_vbstring(str, STR_SIZE, teststr);
	printf("return value: %p\n", pstr);
	printf("str: [%s]\n", str);
	printstr(str, STR_SIZE, NULL);
}
