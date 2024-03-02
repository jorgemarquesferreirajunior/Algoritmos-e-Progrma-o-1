#include "n_complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _n_complex {
    double real;
    double imag;
} ComplexNum;

ComplexNum *createComplexNumber(double real, double imag) {
    ComplexNum *number = (ComplexNum *)calloc(1, sizeof(ComplexNum));
    number->real = real;
    number->imag = imag;

    return number;
}

void destroyComplexNumber(ComplexNum **number) {
    free(*number);
    *number = NULL;
}

void printf_all_ComplexNum(const ComplexNum * number){
    puts("showing parameteres of the Complex Number");
    printf("number->real = %.2f\n", number->real);
    printf("number->imag = %.2f\n\n", number->imag);
}
void printf_sum_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum){
    printf("Sum=      ");
    if (n1->imag >= 0){
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) + (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) + (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) + (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) + (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }else{
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) + (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) + (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) + (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) + (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }
    puts("");
}
void printf_subtract_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum){
    printf("Subtract= ");
    if (n1->imag >= 0){
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) - (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) - (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) - (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) - (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }else{
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) - (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) - (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) - (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) - (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }
    puts("");
}
void printf_multiply_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum){
    printf("Multiply= ");
    if (n1->imag >= 0){
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) * (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) * (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) * (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) * (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }else{
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) * (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) * (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) * (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) * (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }
    puts("");
}
void printf_divide_ComplexNum(const ComplexNum * n1, const ComplexNum * n2, const ComplexNum * sum){
    printf("Divide=   ");
    if (n1->imag >= 0){
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) / (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) / (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f + %.2fi) / (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f + %.2fi) / (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }else{
        if (n2->imag >= 0){
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) / (%.2f + %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) / (%.2f + %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }else{
            if (sum->imag >= 0){
                printf("(%.2f %.2fi) / (%.2f %.2fi) = (%.2f + %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }else{
                printf("(%.2f %.2fi) / (%.2f %.2fi) = (%.2f %.2fi)\n",
                    n1->real, n1->imag, n2->real, n2->imag, sum->real, sum->imag);
            }
        }
    }
    puts("");
    
}
ComplexNum *sumComplexNumbers(const ComplexNum *num1, const ComplexNum *num2) {
    double realSum = num1->real + num2->real;
    double imagSum = num1->imag + num2->imag;
    return createComplexNumber(realSum, imagSum);
}

ComplexNum *subtractComplexNumbers(const ComplexNum *num1, const ComplexNum *num2) {
    double realDiff = num1->real - num2->real;
    double imagDiff = num1->imag - num2->imag;
    return createComplexNumber(realDiff, imagDiff);
}

ComplexNum *multiplyComplexNumbers(const ComplexNum *num1, const ComplexNum *num2) {
    double realProd = num1->real * num2->real - num1->imag * num2->imag;
    double imagProd = num1->real * num2->imag + num1->imag * num2->real;
    return createComplexNumber(realProd, imagProd);
}

ComplexNum *divideComplexNumbers(const ComplexNum *num1, const ComplexNum *num2) {
    double denominator = num2->real * num2->real + num2->imag * num2->imag;
    double realQuot = (num1->real * num2->real + num1->imag * num2->imag) / denominator;
    double imagQuot = (num1->imag * num2->real - num1->real * num2->imag) / denominator;
    return createComplexNumber(realQuot, imagQuot);
}

