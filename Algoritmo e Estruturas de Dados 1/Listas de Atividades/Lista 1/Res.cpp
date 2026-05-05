#include <iostream>


struct Pizza
{
	std::string sabor;
	float preco;
	bool delivery;
};

void print(Pizza pizza){
	if (pizza.delivery){
		std::cout<<pizza.sabor<<" - "<<"R$"<<pizza.preco<<" - "<<"Delivery."<<"\n";
	} 
	else{
		std::cout<<pizza.sabor<<" - "<<"R$"<<pizza.preco<<" - "<<"Mesa."<<"\n";
	}
}

void print(Pizza pizza[], const int TAM){
	float somatorio=0;
	for (int i=0;i<TAM;i++){
		print(pizza[i]);
		somatorio+=pizza[i].preco;
	}

	std::cout<<"Valor total a pagar: R$"<<somatorio<<"\n";

	std::cout<<"---Somente para entrega---"<<"\n";

	for (int i=0;i<TAM;i++){
		if (pizza[i].delivery){
			print(pizza[i]);
		}
	}


}

void renomear(Pizza &pizza, std::string nome){
	pizza.sabor=nome;
}

int main(){

	Pizza pizzas[]={{"Portuguesa",50.0f,true},{"Mussarela", 70.0f, false}, {"Calabrea", 45.0f, true}};

	print(pizzas, 3);


	return 0;
}