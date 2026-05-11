
#include <iostream>

template <typename T>
class No{
private:
	T item;
	No<T>* prox;
	No<T>* ant;
public:

	No(T n){
		item=n;
		prox=nullptr;
		ant=nullptr;
	}

	void definirProx(No<T>* n){
		prox=n;
	}

	void definirAnt(No<T>* n){
		ant=n;
	}

	No<T>* informarProx(){
		return prox;
	}

	No<T>* informarAnt(){
		return ant;
	}

	T informarItem(){
		return item;
	}

	void print(){
		std::cout<<item;
	}


};

template <typename T>
class Deque{
private:
	No<T>* cabeca=new No(T());
	int tamanho=0;
public:
	Deque(){
		cabeca->definirProx(cabeca);
		cabeca->definirAnt(cabeca);
	}

	~Deque(){
		No<T>* primeiro=cabeca->informarProx();
		while(primeiro!=cabeca){
			No<T>* proximo=primeiro->informarProx();
			delete primeiro;
			primeiro=proximo;
		}

		delete cabeca;
	}

	void adicionarNoFinal(T item){
		No<T>* n=new No(item);
		No<T>* ultimo=cabeca->informarAnt();
		ultimo->definirProx(n);
		n->definirAnt(ultimo);
		n->definirProx(cabeca);
		cabeca->definirAnt(n);
		tamanho++;
	}

	void adicionarNoComeco(T item){
		No<T>* n=new No(item);
		No<T>* primeiro=cabeca->informarProx();
		primeiro->definirAnt(n);
		n->definirProx(primeiro);
		n->definirAnt(cabeca);
		cabeca->definirProx(n);
		tamanho++;
	}

	bool estaVazio(){
		return cabeca==cabeca->informarProx();
	}

	void removerDoFinal(){
		if(estaVazio()){
			return;
		}
		No<T>* item=cabeca->informarAnt();
		No<T>* ultimo=item->informarAnt();
		ultimo->definirProx(cabeca);
		cabeca->definirAnt(ultimo);
		delete item;
		item=nullptr;
		tamanho--;
	}

	void removerDoComeco(){
		if(estaVazio()){
			return;
		}
		No<T>* item=cabeca->informarProx();
		No<T>* primeiro=item->informarProx();
		primeiro->definirAnt(cabeca);
		cabeca->definirProx(primeiro);
		delete item;
		item=nullptr;
		tamanho--;
	}

	void print(){
		No<T>* primeiro=cabeca->informarProx();
		while(primeiro!=cabeca){
			primeiro->print();
			primeiro=primeiro->informarProx();

		}
		std::cout<<"\n";
	}
};


int main(){
	Deque<std::string> lista_numeros;
	lista_numeros.adicionarNoFinal("Leandro");
	lista_numeros.adicionarNoComeco("Junior");
	lista_numeros.adicionarNoFinal("Candido");

	lista_numeros.print();

	lista_numeros.removerDoFinal();

	lista_numeros.print();

	lista_numeros.removerDoComeco();

	lista_numeros.print();
}