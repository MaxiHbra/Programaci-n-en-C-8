/*Ejercicio 9: Se pide crear un programa recursivo que permita generar aleatoriamente una lista de N
números enteros en el intervalo [A, B], luego presentar un menú de opciones (el cual debe ser recursivo)
que permita realizar las siguientes tareas: ordenar ascendentemente utilizando el método Q-Sort, buscar
un elemento en la lista (dicho elemento es ingresado por teclado).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tlis[30];

void ingresar(tlis,int*);
void generar(tlis,int,int,int);
int menu(void);
void menu_rec(tlis,int);
void ordenar_qsort(tlis,int,int);
void buscar(tlis,int);
int buscar_rec(tlis,int,int,int);
void mostrar_rec(tlis,int);

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
	printf("\nIngrese 1 ordenar la lista con Q-SORT.");
	printf("\nIngrese 2 para buscar elemento dentro de la lista.");
	printf("\nIngresar 3 para mostrar la lista.");
	printf("\n---> ");
	scanf("%d",&opc);
	return opc;
}
void menu_rec(tlis lis, int n){
	int opc=menu();
	if(opc!=0){
		switch(opc){
			case 0 : printf("\nSaliste del programa."); break;
			case 1 : ordenar_qsort(lis,1,n); break;
			case 2 : buscar(lis,n); break;
			case 3 : mostrar_rec(lis,n); break;
		}
		menu_rec(lis,n);
	}
}
void ordenar_qsort(tlis lis, int ini, int fin){
	int piv,izq,der;
	if(ini<fin){
		piv=lis[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(izq<der && piv<lis[der])
				der--;
			if(izq<der){
				lis[izq]=lis[der];
				izq++;
			}
			while(izq < der && lis[izq]<piv) 
				izq++;
			if(izq < der){
				lis[der]=lis[izq];
				der--;
			}
		}
		lis[izq]=piv;
		ordenar_qsort(lis,ini,izq-1);
		ordenar_qsort(lis,izq+1,fin);
	}
}
void buscar(tlis lis,int n){
	int p,aux;
	printf("\nIngresar elemento a buscar: ");
	scanf("%d",&p);
	aux=buscar_rec(lis,1,n,p);
	if(aux!=0) printf("\nEl elemento %d está en la posicion: %d",p,aux);
	else printf("\nNo se encontro.");
}
int buscar_rec(tlis lis, int ini, int fin, int bus){
	int med=(ini+fin)/2;
	if(ini>fin) return 0;
	else if(lis[med]==bus) return med;
	else if(lis[med]>bus) return buscar_rec(lis,ini,med-1,bus);
		else return buscar_rec(lis,med+1,fin,bus);
}
void mostrar_rec(tlis lis,int n){
	if(n>0){
		mostrar_rec(lis,n-1);
		printf("\nEl elemento %d de la lista es: %d",n,lis[n]);
	}
}
