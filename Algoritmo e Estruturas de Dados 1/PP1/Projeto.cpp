#include <iostream>
#include <string>

struct Comando{
	std::string indicador;
	int cod;

	void tratarDado(const std::string dado){
		std::string codigo="";
		for(int i=0;i<dado.length();i++){
			std::string carac(1,dado[i]);
			try{
				int teste=std::stoi(carac);
				codigo+=dado[i];
			}

			catch(...){
				if(carac!=" "){
					indicador=dado[i];
				}
			}
		}
		cod=stoi(codigo);
	}

	void print(){
		std::cout<<"("<<indicador<<", "<<cod<<")";
	}


};




template <typename T>
void print(T valor){
	std::cout<<valor;
}

void print(Comando c){
	c.print();
}

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
class Navegador{
private:
	No<T>* atual;
public:

	Navegador(No<T>* inicio){
		atual=inicio;
	}

	void irProximo(){
		atual=atual->informarProx();
	}

	T solicitarItem(){
		return atual->informarItem();
	}

	bool final(No<T>* final){
		return atual==final;
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
	No<T>* informarPrimeiro(){
		return cabeca->informarProx();
	}
	No<T>* informarUltimo(){
		return cabeca->informarAnt();
	}

	void print(){
		Navegador<T> nav=Navegador(cabeca->informarProx());
		std::cout<<"[";
		while(!nav.final(cabeca->informarAnt())){
			::print(nav.solicitarItem());
			std::cout<<",";
			nav.irProximo();
		}
		::print(nav.solicitarItem());
		std::cout<<"]\n";

	}

	void copiar(Deque<T>& copia){
		Navegador<T> nav=Navegador(cabeca->informarProx());
		while(!nav.final(cabeca)){
			T valor=nav.solicitarItem();
			copia.adicionarNoFinal(valor);
			nav.irProximo();
		}
	}

};

struct Sistema{
	Deque<Comando> FilaDeComandos;
	Deque<Comando> FEP;
	Deque<int> CANCEL;
	Deque<int> DESC;
};

bool buscar(Comando c, Deque<Comando>& deque){
	Navegador<Comando> nav=Navegador(deque.informarPrimeiro());
	while(!nav.final(deque.informarUltimo())){
		if(c.indicador==nav.solicitarItem().indicador&&c.cod==nav.solicitarItem().cod){
			return true;
		}
		nav.irProximo();
	}
	if(c.indicador==nav.solicitarItem().indicador&&c.cod==nav.solicitarItem().cod){
		return true;
	}
	return false;
}




class Robo{

public:
	Robo(Sistema& sis){
		Navegador<Comando> nav=Navegador(sis.FilaDeComandos.informarPrimeiro());
		while(!nav.final(sis.FilaDeComandos.informarUltimo())){
			Comando valor = nav.solicitarItem();
			processar(sis,valor);
			nav.irProximo();
			
		}
		Comando valor=nav.solicitarItem();
		processar(sis, valor);
	}
	
	void processar(Sistema& sis,Comando c){
		if(c.indicador=="E"||(c.indicador=="-"&&c.cod==0)){
			if(!buscar(c, sis.FEP)){
				sis.FEP.adicionarNoFinal(c);
			}
		}
		if(c.indicador=="C"){
			Comando p=c;
			p.indicador="E";
			if(buscar(p, sis.FEP)&&!buscar(c,sis.FEP)){
				sis.FEP.adicionarNoFinal(c);
			}
			if(!buscar(p,sis.FEP)){
				sis.CANCEL.adicionarNoFinal(c.cod);
			}
		}
		if(c.indicador=="A"){
			Comando p=c;
			p.indicador="E";
			if(buscar(p,sis.FEP)&&!buscar(c,sis.FEP)){
				sis.FEP.adicionarNoFinal(c);
			}
			if(!buscar(p,sis.FEP)){
				sis.DESC.adicionarNoFinal(c.cod);
			}
		}

	}
	
};





int main(){
	Sistema sistema;
	Comando comando;
	bool fim=true;
	std::string Dado=" ";
	while(fim){
		std::getline(std::cin,Dado);
		if(Dado==""){
			fim=false;
		}else{
		comando.tratarDado(Dado);
		sistema.FilaDeComandos.adicionarNoFinal(comando);
		}
	}

	Robo Biggy=Robo(sistema);
	sistema.FEP.print();
	sistema.CANCEL.print();	
	sistema.DESC.print();
	return 0;
}
