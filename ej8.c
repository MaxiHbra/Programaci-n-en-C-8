/*Ejercicio 8: Se pide crear un programa recursivo que permita generar aleatoriamente una lista de N
números enteros en el intervalo [A, B], luego presentar un menú de opciones (el cual debe ser recursivo)
que permita realizar las siguientes tareas: mostrar la lista, Insertar un nuevo elemento en una posición
ingresada por teclado, buscar un elemento en la lista.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tlis[30];

void ingresar(tlis,int*);
void generar(tlis,int,int,int);
int menu(void);
void menu_rec(tlis,int);
void mostrar_rec(tlis,int);
void insertar(tlis,int);
void insertar_rec(tlis,int,int);
void buscar(tlis,int);
int buscar_rec(tlis,int,int);

int main() {
	srand(time(NULL));
	int n;
	tlis lis;
	ingresar(lis,&n);
	menu_rec(lis,n);
	return 0;
}
void ingresar(tlis lis,int *n){
	int a,b;
	printf("\nIngresar el tamanio de la lista ");
	scanf("%d",n);
	printf("\nIngresar el primer valor del intervalo: ");
	scanf("%d",&a);
	printf("\nIngresar el ultimo valor del intervalo: ");
	scanf("%d",&b);
	generar(lis,*n,a,b);
}
void generar(tlis lis,int n,int a, int b){
	if(n>0){
		generar(lis,n-1,a,b);
		lis[n]=(rand()%(b-a-1))+a;
	}
}
int menu(){
	int opc;
	printf("\nIngrese 0 para salir del programa.");
	printf("\nIngrese 1 para mostrar lista.");
	printf("\nIngrese 2 para insertar un elemento en una posicion determinada.");
	printf("\nIngrese 3 para buscar un elemento. ");
	printf("\n---> ");
	scanf("%d",&opc);
	return opc;
}
void menu_rec(tlis lis, int n){
	int opc=menu();
	if(opc==0)
		printf("\nSaliste del programa.");
	else{
		switch(opc){
			case 1 : mostrar_rec(lis,n); break;
			case 2 : insertar(lis,n); break;
			case 3 : buscar(lis,n); break;
			default : break;
	}
	menu_rec(lis,n);
}
}
void mostrar_rec(tlis lis,int n){
	if(n>0){
		mostrar_rec(lis,n-1);
		printf("\nEl elemento %d de la lista es: %d",n,lis[n]);
	}
}
void insertar(tlis lis, int n){
	int pos;
	printf("\nIngresar la posicion a insertar: ");
	scanf("%d",&pos);
	if(pos<=n){
		insertar_rec(lis,n,pos);
	}
	else printf("\nPosicion invalida. ");
}
void insertar_rec(tlis lis,int n,int pos){
	if(n==pos){
		printf("\nIngresar elemento: ");
		scanf("%d",&lis[n]);
	}
	else insertar_rec(lis,n-1,pos);
}
void buscar(tlis lis,int n){
	int p,aux;
	printf("\nIngresar elemento a buscar: ");
	scanf("%d",&p);
	aux=buscar_rec(lis,n,p);
	if(aux!=0) printf("\nPosicion: %d",aux);
	else printf("\nNo se encontro.");
}
int buscar_rec(tlis lis,int n,int bus){
	if(lis[n]==bus) return n;
	else if(n==0) return 0;
	else return buscar_rec(lis,n-1,bus);
}
