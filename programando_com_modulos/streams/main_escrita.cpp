#include<fstream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("nomes.txt");
	if(!fout.is_open()) exit(0);
	fout << "Nova linha adicionada com sucesso. \n";
	fout.close();

	return 0;
}
