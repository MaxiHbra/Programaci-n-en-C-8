/*Ejercicio 5: Mostrar los d�gitos de un n�mero natural X de derecha a izquierda. Realizar la traza para X=
45673. Modificar el m�dulo para que muestre los d�gitos de izquierda a derecha. (�El m�dulo recursivo
lleva return?).
*/
#include <stdio.h>
void mostrar_dig_rec(int);
int main() {
int p;
printf("\nIngresar numero: ");
scanf("%d",&p);
mostrar_dig_rec(p);
return 0;
}
void mostrar_dig_rec(int num){ /*derecha a izquierda*/
if(num!=0){
printf("\n%d",num%10);
mostrar_dig_rec(num/10);
}
}
/*void mostrar_dig_rec(int num){ izquierda a derecha
if(num!=0){
mostrar_dig_rec(num/10);
printf("\n%d",num%10);
}
}*/
