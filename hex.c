/* File: hex.c */
#include <stdlib.h>
#include <time.h>



/* Declaration Section
 *-------------------------------------------------------------------
 */
static const char lhex[] = "0123456789abcdef";
static const char uhex[] = "0123456789ABCDEF";

static int bSeeded = 0;

/* Public (extern) Functions  Section
 *-------------------------------------------------------------------
 */
char get_hexchar(const int value, const int charcase)
{
	if (value < 0 || value > 15)
	{
		return '-';
	}
	if (value >= 0 && value < 10)
	{
		return lhex[value];
	}
	
	/* 0 (default): a, b, c, d, c, f
	 * < 0 or > 0 : A, B, C, D, E, F
	 */
	if (charcase == 0)
	{
		return lhex[value];
	}
	return uhex[value];
}

char *CreateHexString(char *src, const size_t size, const int charcase)
{
	size_t i;
	if (src == NULL || size == 0)
	{
		return NULL;
	}
	if (bSeeded == 0)
	{
		bSeeded = 1;
		srand(time(NULL));
	}

	for (i = 0; i < size; i++)
	{
		src[i] = get_hexchar(rand() % 16, charcase);
	}
	if (size > 1)
	{
		src[size-1] = '\0';
	}
	return src;
}

/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */

