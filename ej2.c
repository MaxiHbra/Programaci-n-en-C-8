/*
Ejercicio 2: Para las siguientes situaciones, realice un módulo recursivo y la traza con los datos indicados
para cada una:
a) Dado un dígito D, determinar si pertenece a un número entero positivo N. Realizar la traza para
D=1 y X= 45673.
b) Dado un número natural, indicar si el mismo es perfecto, abundante o deficiente.
Nota: Un número natural X se dice que es deficiente si la suma de sus divisores (sin contarse a sí mismo)
es menor a X. Si la suma de sus divisores es mayor a X se dice que el número es abundante y si es igual
a X se dice que es perfecto.*/
#include <stdio.h>
void pertenece(int,int);
int pertenece_rec(int,int);
void tp_num(int);
int tp_num_rec(int,int);
int main() {
	int x,x2;
	/*A*/
	printf("\nIngresar numero: ");
	scanf("%d",&x);
	printf("\nIngresar digito a buscar: ");
	scanf("%d",&x2);
	pertenece(x,x2);
	/*B*/
	printf("\nIngresar numero: ");
	scanf("%d",&x);
	tp_num(x);
	return 0;
}
/*A*/
void pertenece(int num,int dig){
	if(pertenece_rec(num,dig)) printf("\nEl digito pertenece.");
	else printf("\nEl digito no pertenece.");
}
int pertenece_rec(int num, int dig){
	if(num==dig) return 1;
	else if(num==0) return 0;
	else return pertenece_rec(num/10,dig);
}
	/*B*/
void tp_num(int num){
	int p=tp_num_rec(num,1);
	if(p>num) printf("\nEl numero es: Abundante.");
	else if(p<num) printf("\nEl numero es: Deficiente.");
	else printf("\nEl numero es: Perfecto.");
}
int tp_num_rec(int num, int cont){
	if(cont > num/2) return 0;
	else if(num % cont ==0) return cont + tp_num_rec(num,cont+1);
	else return tp_num_rec(num,cont+1);
}
