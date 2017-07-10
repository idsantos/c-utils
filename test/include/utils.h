/* File: utils.h */
#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

struct args {
	char *cmd;
	char *func;
};

	extern struct args *createargs(const char *cmd, const char *func);
	extern void freeargs(struct args *args);
	extern void printtestmsg(const char *msg);
	extern void printstr(const char *src, const size_t size, const char *name);
	extern char *tolowchar(char *src);
	extern char *toupperchar(char *src);


#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

