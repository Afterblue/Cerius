#if !defined(_INC_MATRIX)
#define _INC_MATRIX
#if !defined(_INC_CORE_STRCTS)
#include "../Core-Structs.h"
#endif
#if !defined(_INC_ARRAY)
#include "Array.h"
#endif
typedef struct Matrix Matrix;
CERIUS_API Matrix* new_matrix();
CERIUS_API bool matrix_append_row(Matrix*);
CERIUS_API bool matrix_prepend_row(Matrix*);
CERIUS_API bool matrix_add_row(Matrix*, int);
#endif