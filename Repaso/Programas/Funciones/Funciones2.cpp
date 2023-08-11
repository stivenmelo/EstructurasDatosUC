#include <iostream>       // Prueba de parámetros para función main
using namespace std;
//funciones Void(sin retorno)
void LeerVector(int arreglo[10]){
	for(int i=0;i<10;i++){
		cout<<"Digite la posicion "<<i+1<<" del vector:";
		cin>> arreglo[i];
	}
};

void MostrarVector(int arreglo[10], int suma, float media, int min, int max){
	for(int i=0;i<10;i++){
		cout<<"\nEn la posicion "<<i+1<<" el valor es: "<<arreglo[i];
	}
	
	cout<<"\nLa sumatoria es: "<<suma;
	cout<<"\nLa media es: "<<media;
	cout<<"\nEL valor minimo en el vector es : "<<min;
	cout<<"\nEL valor maximo en el vector es : "<<max;

};
//funciones con retorno
int Sumatoria(int arreglo[10]){
	int total = 0;
	
	for(int i =0 ; i<10; i++){
		total=total + arreglo[i];
	}
	
	return total;
} 

float Media(int arreglo[10]){
	return (float) Sumatoria(arreglo)/10;
}

int Min(int arreglo[10]){
	int min =arreglo[0];
	 
	 for(int i =0 ;i<10 ;i++){
	 	if(min>arreglo[i]){
	 		min = arreglo[i];
		 }
	 }
	 
	 return min;
}

int Max(int arreglo[10]){
	int max =arreglo[0];
	 
	 for(int i =0 ;i<10 ;i++){
	 	if(max<arreglo[i]){
	 		max = arreglo[i];
		 }
	 }
	 
	 return max;
}

int main() {
	int suma = 0,min =0, max =0;
	float media = 0;
	
	//funciones Con array funcionan por referencia, es decir el mismo espacio en memoria
	 int v[10];
	 LeerVector(v);
	 
	 
	 suma = Sumatoria(v);
	 media = Media(v);
	 min = Min(v);
	 max = Max(v);
	 
	 MostrarVector(v, suma,media,min,max);
}


