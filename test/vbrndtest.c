/* File: vbrndtest.c */
#include <stdio.h>
#include "modtest.h"
#include "modules.h"

#include "vbrnd.h"


/* Declaration Section
 *-------------------------------------------------------------------
 */
static void testrnd(void);
static void testrand(void);
void testrndloop(const int times, int seed);

const struct modfunc vbrndtest[] = {{"rnd", "Rnd",  testrnd}, {"rand", "Randomize", testrand}, {NULL, NULL, NULL}};

/* Public (extern) Functions Section
 *-------------------------------------------------------------------
 */

/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */
void testrnd()
{
    puts("Testing Rnd() function");

    puts("\ntesting with negativee number (-10)");
    testrndloop(3, -10);

    Randomize(0x50000L);
    Rnd(1);
    puts("\ntesting with 0 as seed");
    testrndloop(3, 0);

    Randomize(0x50000L);
    puts("\ntesting with positive number (1)");
    testrndloop(8, 1);

}

void testrand()
{
    unsigned long uval;
    puts("Testing Randomize() function");
    uval = 0x50000L;
    printf("testing with value of %lu (0x%lX)\n", uval, uval);
    Randomize(uval);
    testrndloop(4, 1);
}

void testrndloop(const int times, int seed)
{
    int i;
    for (i = 0; i < times; i++)
    {
        printf("Rnd(%d) = %.7f\n", seed, Rnd(seed));
    }
}
