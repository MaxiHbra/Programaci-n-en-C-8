/*
Dada la siguiente definici�n recursiva:
Formule el m�dulo recursivo y la traza para el c�lculo del resto (22,5).
Nota: Esta funci�n permite encontrar el resto de la divisi�n entera entre X e Y.
#include <stdio.h>
int resto_rec(int, int);
int main() {
	int x,x2;
	printf("\nIngresar numero: ");
	scanf("%d",&x);
	printf("\nIngresar divisor: ");
	scanf("%d",&x2);
	printf("\n El resto de %d / %d es = %d",x,x2,resto_rec(x,x2));
	return 0;
}
int resto_rec(int num, int div){
	if(div>num) return num;
	else return resto_rec(num-div,div);
}
