/* File: cutils.h */
#ifndef CUTILS_H
#define CUTILS_H

#ifdef __cplusplus
extern "C" {
#endif
	extern void HitEnter(const char *msg);
	extern int get_input(char *src, const size_t size);
	extern int get_number(int *dest);
	extern long int GenerateLong(void);
	extern int init_string(char *str, const size_t size, const char val);
	extern int copy_cstring(char *dest, const size_t size, const char *src);
	extern int append_cstring(char *dest, const size_t size, const char *src);
	extern int findfirstzero(const char *src, const size_t size, size_t *retval);
	extern int findfirstspace(const char *src, const size_t size, size_t *retval);
	extern void init_parray(void **src, const size_t size);
	extern void copy_parray(void **dest, const size_t size, const void**src);
	extern void print_string(const char *src, const size_t size, const char *title);


#ifdef __cplusplus
}
#endif

#endif /* CUTILS_H */

