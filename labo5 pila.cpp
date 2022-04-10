/*Hacer un programa para agregar tantos numeros enteros como desee el usuario en una pila, despues mostrar todos los elementos introducidos en la pila*/

#include<iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&,int &);

int main(){
	Nodo *pila = NULL;
	int dato;
	char rpt;
	
	do{
		cout<<"Digite un numero: ";
		cin>>dato;
		agregarPila(pila,dato);
		
		cout<<"\nDesea agregar otro elemento a la pila (s/n): ";
		cin>>rpt;
		
	}while((rpt=='S')||(rpt=='s'));
	
	cout<<"\nSacando los elementos de la pila: ";
	while(pila != NULL){
		sacarPila(pila,dato);
		if(pila != NULL){
			cout<<dato<<", ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n= aux->dato;
	pila = aux->siguiente;
	delete aux;
}
