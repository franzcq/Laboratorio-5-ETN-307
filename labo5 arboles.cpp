/*Realizar un programa en c++ que realice la reflexion de un arbol binario*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*ArBiBu;

ArBiBu crearNodo(int x)
{
     ArBiBu nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}

void insertar(ArBiBu &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Valor agregado"<<endl<<endl;
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}
ArBiBu arbolEspejo(ArBiBu arbol)
{
    ArBiBu temp;

    if(arbol!=NULL)
    {
          temp = arbol->izq;
          arbol->izq = arbolEspejo(arbol->der);
          arbol->der = arbolEspejo(temp);
    }
    return arbol;
}
void verArbol(ArBiBu arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}


int main (){

    ArBiBu arbol = NULL;
    int n; 
    int x; 

    cout << " Ingrese el numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Introdusca el valor del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    ArBiBu espejo;
                    espejo = NULL;

                    cout << "\n\n Arbol incial \n\n";

                    verArbol(arbol, 0);

                    cout << "\n\n REFLEXION DE NUESTRO ARBOL \n\n";

                    espejo = arbolEspejo(arbol);

                    verArbol(espejo, 0);
}
