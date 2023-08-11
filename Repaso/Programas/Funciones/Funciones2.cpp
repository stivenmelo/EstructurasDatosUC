#include <iostream>       // Prueba de parámetros para función main
using namespace std;
//funciones Void(sin retorno)
void LeerVector(int arreglo[10]){
	for(int i=0;i<10;i++){
		cout<<"Digite la posicion "<<i+1<<" del vector:";
		cin>> arreglo[i];
	}
};

void MostrarVector(int arreglo[10], int suma){
	for(int i=0;i<10;i++){
		cout<<"\nEn la posicion "<<i+1<<" el valor es: "<<arreglo[i];
	}
	
	cout<<"\nla sumatoria es: "<<suma;
};
//funciones con retorno
int Sumatoria(int arreglo[10]){
	int total = 0;
	
	for(int i =0 ; i<10; i++){
		total=total + arreglo[i];
	}
	
	return total;
} 

int main() {
	int suma = 0;
	
	//funciones Con array funcionan por referencia, es decir el mismo espacio en memoria
	 int v[10];
	 LeerVector(v);
	 
	 
	 suma = Sumatoria(v);
	 MostrarVector(v, suma);
}

