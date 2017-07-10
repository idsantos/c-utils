/* File: vbrnd.h */
#ifndef RND_H
#define RND_H

#ifdef __cplusplus
extern "C" {
#endif

	extern float Rnd(float seed);
	
	extern void Randomize(unsigned long seed);

#ifdef __cplusplus
}
#endif

#endif /* RND_H */

