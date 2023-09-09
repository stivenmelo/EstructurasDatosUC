#include <iostream>
using namespace std;

/*

Ejecicio Cola Circular

Creado por:
	-JOHAN SEBASTIAN VARGAS SANCHEZ
	-STIVEN DANIEL MELO GUAYAZAN
	
	2023-09-09 
*/

struct ColaCircular {
    int frente, fin;
    int capacidad;
    int* elementos;
};

ColaCircular crearCola() {
    ColaCircular cola;
    cola.frente = cola.fin = -1;
    cola.capacidad = 5;
    cola.elementos = new int[5];
    return cola;
}

bool estaLlena(ColaCircular cola) {
    return (cola.frente == 0 && cola.fin == cola.capacidad - 1) || (cola.frente == cola.fin + 1);
}

bool estaVacia(ColaCircular cola) {
    return cola.frente == -1;
}

void Insertar(ColaCircular& cola, int valor) {
	
	if (valor == 0) {
        cout << "Valor no valido, no puede cer 0 " << endl;
        return;
    }
	
    if (estaLlena(cola)) {
        cout << "La cola esta llena. No se puede insertar." << endl;
        return;
    }

    if (cola.frente == -1)
        cola.frente = cola.fin = 0;
    else if (cola.fin == cola.capacidad - 1)
        cola.fin = 0;
    else
        cola.fin++;

    cola.elementos[cola.fin] = valor;
    cout << "Elemento insertado: " << valor << endl;
}

void Eliminar(ColaCircular& cola) {
    if (estaVacia(cola)) {
        cout << "La cola esta vacia. No se puede eliminar." << endl;
        return;
    }

    int elementoEliminado = cola.elementos[cola.frente];
    cola.elementos[cola.frente] = 0;

    if (cola.frente == cola.fin)
        cola.frente = cola.fin = -1;
    else if (cola.frente == cola.capacidad - 1)
        cola.frente = 0;
    else
        cola.frente++;

    cout << "Elemento eliminado: " << elementoEliminado << endl;
}

void Imprimir(ColaCircular cola) {
    if (estaVacia(cola)) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    cout << "Contenido de la cola:" << endl;
    
    cout<<endl<<"------------------------------------------";
	for(int i = 0 ; i<5; i++){
			cout<<endl<<"Cola ubicacion "<<i+1<<" Tiene valor :"<<cola.elementos[i];
	}
	cout<<endl<<"indice Inicio: "<<cola.frente;
	cout<<endl<<"indice Fin: "<<cola.fin;
	cout<<endl<<"\n------------------------------------------\n";

}

int main() {

    ColaCircular cola = crearCola();

	for(int i = 0 ; i<5; i++){
			cola.elementos[i] = 0;
	}
	
    while (true) {
        cout << "1. Insertar\n2. Eliminar\n3. Salir" << endl;
        int seleccion;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion) {
            case 1:
                int valor;
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                Insertar(cola, valor);
                break;
            case 2:
                Eliminar(cola);
                break;
            case 3:
                return 0;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }

        Imprimir(cola);
    }

    return 0;
}
