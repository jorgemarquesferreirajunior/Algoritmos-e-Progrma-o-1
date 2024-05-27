#include <iostream>
#include "Vetor.h"

using namespace std;

int main()
{
    Vetor v1(3,4), v2;

    v2 = 4 * v1;

    v1.getInfo();
    cout << endl;

    v2.getInfo();
    cout << endl;

    v2 = operator*(4, v1);

    v1.getInfo();
    cout << endl;

    v2.getInfo();
    cout << endl;

    cout << "-----------------------------------" << endl;
    v2 = 4 + v1;

    v1.getInfo();
    cout << endl;

    v2.getInfo();
    cout << endl;

    v2 = operator+(4, v1);

    v1.getInfo();
    cout << endl;

    v2.getInfo();
    cout << endl;
    cout << "-----------------------------------" << endl;
    v2 = 4 - v1;

    v1.getInfo();
    cout << endl;

    v2.getInfo();
    cout << endl;

    v2 = operator-(4, v1);

    v1.getInfo();
    cout << endl;

    v2.getInfo();
    cout << endl;
    return 0;
}
