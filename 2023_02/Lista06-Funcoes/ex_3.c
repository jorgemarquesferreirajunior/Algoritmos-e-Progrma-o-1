#include <stdio.h>
#include <math.h>

int main() {
    double x = 4.0;
    double y = 2.0;

    double sqrt_result = sqrt(x);
    double pow_result = pow(x, y);
    double sin_result = sin(x);
    double cos_result = cos(x);
    double tan_result = tan(x);
    double log_result = log(x);
    double exp_result = exp(x);

    printf("Raiz quadrada de %.2f: %.2f\n", x, sqrt_result);
    printf("%.2f elevado a %.2f: %.2f\n", x, y, pow_result);
    printf("Seno de %.2f: %.2f\n", x, sin_result);
    printf("Cosseno de %.2f: %.2f\n", x, cos_result);
    printf("Tangente de %.2f: %.2f\n", x, tan_result);
    printf("Logaritmo natural de %.2f: %.2f\n", x, log_result);
    printf("Exponencial de %.2f: %.2f\n", x, exp_result);

    return 0;
}
