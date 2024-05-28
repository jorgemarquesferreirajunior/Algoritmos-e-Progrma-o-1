#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(){

	char ch;
	ifstream arquivo_leitura;
	ofstream arquivo_escrita;

	arquivo_leitura.open("entrada.txt");
	arquivo_escrita.open("saida.txt");


	while(arquivo_leitura.get(ch))
	{
		arquivo_escrita.put(ch);
	}
	arquivo_leitura.close();
	arquivo_escrita.close();



	return 0;
}
