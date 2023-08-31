#include <stdio.h>
int main(){
	int a; /* a es un entero*/
	int *ap; /* ap es un apuntador a un entero*/
	a=10;
	ap=&a; /* ap contiene la direccion de a */
	printf("la direccion de a es %p\n""el valor de ap es %p\n\n",&a,ap);
	// debe ser igual y debe mostrar la direccion

	printf("el valor de a es %d\n""el valor que hay en la direccion *ap es %d\n\n",a,*ap);
	// debe ser igual y mostrar el valor de a

	printf("sabiendo que * y & son complementos de cada uno\n &*ap = %p\n*&ap=%p\n", &*ap,*&ap); 
	return 0;
}
