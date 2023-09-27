#include<iostream>
using namespace std;
 
int main()
{
    /*char str[500];
    printf("cadena: ");
	scanf("%s",&str);
//	scanf("%[^\n]",&str);//permite leer la cadena con espacios, termina cuando oprima enter \n
	printf("La cadena es %s",str);
    */
    
    
    char nombre[50], apellido[50];
    printf("Nombre: ");
    scanf("%[^\n]",&nombre);
    
    //limpia bufer de entrada donde se almacenan los valores recibidos
    fflush(stdin);
    printf("Apellido: ");
    scanf("%[^\n]",&apellido);
    printf("su nombre con apellido es %s %s",nombre,apellido);
}
