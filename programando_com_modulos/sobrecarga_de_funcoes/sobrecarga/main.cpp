#include <iostream>

using namespace std;

int imprime(int x)
{
    std::cout << x << std::endl;
}

int imprime(float x)
{
    std::cout << x << std::endl;
}

int imprime(double x)
{
    std::cout << x << std::endl;
}

int imprime(char *x)
{
    std::cout << x << std::endl;
}

int main()
{
    int a = 1;
    float b = 2;
    double c = 3;
    char *d = "jorge";

    imprime(a);
    imprime(b);
    imprime(c);
    imprime(d);

    return 0;
}
