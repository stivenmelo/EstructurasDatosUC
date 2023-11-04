#include <iostream>
using namespace std;


/*

stiven daniel melo guayazan
Y
johan sebastian vargas sanchez


Entrada

5
0 3 0 0 0
0 0 1 7 0
0 0 0 2 0
0 0 0 0 5
0 0 0 0 0
Ingrese el nodo de inicio y el nodo final: 1 4

*/


const int MAX_N = 10;
const int INF = 99999; // Un valor grande que representa infinito.

int grafos[MAX_N][MAX_N];
int distancia[MAX_N][MAX_N];
int ruta[MAX_N][MAX_N];

void reconstruirRuta(int start, int end) {
    if (ruta[start][end] == -1) {
        cout << "No hay ruta de " << start << " a " << end << endl;
        return;
    }

    int intermediate = ruta[start][end];
    if (intermediate == start) {
        cout << start << " -> " << end << endl;
    } else {
        reconstruirRuta(start, intermediate);
        reconstruirRuta(intermediate, end);
    }
}

int main() {
    int N; // Número de vértices en el grafo.
    cin >> N;

    // Leer la matriz de adyacencia del grafo.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grafos[i][j];
            if (i != j && grafos[i][j] == 0) {
                grafos[i][j] = INF; // Si no hay conexión directa, establecer infinito.
            }
            ruta[i][j] = -1; // Inicializar la matriz de rutas.
        }
    }

    // Inicializar la matriz de distancias mínimas.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distancia[i][j] = grafos[i][j];
        }
    }

    // Algoritmo de Floyd-Warshall para encontrar las distancias mínimas.
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (distancia[i][k] + distancia[k][j] < distancia[i][j]) {
                    distancia[i][j] = distancia[i][k] + distancia[k][j];
                    ruta[i][j] = k;
                }
            }
        }
    }

    int start, end;
    cout << "Ingrese el nodo de inicio y el nodo final: ";
    cin >> start >> end;

    cout << "La distancia mínima entre " << start << " y " << end << " es: ";
    if (distancia[start][end] == INF) {
        cout << "INF" << endl;
    } else {
        cout << distancia[start][end] << endl;
        cout << "Ruta más corta: " << start << " -> ";
        reconstruirRuta(start, end);
    }

    return 0;
}

