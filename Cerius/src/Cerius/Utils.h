#if !defined(_INC_UTILS)
#define _INC_UTILS
#if !defined(_INC_STDIO)
#include <stdio.h>
#endif
#if !defined(_INC_STDLIB)
#include <stdlib.h>
#endif
#if !defined(_INC_STRING)
#include <string.h>
#endif
#if !defined(_STDBOOL)
#include <stdbool.h>
#endif
#define new(type) malloc(sizeof(type))
#define copy(dst, src) memcpy(dst, src, sizeof(src))
#define delete(ptr) free(ptr)
#endif