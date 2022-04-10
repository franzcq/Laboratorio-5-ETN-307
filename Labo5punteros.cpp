/*Rellenar un arreglo con n numeros enteros, posteriormente utilizando punteros
determinar el mayor elemento del arreglo y su posicion de memoria*/

#include<iostream>

using namespace std;

int main(){
	int n,i;
	
	cout<<"Ingrese cuantos numeros desea ingresar: "; cin>>n;
	
	int vectorA[n], *dirVectorA, *dirElemento, varAuxiliar;
	
	for(i=0;i<n;i++){
		vectorA[i] = 0;
	}
	
	cout<<"Introdusca los numeros: "<<endl;
	
	for(i=0;i<n;i++){
		cin>>vectorA[i];
	}
	
	varAuxiliar = vectorA[0]-1;
	dirVectorA = vectorA;
	
	for(i=0;i<n;i++){
		if(*dirVectorA>=varAuxiliar){
			varAuxiliar = *dirVectorA;
		}
		dirVectorA++;
	}
	
	dirElemento = &varAuxiliar;
	
	cout<<"El numero "<<*dirElemento<<" es el numero mas grande entre todos los introducidos"<<endl;
	cout<<"La dirreccion de memoria del numero "<<*dirElemento<<" es: "<<dirElemento<<endl;
	
	return 0;
}
