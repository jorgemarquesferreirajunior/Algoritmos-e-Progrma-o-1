#include <iostream>
#include "Vetor.h"

using namespace std;

int main()
{
    Vetor v1;
    Vetor v2;
    Vetor v3(9,15);
    Vetor v4(7); // (7,0)
    cout << "v1.x = " << v1.getX() << endl;
    cout << "v1.y = " << v1.getY() << endl;

    v1.setX(3);v2.setY(4);
    v2.setX(5);v2.setY(6);


    //cout << "Hello world!" << endl;
    return 0;
}
