#include <iostream>
using namespace std;

void leer(int bus[10]){
	for(int i = 0 ; i<10 ; i++){
		cout<<"Digite la cantidad de pasajeros del bus"<<i+1<<":";
		cin>>bus[i];
	}
}

void imprimir(int bus[10], int sobrecupo, int totalPasajeros,float mediaPasajeros){
	for(int i = 0 ; i<10 ; i++){
		cout<<endl<<"la cantidad de pasajeros del bus"<<i+1<<"es:"<<bus[i];
	}
	
	cout<<endl<<"buses con Sobrecupo: "<<sobrecupo;
	cout<<endl<<"Total pasajeros: "<<totalPasajeros;
	cout<<endl<<"Media de pasajeros: "<<mediaPasajeros;
}

int calcularSobrecupo(int bus[10]){
	int sobrecupo =0;
	for(int i = 0 ; i<10 ; i++){
		if(bus[i]> 150){
			sobrecupo++;
		}
	}
	
	return sobrecupo;
	//cout<<endl<<"sobrecupo en funcion: "<<sobrecupo;
}

int SumatoriaPasajeros(int buses[10]){
	int suma =0 ;
	for(int i = 0 ; i<10 ; i++){
		suma += buses[i];
	}
	return suma;
}


float MediaPasajeros(int totalPasajeros){
	return totalPasajeros/10;
}



int main () {
  int buses[10], sobrecupo =0,totalPasajeros =0 ;
  float mediaPasajeros;
  leer(buses);
  sobrecupo = calcularSobrecupo(buses);
  totalPasajeros =SumatoriaPasajeros(buses);
  
  mediaPasajeros = MediaPasajeros(totalPasajeros);
  imprimir(buses,sobrecupo,totalPasajeros,mediaPasajeros);
  
  	//cout<<endl<<"sobrecupo en main: "<<sobrecupo;
}

