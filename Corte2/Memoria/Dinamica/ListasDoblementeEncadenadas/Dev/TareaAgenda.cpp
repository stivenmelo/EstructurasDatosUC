/*
	--- Taller Lista en Memoria Dinamica --- 
	
	** Metodos utilizados :  insertarPorDerecha, insertarPorIzquierda, eliminarPorIzquierda, 
	eliminarPorDerecha, Buscar, mostrarLista **
	
	NOTA: No se utilizo malloc en una variable de localizar debido a que al realizar una busqueda de la documentacion vimos
	mas complejo utilizar el puntero, asi que se ideo una nueva forma dentro de una clase, utilizando conocimientos basicos 
	de progrmacion orientada a objetos y por medio de un contructor darle un valor directamente inicial al puntero. 
	
	Nombres: Johan Sebastian Vargas Sanchez & Stiven Daniel Melo Guayazan
	Grupo: Estructuras de Datos -- Grupo 5
*/

#include <iostream>
using namespace std;

struct Nodo {
	Nodo* Anterior;
    long Codigo;
    char Nombre[50];
    long Telefono;
    Nodo* Siguiente;
};

class Lista {
private:
    Nodo* inicio;

public:
    Lista() {
        inicio = NULL;  
    }

    void Insertar(long Codigo,char Nombre[50],long Telefono) {
    	
    	//To Do hacer logica para que sea ordenamiento de menor a mayor
    	
        Nodo* nuevoNodo = new Nodo;
        
        nuevoNodo->Anterior = null;
        
        nuevoNodo->Codigo = Codigo;
        nuevoNodo->Nombre = Nombre;
        nuevoNodo->Telefono = Telefono;

        nuevoNodo->Siguiente = NULL;  

        if (inicio == NULL) {  
            inicio = nuevoNodo;
        } else {
            Nodo* temp = inicio;
            while (temp->siguiente != NULL) { 
                temp = temp->Siguiente;
            }
            temp->Siguiente = nuevoNodo;
            temp->Siguiente->Anterior = temp;
            temp->Siguiente->Siguiente = null;
        }
    }

    void insertarPorIzquierda(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
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

    void mostrarLista() {
        Nodo* temp = inicio;
        while (temp != NULL) {  
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
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
        cout << "5. Buscar" << endl;
        cout << "6. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nIngresa un valor: ";
                cin >> valor;
                lista.insertarPorDerecha(valor);
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista();
                break;
            case 2:
                cout << "\nIngresa un valor: ";
                cin >> valor;
                lista.insertarPorIzquierda(valor);
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista();
                break;
            case 3: 
            	cout << "\n-- Se elimino correctamente por derecha --\n";
                lista.eliminarPorDerecha();
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista();
                break;
            case 4:
            	cout << "\n-- Se elimino correctamente por izquierda --\n";
                lista.eliminarPorIzquierda();
                cout << "\nLa lista actualmente es: ";
                lista.mostrarLista();
                break;
            case 5:
            	cout << "\nIngresa un valor que desea buscar: ";
                cin >> valorBusqueda;
                lista.Buscar(valorBusqueda);
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta. Intentalo de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}
