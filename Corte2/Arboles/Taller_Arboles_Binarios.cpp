#include <iostream>
using namespace std;
/*
	--- Taller Arboles - Inserciones Arbol Binario  --- 	
		
	Nota: El taller fue realizado con clases con el fin de realizar las declaraciones de forma mas amena y limpia, con el fin de que al leer el codigo sea mucho mas
	sencillo.
	
	Nombres: Johan Sebastian Vargas Sanchez & Stiven Daniel Melo Guayazan
	Grupo: Estructuras de Datos -- Grupo 5
*/

struct NodoArb {
    int dato;
    NodoArb* izq;
    NodoArb* der;
    
    // Declaracion del constructor y asignacion de valores paralos argumentos.

    NodoArb(int valor) : dato(valor), izq(NULL), der(NULL) {} 
};

class ArbolBinario {
private:
    NodoArb* raiz;

    NodoArb* insertarRecursivo(NodoArb* nodo, int valor) {
        if (nodo == NULL) {
            return new NodoArb(valor);
        }
        if (valor < nodo->dato) {
            nodo->izq = insertarRecursivo(nodo->izq, valor);
        } else if (valor > nodo->dato) {
            nodo->der = insertarRecursivo(nodo->der, valor);
        }
        return nodo;
    }
    
	NodoArb* buscarRecursivo(NodoArb* nodo, int valor) {
	    if (nodo == NULL || nodo->dato == valor) {
	        return nodo;
	    }
	
	    if (valor < nodo->dato) {
	        return buscarRecursivo(nodo->izq, valor);
	    } else {
	        return buscarRecursivo(nodo->der, valor);
	    }
	}

    NodoArb* buscarMinimo(NodoArb* nodo) {
        while (nodo->izq != NULL) {
            nodo = nodo->izq;
        }
        return nodo;
    }

    NodoArb* eliminarRecursivo(NodoArb* nodo, int valor) {		
			
		if (nodo == NULL) {
            return nodo;
        }
        if (valor < nodo->dato) {
            nodo->izq = eliminarRecursivo(nodo->izq, valor);
        } else if (valor > nodo->dato) {
            nodo->der = eliminarRecursivo(nodo->der, valor);
        } else {
            if (nodo->izq == NULL) {
                NodoArb* temp = nodo->der;
                delete nodo;
                return temp;
            } else if (nodo->der == NULL) {
                NodoArb* temp = nodo->izq;
                delete nodo;
                return temp;
            }
            NodoArb* temp = buscarMinimo(nodo->der);
            nodo->dato = temp->dato;
            nodo->der = eliminarRecursivo(nodo->der, temp->dato);
        }
        return nodo;
    }

    void imprimirPreOrden(NodoArb* nodo) {
        if (nodo != NULL) {
            cout << nodo->dato << " ";
            imprimirPreOrden(nodo->izq);
            imprimirPreOrden(nodo->der);
        }
    }

    void imprimirInOrden(NodoArb* nodo) {
        if (nodo != NULL) {
            imprimirInOrden(nodo->izq);
            cout << nodo->dato << " ";
            imprimirInOrden(nodo->der);
        }
    }

    void imprimirPosOrden(NodoArb* nodo) {
        if (nodo != NULL) {
            imprimirPosOrden(nodo->izq);
            imprimirPosOrden(nodo->der);
            cout << nodo->dato << " ";
        }
    }

public:
    ArbolBinario() : raiz(NULL) {}

    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void buscar(int valor) {
        NodoArb* resultado = buscarRecursivo(raiz, valor);
        if (resultado != NULL) {
            cout << "\nEl valor " << valor << " se encontro en el arbol." << endl;
        } else {
            cout << "\nEl valor " << valor << " no se encontro en el arbol." << endl;
        }
    }

    void buscarYEliminar(int valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }

    void imprimirPreOrden() {
        imprimirPreOrden(raiz);
        cout << endl;
    }

    void imprimirInOrden() {
        imprimirInOrden(raiz);
        cout << endl;
    }

    void imprimirPosOrden() {
        imprimirPosOrden(raiz);
        cout << endl;
    }
};

int main() {
    ArbolBinario abb;
    int opcion, valor;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Buscar y eliminar" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                abb.insertar(valor);
                cout << "\nArbol despues de la insercion (preorden): ";
                abb.imprimirPreOrden();
                cout << "\nArbol despues de la insercion (inorden): ";
                abb.imprimirInOrden();
                cout << "\nArbol despues de la insercion (posorden): ";
                abb.imprimirPosOrden();
                break;
            case 2:
                cout << "Ingrese un valor a buscar: ";
                cin >> valor;
                abb.buscar(valor);
                break;
            case 3:
                cout << "Ingrese un valor a buscar y eliminar: ";
                cin >> valor;
                abb.buscar(valor);
                abb.buscarYEliminar(valor);
                cout << "\nArbol despues de la eliminacion (preorden): ";
                abb.imprimirPreOrden();
                cout << "\nArbol despues de la eliminacion (inorden): ";
                abb.imprimirInOrden();
                cout << "\nArbol despues de la eliminacion (posorden): ";
                abb.imprimirPosOrden();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
