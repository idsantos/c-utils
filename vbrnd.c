/* File: vbrnd.c */
#include <stdio.h>
#include <time.h>
#include "vbrnd.h"

/* Declaration Section
 *-------------------------------------------------------------------
 */
// Multiplication / division / remainder first adding/subtracting second
// x1 = ( x0 * a + c ) MOD (2^24);
/* [ INFO: How Visual Basic Generates Pseudo-Random Numbers for the RND Function ]
 * See Microsoft KB article kb231847
 *-----------------------------------------------------------------------------
 */
static unsigned long rndval = 0x50000L;


static unsigned long getrnd(unsigned long val);


/* Public (extern) Functions Section
 *-------------------------------------------------------------------
 */
float Rnd(float seed)
{
    float rndFloat;
        
    // rndval = (rndval * 0x43fd43fd + 0xc39ec3) & 0xffffff
    if (seed < 0)
    {
        rndval = getrnd((unsigned long)seed);
    }
    else if (seed > 0)
    {
        rndval = getrnd(rndval);
    }
    rndFloat = ((float)rndval / 16777216.0);
    return rndFloat;
}


void Randomize(unsigned long seed)
{
    if (seed == 0)
    {
        rndval = time(NULL);
        return;
    }
    rndval = seed;
}


/* Private (static) Functions Section
 *-------------------------------------------------------------------
 */
unsigned long getrnd(unsigned long val)
{
    return (val * 0x43fd43fdL + 0xc39ec3L) & 0xffffffL;
}


