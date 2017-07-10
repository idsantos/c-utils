/* File: vbstring.h */
#ifndef VBSTRING_H
#define VBSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

	extern int init_vbstring(char *src, const size_t size);
	extern int ToCStyleArray(char *src, const size_t size);
	extern int ToVBStyleString(char *src, const size_t size);
	extern char *copy_vbstring(char *dest, const size_t size, const char *src);
	extern char *append_vbstring(char *dest, const size_t size, const char *src);

#ifdef __cplusplus
}
#endif

#endif /* VBSTRING_H */
