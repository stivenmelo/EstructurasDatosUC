#include <stdio.h> //printf y scanf
#include <iostream>
#include <conio.h> //getche

int main(){
       int x, y, z, result;
       printf("\nLeer tres enteros\n");
       printf("Digite el primer numero: ");
	   scanf("%d",&x);
	   printf("Digite el segundo numero: ");
	   scanf("%d",&y);
	   printf("Digite el tercer numero: ");
	   scanf("%d",&z);
       result=x+y+z;
       printf("%d + %d + %d = %d \n",x,y,z,result);
       return 0;
}
