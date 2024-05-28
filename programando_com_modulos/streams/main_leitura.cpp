#include<fstream>
#include<cstdlib>
#include<iostream>

using namespace std;

int main(){

	string conteudo;
	ifstream fin;
	fin.open("nomes.txt");
	if(!fin.is_open()) exit(0);
	fin >> conteudo;
	fin.close();

	cout << "conteudo: " << conteudo << endl;
	return 0;
}
