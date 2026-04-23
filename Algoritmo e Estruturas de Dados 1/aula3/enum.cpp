#include <iostream>

enum CoresSemaforo{vermelho, amarelo, verde};
using CorDoSinaleiro=int;

int main(){

	int d=0;
	CorDoSinaleiro s1=verde;
	std::cout<<"Digite a diferença: ";
	std::cin>>d;
	CorDoSinaleiro s2=s1-d;
	if(s2==vermelho){
		std::cout<<"Pare!";
	}

	return 0;
}