/*Realizar un programa con listas, que tenga el siguiente menu:
	1.Almacenar un nuevo numero en la lista.
	2.Mostrar todos los numeros almacenados en la lista.
	3.Eliminar un numero de la lista.
	4.Eliminar todos los numeros almacenados.
	5.Mostrar la suma y promedio de todos los numeros almacenados.
	6.Salir.*/

#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
 	float dato;
	Nodo *siguiente;
};

void almacenar(Nodo *&, float);
void mostrar(Nodo *);
void eliminar(Nodo *&, float);
void vaciar(Nodo *&, float &);
void calcular(Nodo *);

int main() {
 Nodo *lista = NULL;
 int opcion;
 float dato;
 
 do {
  cout << "1.Almacenar un nuevo numero en la lista." << endl;
  cout << "2.Mostrar todos los numeros almacenados." << endl;
  cout << "3.Eliminar un numero de la lista." << endl;
  cout << "4.Eliminar todos los numeros almacenados." << endl;
  cout << "5.Mostrar la suma y promedio de todos los numeros almacenados." << endl;
  cout << "6.Salir." << endl;
  cout << "\nElija la opcion: ";
  cin >> opcion;
  
  switch(opcion) {
   case 1:
    cout << "\nDigite un numero: ";
    cin >> dato;
    almacenar(lista,dato);
    cout << "\n\nPresione cualquier tecla para volver a mostrar el menu de opciones.";
    getch();
    break;
   case 2:
    if(lista != NULL) {
     mostrar(lista);
    } else {
     cout << "\nLa lista esta vacia.";
    }
    cout << "\n\nPresione cualquier tecla para volver a mostrar el menu de opciones.";
    getch();
    break;
   case 3:
    if(lista != NULL) {
     cout << "\nDigite un numero: ";
     cin >> dato;
     eliminar(lista,dato);
    } else {
     cout << "\nLa lista esta vacia.";
    }
    cout << "\n\nPresione cualquier tecla para volver a mostrar el menu de opciones.";
    getch();
    break;
   case 4:
    if(lista != NULL) {
     while(lista != NULL) {
      vaciar(lista,dato);
      cout << "\n\tNumero " << dato << " eliminado.";
     }
    } else {
     cout << "\nLa lista esta vacia.";
    }
    cout << "\n\nPresione cualquier tecla para volver a mostrar el menu de opciones.";
    getch();
    break;
   case 5:
    if(lista != NULL) {
     calcular(lista);
    } else {
     cout << "\nLa lista esta vacia.";
    }
    cout << "\n\nPresione cualquier tecla para volver a mostrar el menu de opciones.";
    getch();
    break;
  }
  system("cls");
 } while (opcion != 6);
 
 cout << "\nPresione cualquier tecla para salir del programa." << endl;
 getch();
 return 0;
}

void almacenar(Nodo *&lista, float n) {
 Nodo *nuevo_nodo = new Nodo();
 Nodo *aux;
 
 nuevo_nodo->dato = n;
 nuevo_nodo->siguiente = NULL;
 
 if(lista == NULL) {
  lista = nuevo_nodo;
 } else {
  aux = lista;
  while(aux->siguiente != NULL) {
   aux = aux->siguiente;
  }
  aux ->siguiente = nuevo_nodo;
 }
 
 cout << "\n\tNumero " << n << " agregado." << endl;
}

void mostrar(Nodo *lista) {
 while (lista != NULL) {
  cout << "\n\t- " << lista->dato;
  lista = lista->siguiente;
 }
}

void eliminar(Nodo *&lista, float n) {
 if(lista != NULL) {
  Nodo *aux = lista;
  Nodo *anterior = NULL;
  
  while((aux != NULL) && (aux->dato != n)) {
   anterior = aux;
   aux = aux->siguiente;
  }
  
  if(aux == NULL) {
   cout << "\n\tNumero " << n << " no encontrado.";
  } else if (anterior == NULL) {
   lista = lista->siguiente;
   delete aux;
   cout << "\n\tNumero " << n << " eliminado.";
  } else {
   anterior->siguiente = aux->siguiente;
   delete aux;
   cout << "\n\tNumero " << n << " eliminado.";
  }
 }
}

void vaciar(Nodo *&lista, float &n) {
 Nodo *aux = lista;
 n = aux->dato;
 lista = aux->siguiente;
 delete aux;
}

void calcular(Nodo *lista) {
 float suma = 0;
 float promedio;
 int contador = 0;
 
 while(lista != NULL) {
  suma = suma + lista->dato;
  lista = lista->siguiente;
  contador++;
 }
 
 promedio = suma / contador;
 
 cout << "\n\tSuma: " << suma << endl;
 cout << "\tPromedio: " << promedio << endl;
}
