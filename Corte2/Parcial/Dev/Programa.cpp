/*
	--- Segunda Evaluación Parcial --- 
	
	Nombre: Stiven Daniel Melo Guayazan
	Grupo: Estructuras de Datos -- Grupo 5
*/

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Lista {
public:
    Nodo* inicio;
    Nodo* Modulo3;

public:
    Lista() {
        inicio = NULL;
		Modulo3 = NULL; 
    }

    void insertarPorDerecha(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = NULL;  

        if (inicio == NULL) {  
            inicio = nuevoNodo;
        } else {
            Nodo* temp = inicio;
            while (temp->siguiente != NULL) { 
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void insertarPorIzquierda(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
    }
    
    void GenerarNodoModulo() {
    	
    	Nodo* tempIni = inicio;
    	Nodo* tempMod = Modulo3;
    	
        while (tempIni != NULL) {  
        	
        	if(tempIni->dato % 3 == 1){
        		Nodo* nuevoNodo = new Nodo;
        		
		        nuevoNodo->dato = tempIni->dato;
		        nuevoNodo->siguiente = NULL;  
		        
		        if (Modulo3 == NULL) {  
	            Modulo3 = nuevoNodo;
		        } else {
		            Nodo* tempR = Modulo3;
		            while (tempR->siguiente != NULL) { 
		                tempR = tempR->siguiente;
		            }
		            tempR->siguiente = nuevoNodo;
		        }
			}
            tempIni = tempIni->siguiente;
        }
    }

    void eliminarPorDerecha() {
        if (inicio == NULL) {  
            cout << "La lista esta vacia." << endl;
            return;
        }

        Nodo* temp = inicio;
        Nodo* prev = NULL;  

        while (temp->siguiente != NULL) {  
            prev = temp;
            temp = temp->siguiente;
        }

        if (prev == NULL) {  
            delete inicio;
            inicio = NULL;  
        } else {
            delete temp;
            prev->siguiente = NULL;  
        }
    }

    void eliminarPorIzquierda() {
        if (inicio == NULL) {  
            cout << "La lista esta vacia." << endl;
            return;
        }

        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }

    void mostrarLista(Nodo* nodoImprimir) {
        Nodo* temp = nodoImprimir;
        while (temp != NULL) {  
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    void ContarNodosPares() {
    	int nodosPares = 0;
    	
        Nodo* temp = inicio;
        while (temp != NULL) {  
            if(temp->dato % 2 == 0){
            	nodosPares++;
			}
			temp = temp->siguiente;
        }
        cout << "Nodos Pares: "<< nodosPares << endl;
    }
    
    
    
    void Buscar( int valorBuscar){
        
        if (inicio == NULL) { // Reemplaza nullptr con NULL
            cout << "La lista esta vacia." << endl;
            return;
        }
        
        Nodo* temp = inicio;
        bool existe = false;
        
        while(temp != NULL){
            if(temp->dato == valorBuscar){
                existe = true;
            }
            temp = temp->siguiente;
        }
        
        if(existe == true){
            cout<< "\nElemento "<<valorBuscar<<" SI a sido encontrado en lista\n";
        }
         else{
             cout<< "\nElemento "<<valorBuscar<<" NO a sido encontrado en lista\n";
         }
    }
};

int main() {
    Lista lista;
    int opcion, valor, valorBusqueda;

    do {
        cout << "\n1. Insertar por derecha" << endl;
        cout << "2. Insertar por izquierda" << endl;
        cout << "3. Eliminar por derecha" << endl;
        cout << "4. Eliminar por izquierda" << endl;
        cout << "5. Contrar nodos Pares" << endl;
        cout << "6. Modulo3" << endl;
        cout << "7. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nIngresa un valor: ";
                cin >> valor;
                lista.insertarPorDerecha(valor);
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista(lista.inicio);
                break;
            case 2:
                cout << "\nIngresa un valor: ";
                cin >> valor;
                lista.insertarPorIzquierda(valor);
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista(lista.inicio);
                break;
            case 3: 
            	cout << "\n-- Se elimino correctamente por derecha --\n";
                lista.eliminarPorDerecha();
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista(lista.inicio);
                break;
            case 4:
            	cout << "\n-- Se elimino correctamente por izquierda --\n";
                lista.eliminarPorIzquierda();
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista(lista.inicio);
                break;
            case 5:
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista(lista.inicio);
                cout << "\n";
                lista.ContarNodosPares();
                break;
            case 6:
                lista.GenerarNodoModulo();
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista(lista.inicio);
                cout << "\nLa lista Modulo actualmente es: ";
                lista.mostrarLista(lista.Modulo3);
                lista.Modulo3 = NULL;
                cout << "\n";
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta. Intentalo de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}
