#include <iostream>


void print(int* ptr, const int TAM){
	for(int i=0;i<TAM;i++){
		std::cout<<ptr[i]<<" ";
	}
}

int* adicionar(int* ptr, int &TAM,int valor){
	int* ptrtemp=new int[TAM+1];
	for(int i=0;i<TAM;i++){
		ptrtemp[i]=ptr[i];
	}
	delete[] ptr;
	ptrtemp[TAM]=valor;
	TAM+=1;
	return ptrtemp;
}

int main(){
	int TAM=3;
	int* ptr=new int[TAM];
	for(int i=0;i<TAM;i++){
		ptr[i]=i;
	}

	print(ptr, TAM);
	ptr=adicionar(ptr, TAM, 4);
	std::cout<<"\n";
	print(ptr,TAM);
}