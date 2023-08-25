#include <iostream>
void leer(int [5]);//declaracion de la funcion
void impresion(int [5],struct estadistica);
struct estadistica Calculos(int [5]);

//se crea struct
struct estadistica{
	int Suma;
	float Media;
	int Max;
	int Min;
};


using namespace std;
int main() {
	int datos[5];
	struct estadistica e1;
	leer(datos);
	e1 = Calculos(datos);
	impresion(datos,e1);
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
void impresion(int datos[5],struct estadistica est){
	//impresion del vector
	for(int i=0;i<5;i++){
		cout<<"La posicion "<<i+1<<" de vector es: "<<datos[i]<<endl;
	}
	
	cout<<endl<<"La sumatoria es: "<< est.Suma;
	cout<<endl<<"La media aritmetica es: "<< est.Media;
	cout<<endl<<"El minimo es: "<< est.Min;
	cout<<endl<<"El maximo es: "<< est.Max;

}
struct estadistica Calculos(int datos[5]){
	struct estadistica a1;
	a1.Suma = 0;
	a1.Min = datos[0];
	a1.Max = datos[0];
	 
	for(int i=0;i<5;i++){
		
		a1.Suma += datos[i];
		
		if(a1.Min > datos[i]){
			a1.Min = datos[i];
		}
		
		if(a1.Max < datos[i]){
			a1.Max = datos[i];
		}
	}
	
	a1.Media = (float)a1.Suma/5;
	
	return a1;
};
