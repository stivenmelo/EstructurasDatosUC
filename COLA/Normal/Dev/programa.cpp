#include <iostream>
#include <string.h>
using namespace std;

struct Indices{
	int Inico;
	int Fin;

};

void Imprimir(int cola[5],struct Indices indiceCola){
	cout<<endl<<"\n------------------------------------------";
	for(int i = 0 ; i<5; i++){
			cout<<endl<<"Cola ubicacion "<<i+1<<" Tiene valor :"<<cola[i];
	}
	cout<<endl<<"indice Inicio: "<<indiceCola.Inico;
	cout<<endl<<"indice Fin: "<<indiceCola.Fin;
	cout<<endl<<"\n------------------------------------------";
}

struct Indices Insertar(int cola[5],struct Indices indiceCola){
	int valor;
	if(indiceCola.Fin == -1){
		
		cout<<"Digite el valor: ";
		cin>>valor;
		
		indiceCola.Inico = 0;
		indiceCola.Fin = 0;
		
		cola[indiceCola.Fin] = valor;
	}
	else if(indiceCola.Fin == 4){
		cout<<endl<<"-----------------Cola llena-----------------\n";
		cout<<endl<<"\n------------------------------------------";
	}
	else
	{
		cout<<"Digite el valor: ";
		cin>>valor;
		indiceCola.Fin = indiceCola.Fin + 1;
		cola[indiceCola.Fin] = valor;	
	}
	
	Imprimir(cola,indiceCola);
	
	return indiceCola;
}




int main()
{
	//Inicializar variables
	int cola[5], seleccion=0;
	struct Indices indiceCola;
	bool programaIniciado  = true;
	
	//Asignar valores variables
	indiceCola.Fin = -1;
	indiceCola.Inico = -1;
	
	for(int i = 0 ; i<5; i++){
			cola[i] = 0;
	}
	
	//Inicio programa
	
	cout<<endl<<"Programa COLA \n";
	
	while(programaIniciado){
		
		cout<<endl<<"1.Insertar \n2.Eliminar \n3.salir\n";
		cout<<endl<<"SELECCION:";
		cin>>seleccion;
		
		switch(seleccion) 
		{
		    case 1:
		    	indiceCola = Insertar(cola,indiceCola);
		    break;
		    case 2:
		    	//indiceCola = Eliminar(cola,indiceCola);
		    break;
		    case 3:
				 programaIniciado = false;
		    break;
		    
		    default:
				cout<<endl<<"Seleccion no valida\n";
			break; 
		}
	}
	
	//Fin programa
}
