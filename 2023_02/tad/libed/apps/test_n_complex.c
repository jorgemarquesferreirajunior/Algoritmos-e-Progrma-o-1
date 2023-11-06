#include "n_complex.h"
#include <stdio.h>

int main() {
    ComplexNum *z1 = createComplexNumber(3.0, 4.0);
    ComplexNum *z2 = createComplexNumber(-1.0, -2.0);
    printf_all_ComplexNum(z1);
    printf_all_ComplexNum(z2);

    ComplexNum *sum = sumComplexNumbers(z1, z2);
    printf_sum_ComplexNum(z1, z2, sum);
    ComplexNum *difference = subtractComplexNumbers(z1, z2);
    printf_subtract_ComplexNum(z1, z2, difference);
    ComplexNum *product = multiplyComplexNumbers(z1, z2);
    printf_multiply_ComplexNum(z1, z2, product);
    ComplexNum *quotient = divideComplexNumbers(z1, z2);
    printf_divide_ComplexNum(z1, z2, quotient);

    destroyComplexNumber(&z1);
    destroyComplexNumber(&z2);
    destroyComplexNumber(&sum);
    destroyComplexNumber(&difference);
    destroyComplexNumber(&product);
    destroyComplexNumber(&quotient);

    return 0;
}