/*Ejercicio 1: Dado el módulo iterativo que calcula el factorial de un número natural, se solicita replantearlo
recursivamente y realizar la traza con num=6.
int factorial(int num){ int i,fact=1;
for (i=num; i>=1; i--) fact=fact*i;
return fact; }*/
#include <stdio.h>
int factorial_rec(int);
int main() {
	int x;
	printf("\nIngresar numero para calcular factorial: ");
	scanf("%d",&x);
	printf("\nEl factorial de %d es: %d",x,factorial_rec(x));
	return 0;
}
int factorial_rec(int num){
	if(num==1) return 1;
	else if(num==0) return 1;
	else return num*factorial_rec(num-1);
}
