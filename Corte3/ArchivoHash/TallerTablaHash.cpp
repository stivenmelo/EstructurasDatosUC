#include <iostream>
#include <string>
#include <vector>


/* 
	--- Taller Metodos Tabla Hash --- 
	
	** Nombres: Johan Sebastian Vargas Sanchez & Stiven Daniel Melo Guayazan
	Grupo: Estructuras de Datos -- Grupo 5

*/
using namespace std;

// Funcion hash 1
int hashFunction1(string input) {
    int sum = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        sum += int(input[i]);
    }

    size_t length = input.length();
    size_t centerStart = (length > 5) ? (length - 3) / 2 : 0;
    size_t centerEnd = (length > 5) ? centerStart + 2 : 0;

    return sum % 7;
}

// Funcion hash 2
int hashFunction2(string input) {
    int sum = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        sum += int(input[i]);
    }

    size_t length = input.length();
    size_t centerStart = (length > 5) ? (length - 3) / 2 : 0;
    size_t centerEnd = (length > 5) ? centerStart + 2 : 0;

    return sum % 13;
}

// Funcion hash 3
int hashFunction3(string input) {
    int sum = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        sum += int(input[i]);
    }

    size_t length = input.length();
    size_t centerStart = (length > 5) ? (length - 3) / 2 : 0;
    size_t centerEnd = (length > 5) ? centerStart + 2 : 0;

    return sum % 11;
}

int main() {
    vector<string> apellidos;
    apellidos.push_back("Gonzalez");
    apellidos.push_back("Rodriguez");
    apellidos.push_back("Lopez");
    apellidos.push_back("Martinez");
    apellidos.push_back("Perez");
    apellidos.push_back("Gomez");
    apellidos.push_back("Sanchez");
    apellidos.push_back("Diaz");
    apellidos.push_back("Hernandez");
    apellidos.push_back("Torres");

    cout << "Resultados de las funciones hash para los apellidos:\n";
    cout << "---------------------------------------------\n";
    for (size_t i = 0; i < apellidos.size(); ++i) {
        cout << "Apellido: " << apellidos[i] << endl;
        cout << "Resultado Hash 1: " << hashFunction1(apellidos[i]) << endl;
        cout << "Resultado Hash 2: " << hashFunction2(apellidos[i]) << endl;
        cout << "Resultado Hash 3: " << hashFunction3(apellidos[i]) << endl;
        cout << "---------------------------------------------\n";
    }

    return 0;
}
