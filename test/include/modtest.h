/* File: modtest.h */
#ifndef MODTEST_H
#define MODTEST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils.h"

struct modfunc
{
	const char *func;
	const char *name;
	void (*f)(void);
};

struct modcmd
{
	const char *name;
	const struct modfunc *funclist;
};

	extern void printcmdlist(const struct modcmd *cmdlist);
	extern void printfunclist(const struct modfunc *funclist);
	extern void exectestcmds(const struct modcmd *cmdlist, struct args *args);
	extern void exectestfunc(const struct modfunc *funclist, const char *func);


#ifdef __cplusplus
}
#endif

#endif /* MODTEST_H */
