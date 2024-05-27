#include <iostream>
#include "vetor_2d.h"

using namespace std;

int main()
{
    vetor_2d v1;

    v1.setY(45);
    v1.setX(8);

    cout << "vetor = (" << v1.getX() << "," << v1.getY() << ")" << endl;
    return 0;
}
