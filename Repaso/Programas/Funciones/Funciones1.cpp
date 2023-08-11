#include <iostream>       // Prueba de parámetros para función main
using namespace std;

void Cambiar(int nuevoValor){
	nuevoValor = 8 ; 
	cout<<endl<<"(Despues de cambiar) El valor de n es :" << nuevoValor;
};

int main() {
	 int n= 5;
	 cout<<endl<<"El valor de n es :" << n;
	 Cambiar(n);
	 cout<<endl<<"(Despues de cambiar) El valor de n es :" << n;
}
