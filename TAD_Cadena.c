#include "TAD_Cadena.h"
#include <string.h>
#include <stdio.h>

void cargar_cadena(TCadena cad){
	leeCad(cad,20);
}
void leeCad(TCadena cad, int tam){ /*Completar con proceso recursivo*/

}
int compara_cadena(TCadena cad1, TCadena cad2){
	if (strcmp(cad1, cad2)==1) return 1; /*cad1 > cad2*/
			else if (strcmp(cad1, cad2)==0) return 0; /*cad1 = cad2*/
						else return -1; /*cad1 < cad2*/
}
