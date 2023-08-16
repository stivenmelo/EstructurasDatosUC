#include <iostream>
using namespace std;

void leer(int bus[10]){
	for(int i = 0 ; i<10 ; i++){
		cout<<"Digite la cantidad de pasajeros del bus"<<i+1<<":";
		cin>>bus[i];
	}
}

void imprimir(int bus[10]){
	for(int i = 0 ; i<10 ; i++){
		cout<<endl<<"la cantidad de pasajeros del bus"<<i+1<<"es:"<<bus[i];
	}
}

int main () {
  int buses[10], sobrecupo;
  leer(buses);
  imprimir(buses);
}
