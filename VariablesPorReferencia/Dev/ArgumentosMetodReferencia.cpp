/* calcular el cubo usando llamada por referencia*/
#include <stdio.h>
void cuboporreferencia(int *);//el "*" significa que va a recibir, como argunemro, la referencia de memoria(Direccion de memoria) de la variable int
main(){
	int numero=5;
	printf("El valor original del numero es %d\n",numero);
	cuboporreferencia(&numero);
	printf("El nuevo valor es %d\n",numero);
	return 0;
}

void cuboporreferencia(int *np){
	*np = *np *  *np * *np; /* numero al cubo en el main */
}
