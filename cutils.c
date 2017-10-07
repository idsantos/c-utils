/* File: cutils.c */
#include <stdio.h>
#include "cutils.h"
#include "vbrnd.h"


/* Declaration Section
 *-------------------------------------------------------------------
 */



/* Public (extern) Functions Section
 *-------------------------------------------------------------------
 */
 
void HitEnter(const char *msg)
{
	int ch;
	printf("%s", (msg == NULL)?"":msg);
	while ((ch = getchar()) != '\n' && ch != EOF)
		; // Do nothing except waiting for enter key or EOF marker
}

int get_input(char *src, const size_t size)
{
	int ch;
	size_t pos;
	if (src == NULL || size == 0)
	{
		return 0;
	}

	pos = 0;
	while ((ch = getchar()) != '\n' && ch != EOF )
	{
		if (pos < size)
		{
			src[pos] = ch;
			pos++;
		}
	}
	if (pos > 0 && size > 1)
	{
		if (pos == size)
		{
			pos--;
		}
		src[pos] = '\0';
	}
	return pos;
}

int get_number(int *dest)
{
	int number, negative;
	int ret;
	int value;
	int i;
	int process;
	int ch;

	if (dest == NULL)
	{
		return 0;
	}
	ret = 1;
	ch = getchar();
	negative = 0;
	process = 1;
	if (ch == '-')
	{
		negative = 1;
		ch = getchar();
	}

	number = 0;
	while (ch != '\n' && ch != EOF)
	{
		if (ch >= '0' && ch  <= '9' && process != 0)
		{
			value = 0;
			for (i = 0; i < 10; i++)
			{
				value += number;
				if (value < number)
				{
					// overflow
					//printf("value is %d and number is %d\n", value, number);
					number = 0;
					process = 0;
					ret = 0;
					break;
				}
			}
			if (process > 0)
			{
				number = (number * 10) + (ch - '0');
				if (number < value)
				{
					// overflow

					//printf("number is %d\n", number);
					if ((number - 1) > 0 && negative != 0)
					{
						number = ((~number) + 1);
						//printf("number is now %d\n", number);
					}
					else
					{
						number = 0;
						ret = 0;
					}
					process = 0;

				}
			}
		}
		ch = getchar();
	}
	if (negative != 0 && number > 0)
	{
		number = ((~number) +1);
	}
	*dest = number;
	return ret;
}


long int GenerateLong()
{
	long int number;
	const long int lowerbound = 0L;
	const long int upperbound = 0x7ffffffeL;
	number = ((upperbound - lowerbound + 1) * Rnd(1) + lowerbound);
	return number;
}


int init_string(char *src, const size_t size, const char val)
{
	size_t i;
	
	if (src == NULL || size < 2)
	{
		return 0;
	}
	for (i = 0; i < (size-1); i++)
	{
		src[i] = val;
	}
	src[i] = '\0';
	return 1;
}


int copy_cstring(char *dest, const size_t size, const char *src)
{
	size_t i;
	if (dest == NULL || src == NULL || size < 2)
	{
		return 0;
	}
	for (i = 0; i < (size -1); i++)
	{
		if (src[i] == '\0')
		{
			break;
		}
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return 1;
}


int append_cstring(char *dest, const size_t size, const char *src)
{
	size_t i, j,  pos;
	if (dest == NULL || src == NULL || size < 2)
	{
		return 0;
	}

	if (findfirstzero(dest, size, &pos) != 1)
	{
		return 0;
	}

	printf("pos = %u\n", pos);
	for (i = pos, j = 0; i < (size-1); i++, j++)
	{
		if (src[j] == '\0')
		{
			break;
		}
		dest[i] = src[j];
	}
	return 1;
}

int findfirstzero(const char *src, const size_t size, size_t *retval)
{
	size_t i;
	if (src == NULL || size < 2)
	{
		return 0;
	}

	for (i = 0; i < size; i++)
	{
		//printf("[%c] ", (src[i] != 0)? src[i] : '0' );
		if (src[i] == '\0')
		{
			break;
		}
	}
	if (retval != NULL)
	{
		*retval = i;
	}
	//putchar('\n');
	return 1;
}
int findfirstspace(const char *src, const size_t size, size_t *retval)
{
	size_t i;
	if (src == NULL || size < 2)
	{
		return 0;
	}
	
	i = (size - 2);
	while(1)
	{
		if (src[i] != ' ')
		{
			break;
		}
		if (i == 0)
		{
			break;
		}
		i--;
	}
	if (retval != NULL)
	{
		i++;
		*retval = i;
	}
	return 1;
}

void init_parray(void **src, const size_t size)
{
	size_t i;
	if (src == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		src[i] = NULL;
	}
}

void copy_parray(void **dest, const size_t size, const void **src)
{
	size_t i;
	if (dest == NULL || src == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		dest[i] = (void *)src[i];
	}
}


void print_string(const char *src, const size_t size, const char *title)
{
	size_t i;
	if (src == NULL || size == 0)
	{
		return;
	}

	if (title != NULL)
	{
		puts(title);
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

/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */

