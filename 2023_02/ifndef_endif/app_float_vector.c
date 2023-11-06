#include "float_vector.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FloatVector *vec = FloatVector_create(10);
    
    FloatVector_print_vec(vec);
    FloatVector_append(vec, 0.5);
    FloatVector_append(vec, 1.8);
    FloatVector_append(vec, 6);

    FloatVector_print_vec(vec);

    FloatVector_destroy(&vec);
    
    return 0;
}
