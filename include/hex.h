/* File: hex.h */
#ifndef HEX_H
#define HEX_H

#ifdef __cplusplus
extern "C" {
#endif

	extern char get_hexchar(const int value, const int charcase);
	extern char *CreateHexString(char *src, const size_t size, const int charcase);

#ifdef __cplusplus
}
#endif

#endif /* HEX_H */
