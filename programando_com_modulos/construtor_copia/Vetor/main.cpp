#include <iostream>
#include "vetor.h"

using namespace std;

int main(){
  Vetor v1(3,4), v2(5,6), v3;
  Vetor v4=v1;
  Vetor v5(v2);
  v3 = v1.soma(v2);
  v1.print();
  v2.print();
  v3.print();
  return 0;
}
