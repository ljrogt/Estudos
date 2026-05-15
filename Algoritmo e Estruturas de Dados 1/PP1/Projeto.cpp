#include <iostream>
#include <string>

struct Comando{
    std::string indicador;
    int cod;

    void tratarDado(){
	    std::cin>>indicador>>cod;
    }

    void print(){
        std::cout<<"("<<indicador<<", "<<cod<<")";
    }


};




template <typename T>
void prinT(T valor){
    std::cout<<valor;
}

void prinT(Comando c){
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
    No<T>* fim;
public:

    Navegador(No<T>* inicio,No<T>* f){
	    atual=inicio;
	    fim=f;
    }

    void irProximo(){
        atual=atual->informarProx();
    }

    T solicitarItem(){
        return atual->informarItem();
    }

    bool final(){
        return atual==fim->informarProx();
    }

};


template <typename T>
void print(Navegador<T> nav){
	std::cout<<"[";
	if(nav.final()){
		std::cout<<" ";
	}
	while(!nav.final()){
		prinT(nav.solicitarItem());
		nav.irProximo();
		if(!nav.final()){
			std::cout<<", ";
		}
	}
	std::cout<<"]\n";
}

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
    
    T informarPrimeiro(){
        return cabeca->informarProx()->informarItem();
    }
    
    T informarUltimo(){
	    return cabeca->informarAnt()->informarItem();
    }

    Navegador<T> dequeNavegador(){
	    Navegador<T> nav=Navegador(cabeca->informarProx(),cabeca->informarAnt());
	    return nav;
    }

    int informarTamanho(){
        return tamanho;
    }

};


template <typename T>
class Fila{
private:
    Deque<T> deque;
public:
    void adicionar(T item){
        deque.adicionarNoFinal(item);
    }
    void remover(){
        deque.removerDoComeco();
    }
    
    T informarPrimeiro(){
	    return deque.informarPrimeiro();
    }

    Navegador<T> filaNavegador(){
	    return deque.dequeNavegador();
    }
 
    int informarTamanho(){
        return deque.informarTamanho();
    }
};


template <typename T>
class Pilha{
private:
    Deque<T> deque;
public:
    void adicionar(T item){
        deque.adicionarNoComeco(item);
    }
    void remover(){
        deque.removerDoComeco();
    }
    
    T informarPrimeiro(){
	    return deque.informarPrimeiro();
    }

    Navegador<T> pilhaNavegador(){
	    return deque.dequeNavegador();
    }
    
   
    int informarTamanho(){
        return deque.informarTamanho();
    }
};



struct Sistema{
    Fila<Comando> FilaDeComandos;
    Fila<Comando> FEP;
    Pilha<int> PEP;
    Fila<int> CANCEL;
    Fila<int> DESC;
};

bool buscar(Comando c, Fila<Comando>& fila){
    Navegador<Comando> nav=fila.filaNavegador();
    while(!nav.final()){
        if(c.indicador==nav.solicitarItem().indicador&&c.cod==nav.solicitarItem().cod){
            return true;
        }
        nav.irProximo();
    }
    
    return false;
}

bool buscar(Comando c, Pilha<Comando>& pilha){
    Navegador<Comando> nav=pilha.pilhaNavegador();
    while(!nav.final()){
        if(c.indicador==nav.solicitarItem().indicador&&c.cod==nav.solicitarItem().cod){
            return true;
        }
        nav.irProximo();
    }
    
    return false;
}


template <typename T>
bool buscar(T c, Fila<T>& fila){
    Navegador<T> nav=fila.filaNavegador();
    while(!nav.final()){
        if(c==nav.solicitarItem()){
            return true;
        }
        nav.irProximo();
    }
    
    return false;
};


template <typename T>
bool buscar(T c, Pilha<T>& pilha){
    Navegador<T> nav=pilha.pilhaNavegador();
    while(!nav.final()){
        if(c==nav.solicitarItem()){
            return true;
        }
        nav.irProximo();
    }
    
    return false;
};



