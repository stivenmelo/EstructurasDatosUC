#include <iostream>
void leer(int [5]);//declaracion de la funcion
void impresion(int [5]);
struct estadisticas{
	int Suma;
	float Media;
	int Max;
	int Min;
};


using namespace std;
int main(int argc, char *argv[]) {
	int datos[5];
	leer(datos);
	impresion(datos);
	return 0;
}

void leer(int datos[5]){
	//lectura del vector
	int i;
	for( i=0;i<5;i++){
		cout<<"Escriba la posicion "<<i+1<<" de 5: ";
		cin>>datos[i];
	}
}
void impresion(int datos[5]){
	//impresion del vector
	for(int i=0;i<5;i++){
		cout<<"La posicion "<<i+1<<" de vector es: "<<datos[i]<<endl;
	}
}



