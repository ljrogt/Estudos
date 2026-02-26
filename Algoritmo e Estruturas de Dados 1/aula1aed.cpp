#include <iostream>

//int main(){
//
//	std::cout << "Olá Mundo!\n";
//
//	return 0;
//}

//int main(){
//	int x = 12345;
//
//	std::cout<<"x: "<< x<<"\n";
//
//	return 0;
//}


int main(){
	int idade = 0;

	std::cout<<"Digite sua idade: ";
	std::cin>>idade;
	if (idade>18) {
		std::cout<<"Idade: "<< idade<<"\n";
		std::cout<<"End. de Idade: "<<&idade<<"\n";
	}

	return 0;
}


//int main(){
//	const float peso_limite = 150.0f;
//
//	std::cout <<"Peso limite: "<<peso_limite<<"\n";
//}


//int main(){
//	const int count = 10;
//
//	for (int i =1; i <= count; i++){
//		std::cout<<i<<"\n";
//	}
//
//	return 0;
//
//}


