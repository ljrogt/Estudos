#include <iostream>

using NumeroDeCelular=std::string;
using Email=std::string;
using Nome=std::string;

struct Contato
{
	Nome nome;
	NumeroDeCelular numero;
	Email email;
};

void print(Contato contato)
{
	std::cout<<contato.nome<<" - "<<contato.numero<<" - "<<contato.email<<"\n";
}

void print(Contato cs[], int TAM){
	for (int i=0;i<TAM;i++){
		print(cs[i]);
	}
}

int main(){

	const int TAM=3;
	Contato cs[TAM]={{"Leandro Júnior","(92) 98425-8288","leandrojr28102006@gmail.com"},
				{"Sammya Brito", "(92) 98419-0585","syajuci@gmail.com"},
				{"Levi Cândido","(99) 99999-9999","levicdoli@gmail.com"}};



	print(cs, TAM);

}