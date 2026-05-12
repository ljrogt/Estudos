#include <iostream>

template <typename T>
class Node{
private:
	T item;
public:
	Node<T>* next;
	Node(T valor){
		item=valor;
		next=nullptr;
	}

	T getItem(){
		return item;
	}

	void defineNext(Node<T>* n){
		next=n;
	}

};


int main(){


	return 0;
}
