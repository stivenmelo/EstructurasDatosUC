#include <iostream>
using namespace std;

/*

Programa Creado por: STIVEN DANIEL MELO GUAYAZAN

*/


int Insertar(int pila[10],int indice){
	int valorPila = 0;
	int indi = indice;
	
	cout<<endl<<"Valor Pila:";
	cin>>valorPila;
	
	if(valorPila == 0){
		cout<<endl<<"valor no valido\n";
		return indi;
	}
	
	if(indice>=-1 && indice <=10){
		if(pila[9] != 0){
			cout<<endl<<"Pila LLena \n";
			return indi;
		}
		indi++;
		pila[indi] = valorPila;
		return indi;
	}
	
	cout<<endl<<"Pila LLena \n";
	return indi;
}

int Eliminar(int pila[10],int indice){
	if(indice == -1){
		cout<<endl<<"Pila Vacia \n";
		return indice;
	}
	
	pila[indice] = 0;
	indice--;
	return indice;
}

void Buscar(int pila[10]){
	
	int valorBusqueda = 0 ;
	bool encontroValor = false;
	
	cout<<endl<<"Digite el valor a buscar: ";
	cin>>valorBusqueda;
	
	
	
	for(int i = 0 ; i<10; i++){
		if(pila[i] == valorBusqueda && valorBusqueda != 0){
			cout<<endl<<"su valor "<<valorBusqueda<<" de busqueda se encuentra en el indice: "<<i+1<<"\n";
			encontroValor = true;
		}
	}
	
	if(!encontroValor && valorBusqueda != 0){
		cout<<endl<<"No se encontro el valor "<< valorBusqueda <<" en la pila.";
	}
	
	if(valorBusqueda == 0){
		cout<<endl<<"valor no valido";
	}
	
}

void CantidadNumerosImpares(int pila[10]){
	int contadorImpares = 0;

	for(int i = 0 ; i<10; i++){
		if(pila[i] % 2 != 0 && pila[i] != 0){
			contadorImpares++;
		}
	}
	
	cout<<endl<<"Tiene un total de "<< contadorImpares << " numeros impares \n"<<"------------------------------------------";;
	
}


void InvertirPila(int pila[10],int indice){
	if(indice == -1){
		cout<<endl<<"Pila Vacia \n";
	}
	
	int p = 0;
	int q = indice;
	
	while(p<q){
		
		pila[p] = pila[p] + pila[q];
		pila[q] = pila[p] - pila[q];
		pila[p] = pila[p] - pila[q];
		
		p++;
		q--;
	}
	
}

void imprimir(int pila[10],int indice){
	
	cout<<endl<<"\n------------------------------------------";
	
	for(int i = 9 ; i>=0; i--){
			cout<<endl<<"Pila ubicacion "<<i+1<<" Tiene valor :"<<pila[i];
	}
	cout<<endl<<"\n Indice: "<<indice<<"\n------------------------------------------";
	
	CantidadNumerosImpares(pila);
}

int main() {
	int pila[10],indice = -1,valor =0, seleccion=0;
	bool programaIniciado  = true;
	for(int i = 0 ; i<10; i++){
			pila[i] = 0;
	}
	
	cout<<endl<<"PILA \n";
	
	while(programaIniciado){
		
		cout<<endl<<"1.Insertar \n2.Eliminar \n3.Buscar \n4.Invertir cola \n5.Salir \n";
		cout<<endl<<"SELECCION:";
		cin>>seleccion;
		
		switch(seleccion) 
		{
		    case 1:
		    	indice = Insertar(pila,indice);
		    	imprimir(pila,indice);
		    break;
		    case 2:
		    	indice = Eliminar(pila,indice);
		    	imprimir(pila,indice);
		    break;
		    case 3:
				 Buscar(pila);
				 imprimir(pila,indice);
		    break;
		    case 4:
				 InvertirPila(pila,indice);
				 imprimir(pila,indice);
		    break;
		    case 5:
				 programaIniciado = false;
		    break;
		    
		    default:
				cout<<endl<<"Seleccion no valida\n";
			break; 
		}
	} 
}
