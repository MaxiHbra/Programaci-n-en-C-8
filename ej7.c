/*Ejercicio 7: Dada una lista de N números enteros que se ingresa ordenada, se pide crear un programa
recursivo que permita: cargar y mostrar la lista, a continuación, buscar si encuentra un elemento
ingresado por teclado, en caso de encontrarlo debe mostrar su posición y luego eliminarlo.
Nota: Hacer búsqueda binaria.*/
#include <stdio.h>
#define max 20

typedef int tlis[max];

void ingreso(tlis,int*);
void ingreso_rec(tlis,int);
void muestra_rec(tlis,int);
int busqueda_binaria(tlis,int,int);
int busqueda_rec(tlis,int,int,int);
void eliminar(tlis,int*,int);
void eliminar_rec(tlis,int,int);

int main() {
	tlis lis;
	int n,aux;
	ingreso(lis,&n);
	muestra_rec(lis,n);
	printf("\nIngresar elemento a buscar: ");
	scanf("%d",&aux);
	aux=busqueda_binaria(lis,n,aux);
	if(aux!=0){
		eliminar(lis,&n,aux);
		printf("\nLista resultante: ");
		muestra_rec(lis,n);
	}
	else printf("\nNo se encontro.");
	return 0;
}
void ingreso(tlis lis, int *n){
	printf("\nIngresar tamanio: ");
	scanf("%d",n);
	ingreso_rec(lis,*n);
}
void ingreso_rec(tlis lis,int n){
	if(n>0){
		ingreso_rec(lis,n-1);
		printf("\nIngrese un elemento: ");
		scanf("%d",&lis[n]);
	}
}
void muestra_rec(tlis lis,int n){
	if(n>0){
		muestra_rec(lis,n-1);
		printf("\nEl elemento es %d: %d",n,lis[n]);
	}
}
int busqueda_binaria(tlis lis,int n,int bus){
	return busqueda_rec(lis,1,n,bus);
}
int busqueda_rec(tlis lis,int ini,int fin,int bus){
	int med=(ini+fin)/2;
	if(ini>fin) return 0;
	else if(lis[med]==bus) return med;
		else if(bus > lis[med]) return busqueda_rec(lis,med+1,fin,bus);
			else return busqueda_rec(lis,ini,med-1,bus);
}
void eliminar(tlis lis,int *n,int pos){
	eliminar_rec(lis,*n,pos);
	*n=*n-1;
}
void eliminar_rec(tlis lis,int n,int pos){
	if(pos<n){ 
		lis[pos]=lis[pos+1];
		eliminar_rec(lis,n,pos+1);
	}
}