class Biggy{
public:
    
    void processar(Fila<Comando>& comds,Fila<Comando>& FEP,Fila<int>& CANCEL, Fila<int>& DESC){
        Navegador<Comando> nav=comds.filaNavegador();
        while(!nav.final()){
            Comando c=nav.solicitarItem();
            nav.irProximo();
            if(c.indicador=="E"||(c.indicador=="-"&&c.cod==0)){
                if(!buscar(c, FEP)){
                    FEP.adicionar(c);
                }
            }
            if(c.indicador=="C"){
                Comando p=c;
                p.indicador="E";
                if(buscar(p, FEP)&&!buscar(c,FEP)){
                    FEP.adicionar(c);
                }
                if(!buscar(p,FEP)){
                    if(!buscar(c.cod,CANCEL)){
                        CANCEL.adicionar(c.cod);
                    }
                }
            }
            if(c.indicador=="A"){
                Comando p=c;
                p.indicador="E";
                if(buscar(p,FEP)&&!buscar(c,FEP)){
                    FEP.adicionar(c);
                }
                if(!buscar(p,FEP)){
                    DESC.adicionar(c.cod);
                }
            }        
        }
    }

};

class Bang{
private:
    Pilha<int> AUX;
public:
    void printAUX(){
	    print(AUX.pilhaNavegador());
    }
    void processar(Sistema& sis){
        while(sis.FEP.informarTamanho()>0){
            Comando c=sis.FEP.informarPrimeiro();
            sis.FEP.remover();
            if(c.indicador=="E"){
                sis.PEP.adicionar(c.cod);
            }
            if(c.indicador=="C"){
                while(true){
                    if(sis.PEP.informarPrimeiro()!=c.cod){
                        AUX.adicionar(sis.PEP.informarPrimeiro());
                        sis.PEP.remover();
                    }else{
                        sis.CANCEL.adicionar(sis.PEP.informarPrimeiro());
                        sis.PEP.remover();
                        while(true){
                            if(AUX.informarTamanho()>0){
                                sis.PEP.adicionar(AUX.informarPrimeiro());
                                AUX.remover();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                }
            }    
            if(c.indicador=="A"){
                while(true){
                    if(sis.PEP.informarPrimeiro()!=c.cod){
                        AUX.adicionar(sis.PEP.informarPrimeiro());
                        sis.PEP.remover();
                    }else{
                        sis.DESC.adicionar(sis.PEP.informarPrimeiro());
                        sis.PEP.remover();
                        while(true){
                            if(AUX.informarTamanho()>0){
                                sis.PEP.adicionar(AUX.informarPrimeiro());
                                AUX.remover();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

};


int main(){
    Sistema sistema;
    Comando comando;
    bool fim=true;
    std::string Dado=" ";
    Biggy biggy;
    Bang bang;
    while(fim){
	   comando.tratarDado();
           sistema.FilaDeComandos.adicionar(comando);
           if(comando.indicador=="-"&&comando.cod==0){
                fim=false;
          }
    }

    biggy.processar(sistema.FilaDeComandos,sistema.FEP,sistema.CANCEL,sistema.DESC);
    std::cout<<"Biggy:\n";
    std::cout<<"FEP = ";
    print(sistema.FEP.filaNavegador());
    std::cout<<"CANCEL = ";

    print(sistema.CANCEL.filaNavegador());
    std::cout<<"DESC = ";

    print(sistema.DESC.filaNavegador());
    std::cout<<"\n";
    std::cout<<"Bang:\n";
    bang.processar(sistema);
    std::cout<<"FEP = ";

    print(sistema.FEP.filaNavegador());
    std::cout<<"PEP = ";

    print(sistema.PEP.pilhaNavegador());
    std::cout<<"AUX = ";
    bang.printAUX();
    std::cout<<"CANCEL = ";

    print(sistema.CANCEL.filaNavegador());
    std::cout<<"DESC = ";

    print(sistema.DESC.filaNavegador());
    return 0;
}
