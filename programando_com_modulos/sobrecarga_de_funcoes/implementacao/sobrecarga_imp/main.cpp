#include <iostream>
#include "Vetor.h"

using namespace std;

int main()
{
    Vetor v1, v2(3, 4), v3(-1, 10), v4;
    float result;
    int k = 2;

    result = v2.produto(v3);

    v2.getInfo();
    cout << "*";
    v3.getInfo();
    cout << " = " << result << endl;

    v4 = v2.produto(k);
    v2.getInfo();
    cout << "*" << k << " = ";
    v4.getInfo();
    cout << endl;

    return 0;
}
