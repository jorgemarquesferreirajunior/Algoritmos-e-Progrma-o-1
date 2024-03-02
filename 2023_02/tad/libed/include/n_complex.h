#ifndef N_COMPLEX_H
#define n_COMPLEX_H

typedef struct _n_complex ComplexNum;

ComplexNum *createComplexNumber(double real, double imag);
void destroyComplexNumber(ComplexNum **number);
void printf_all_ComplexNum(const ComplexNum * number);
void printf_sum_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum);
void printf_subtract_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum);
void printf_multiply_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum);
void printf_divide_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum);
ComplexNum *sumComplexNumbers(const ComplexNum *num1, const ComplexNum *num2);
ComplexNum *subtractComplexNumbers(const ComplexNum *num1, const ComplexNum *num2);
ComplexNum *multiplyComplexNumbers(const ComplexNum *num1, const ComplexNum *num2);
ComplexNum *divideComplexNumbers(const ComplexNum *num1, const ComplexNum *num2);

#endif