#include <iostream>


using Temperatura=float;
using Peso=float;
const int TAM=3;
using VetorStr=std::string[TAM];

void print(VetorStr nomes, int TAM){

	for (int i=0;i<TAM;i++){
		std::cout<<nomes[i]<<" ";
	}

}

int main(){
	Temperatura temp=37.5f;
	Peso peso=23.45f;

	VetorStr nome={"Leandro","Júnior","Cândido"};

	std::cout<<temp<<" "<<peso<<" \n";

	print(nome,TAM);

	return 0;
}

