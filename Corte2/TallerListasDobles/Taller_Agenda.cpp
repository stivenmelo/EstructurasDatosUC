#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
    Nodo* ant;
    int codigo;
    string nombre;
    string telefono;
    string correo;
    Nodo* sig;

    Nodo(int _codigo, string _nombre, string _telefono, string _correo)
        : ant(NULL), codigo(_codigo), nombre(_nombre), telefono(_telefono), correo(_correo), sig(NULL) {}
};

class Agenda {
public:
    Nodo* cab;

    Agenda() : cab(NULL) {}

    void insertar(int codigo, string nombre, string telefono, string correo) {
        Nodo* nuevo = new Nodo(codigo, nombre, telefono, correo);

        if (!cab) {
            cab = nuevo;
        } else {
            Nodo* actual = cab;
            while (actual->sig && actual->codigo < codigo) {
                actual = actual->sig;
            }

            if (actual->codigo < codigo) {
                nuevo->ant = actual;
                actual->sig = nuevo;
            } else {
                nuevo->ant = actual->ant;
                actual->ant = nuevo;
                nuevo->sig = actual;
                if (nuevo->ant)
                    nuevo->ant->sig = nuevo;
                else
                    cab = nuevo;
            }
        }
    }

    Nodo* buscar(int codigo) {
        Nodo* actual = cab;
        while (actual && actual->codigo != codigo) {
            actual = actual->sig;
        }
        return actual;
    }

    void eliminar(int codigo) {
        Nodo* nodoAEliminar = buscar(codigo);
        if (nodoAEliminar) {
            if (nodoAEliminar->ant) {
                nodoAEliminar->ant->sig = nodoAEliminar->sig;
            } else {
                cab = nodoAEliminar->sig;
            }
            if (nodoAEliminar->sig) {
                nodoAEliminar->sig->ant = nodoAEliminar->ant;
            }
            delete nodoAEliminar;
            cout << "Nodo eliminado correctamente.\n";
        } else {
            cout << "Nodo no encontrado.\n";
        }
    }

    void imprimir() {
        Nodo* actual = cab;
        while (actual) {
            cout << "codigo: " << actual->codigo << ", Nombre: " << actual->nombre
                << ", telefono: " << actual->telefono << ", Correo: " << actual->correo << "\n";
            actual = actual->sig;
        }
    }
};

int main() {
    Agenda lista;
    int opcion, codigo;
    string nombre, telefono, correo;

    do {
        cout << "Menu:\n";
        cout << "1. Insertar\n";
        cout << "2. Buscar por codigo\n";
        cout << "3. Eliminar por codigo\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el codigo: ";
                cin >> codigo;
                cout << "Ingrese el nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el telefono: ";
                cin >> telefono;
                cout << "Ingrese el correo: ";
                cin >> correo;
                lista.insertar(codigo, nombre, telefono, correo);
                lista.imprimir();
                break;
            }
            case 2: {
                cout << "Ingrese el codigo a buscar: ";
                cin >> codigo;
                Nodo* encontrado = lista.buscar(codigo);
                if (encontrado) {
                    cout << "Nodo encontrado:\n";
                    cout << "codigo: " << encontrado->codigo << ", Nombre: " << encontrado->nombre
                        << ", telefono: " << encontrado->telefono << ", Correo: " << encontrado->correo << "\n";
                } else {
                    cout << "Nodo no encontrado.\n";
                }
                break;
            }
            case 3: {
                cout << "Ingrese el codigo a eliminar: ";
                cin >> codigo;
                lista.eliminar(codigo);
                lista.imprimir();
                break;
            }
            case 4: {
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opcion no valida. Intentalo de nuevo.\n";
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}
