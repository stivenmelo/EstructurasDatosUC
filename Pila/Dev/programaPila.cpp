#include <iostream>
using namespace std;



int insertar(int pila[5],int indice){
	int valorPila = 0;
	int indi = indice;
	
	cout<<endl<<"Valor Pila:";
	cin>>valorPila;
	
	if(indice>=-1 && indice <=4){
		if(pila[4] != 0){
			cout<<endl<<"Pila LLena";
			return indi;
		}
		cout<<endl<<"aca";
		indi++;
		pila[indi] = valorPila;
		return indi;
	}
	
	cout<<endl<<"Pila LLena";
	return indi;
}

void imprimir(int pila[5],int indice){
	for(int i = 0 ; i<5; i++){
			cout<<endl<<"Pila ubicacion "<<i+1<<" Tiene valor :"<<pila[i];
	}
	cout<<endl<<"indice: "<<indice<<"\n------------------------------------------";
}

int main() {
	int pila[5],indice = -1,valor =0, seleccion=0;
	bool programaIniciado  = true;
	for(int i = 0 ; i<5; i++){
			pila[i] = 0;
	}
	
	cout<<endl<<"PILA \n";
	
	while(programaIniciado){
		
		cout<<endl<<"1.insertar \n2.eliminar \n3.salir\n";
		cout<<endl<<"SELECCION:";
		cin>>seleccion;
		
		switch(seleccion) 
		{
		    case 1:
		    	indice = insertar(pila,indice);
		    	imprimir(pila,indice);
		    break;
		    case 2:
		    break;
		    case 3: 
		    break;
		    
		    default:
				cout<<endl<<"Seleccion no valida\n";
			break; 
		}
		
	} 
}
