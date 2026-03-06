#include <iostream>


struct Pizza
{
	std::string sabor;
	float preco;
	bool delivery;
};

//Questão 1
// int main() {
// 	Pizza pizza1 = {"Portuguesa",55.50f,true};
// 	Pizza pizza2 = {"Calabresa", 60.00f,false};

// 	std::cout<<pizza1.sabor<<" | "<<pizza1.preco<<" | "<<pizza1.delivery<<std::endl;
// 	std::cout<<pizza2.sabor<<" | "<<pizza2.preco<<" | "<<pizza2.delivery<<std::endl;
// }


// Questão 2

void mostrar_pizza(Pizza pizza[],int tamanho) {
	
	for (int i = 0; i < tamanho; ++i)
	{
		std::string forma="Mesa";


		if (pizza[i].delivery){
		forma="Delivery";
	}
		std::cout<<pizza[i].sabor<<" - R$"<<pizza[i].preco<<" - "<<forma<<std::endl;
	}
	
}

// int main() {
// 	Pizza pizza1 = {"Portuguesa",55.50f,false};
// 	mostrar_pizza(pizza1);
// }


// Questão 3

// std::string mudar_nome(Pizza pizza,std::string nome){
// 	pizza.sabor=nome;
// 	return nome;
// }

// int main(){
// 	Pizza pizza={"Portuguesa",60.00f,true};
// 	mostrar_pizza(pizza);
// 	pizza.sabor=mudar_nome(pizza,"Calabresa");
// 	mostrar_pizza(pizza);
// }


// Questão 4

// // int main(){
// 	// Pizza pizza[5]={
// 	// 	{"Frango Cap", 50.50f,true},
// 	// 	{"Portuguesa", 74.30f,false},
// 	// 	{"Mussarela", 45.50f,true},
// 	// 	{"File com Fritas", 54.50f,false},
// 	// 	{"Calabresa", 57.56f,true}
// 	// };

// 	for (int i = 0; i < 5; ++i)
// 	{
// 		mostrar_pizza(pizza[i]);
// 	}

// }

// Questão 5

// int main(){
// 	Pizza pizza[5]={
// 		{"Frango Cap", 50.50f,true},
// 		{"Portuguesa", 74.30f,false},
// 		{"Mussarela", 45.50f,true},
// 		{"File com Fritas", 54.50f,false},
// 		{"Calabresa", 57.56f,true}
// 	};

// 	Pizza pizza1[1]={"Frango e Carne", 57.56f,true};

// 	mostrar_pizza(pizza,5);
// 	std::cout<<"++++++++++++"<<std::endl;
// 	mostrar_pizza(pizza1,1);

// }

// Questão 6

// float calcular_total_a_ser_pago(Pizza pizza[],int tamanho){
// 	float preco_total=0;
// 	for (int i=0;i<tamanho;i++){
// 		preco_total+=pizza[i].preco;
// 	}

// 	return preco_total;
// }

// int main()
// {
// 	Pizza pizza[5]={
// 		{"Frango Cap", 50.50f,true},
// 		{"Portuguesa", 74.30f,false},
// 		{"Mussarela", 45.50f,true},
// 		{"File com Fritas", 54.50f,false},
// 		{"Calabresa", 57.56f,true}
// 	};

// 	mostrar_pizza(pizza,5);
// 	float total_a_pagar=calcular_total_a_ser_pago(pizza,5);
// 	std::cout<<"O total a ser pago por essas pizzas é: "<<total_a_pagar<<std::endl;
// 	return 0;
// }

// Questão 7

