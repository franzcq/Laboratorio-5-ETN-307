/*Hacer un programa, utilizando colas que contenga el sigueinte menu:
	-Insertar un caracter a una cola
	-Mostrar todos los elementos de la cola
	-salir */

#include<iostream>

using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;	
};

void menu();
void insertarCola(Nodo *&,Nodo *&,char);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,char &);

int main(){
	menu();
	
	return 0;
}

void menu(){
	int opc;
	char dato;
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
		cout<<"1. Insertar un caracter a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos de la cola"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Elija una opcion: "; cin>>opc;
		
		switch(opc){
			case 1: 
				cout<<"\nIngrese el caracter para agregar a la cola: "; cin>>dato;
				insertarCola(frente,fin,dato);
				
				break;	
			case 2:
				cout<<"Mostrando los elementos de la cola: ";
				while(frente != NULL){
					suprimirCola(frente,fin,dato);
					if(frente != NULL){
						cout<<dato<<", ";					
					}
					else{
						cout<<dato<<".";
					}
				}
				system("pause");
			case 3: break;
		}
		system("cls");
		
	}while(opc!=3);
}

void insertarCola(Nodo *&frente, Nodo *&fin,char n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return(frente == NULL)? true : false;
}

void suprimirCola(Nodo *&frente,Nodo *&fin, char &n){
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}
