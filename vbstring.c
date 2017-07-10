/* File: vbstring.c */
#include <stdio.h>
#include "cutils.h"
#include "vbstring.h"


/* Declaration Section
 *-------------------------------------------------------------------
 */


/* Public (extern) Functions  Section
 *-------------------------------------------------------------------
 */
int init_vbstring(char *src, size_t size)
{
	if (src == NULL || size < 2)
	{
		return 0;
	}
	init_string(src, size, ' ');
	return 1;
}

//   0   1   2   3    4
//  [1] [2] [3] [0] [E]
int ToCStyleArray(char *src, const size_t size)
{
	size_t i;
	if (src == NULL)
	{
		return 0;
	}
	i = (size-2);
	while (1)
	{
		if (src[i] != ' ')
		{
			break;
		}
		src[i] = '\0';
		if (i == 0)
		{
			break;
		}
		i--;
	} 
	
	return 1;
}

int ToVBStyleString(char *src, const size_t size)
{
	size_t firstzero, i;
	int ret;
	ret = findfirstzero(src, size, &firstzero);
	printf("first zero = %u (return code: %d)\n", firstzero, ret);
	for (i = firstzero; i < (size-1); i++)
	{
		src[i] = ' ';
	}
	return 1;
}

char *copy_vbstring(char *dest, const size_t size, const char *src)
{
	size_t i, j;

	if (dest == NULL || src == NULL || size < 2)
	{
		return NULL;
	}
	for (i = 0, j = 0; i < (size - 1); i++)
	{
		if (src[j] != '\0')
		{
			dest[i] = src[j];
			j++;
			continue;
		}
		dest[i] = ' ';
	}
	dest[size-1] = '\0';
	return dest;
}

extern char *append_vbstring(char *dest, const size_t size, const char *src)
{
	size_t i, j, pos;

	if (src == NULL || dest == NULL || size < 2)
	{
		return NULL;
	}
	if (findfirstspace(dest, size, &pos) != 1)
	{
		return NULL;
	}
	printf("pos: %u\n", pos);
	for (i = pos, j = 0; i < (size - 1); i++, j++)
	{
		if (src[j] == '\0') // end of string
		{
			break;
		}
		dest[i] = src[j];
		
	}
	return dest;
}


/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */

