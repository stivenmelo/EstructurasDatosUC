#include <iostream>
using namespace std;

struct ColaCircular {
    int frente, fin;
    int capacidad;
    int* elementos;
};

ColaCircular crearCola(int capacidad) {
    ColaCircular cola;
    cola.frente = cola.fin = -1;
    cola.capacidad = capacidad;
    cola.elementos = new int[capacidad];
    return cola;
}

bool estaLlena(ColaCircular cola) {
    return (cola.frente == 0 && cola.fin == cola.capacidad - 1) || (cola.frente == cola.fin + 1);
}

bool estaVacia(ColaCircular cola) {
    return cola.frente == -1;
}

void Insertar(ColaCircular& cola, int valor) {
    if (estaLlena(cola)) {
        cout << "La cola está llena. No se puede insertar." << endl;
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
        cout << "La cola está vacía. No se puede eliminar." << endl;
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
        cout << "La cola está vacía." << endl;
        return;
    }

    cout << "Contenido de la cola:" << endl;
    int i = cola.frente;
    if (i <= cola.fin) {
        while (i <= cola.fin)
            cout << cola.elementos[i++] << " ";
    } else {
        while (i < cola.capacidad)
            cout << cola.elementos[i++] << " ";
        i = 0;
        while (i <= cola.fin)
            cout << cola.elementos[i++] << " ";
    }
    cout << endl;
}

int main() {
    int capacidad;
    cout << "Ingrese la capacidad de la cola circular: ";
    cin >> capacidad;

    ColaCircular cola = crearCola(capacidad);

    while (true) {
        cout << "1. Insertar\n2. Eliminar\n3. Salir" << endl;
        int seleccion;
        cout << "Seleccione una opción: ";
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
                cout << "Opción no válida." << endl;
                break;
        }

        Imprimir(cola);
    }

    return 0;
}
