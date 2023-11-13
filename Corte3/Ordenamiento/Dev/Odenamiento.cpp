#include <iostream>

const int arregloSize = 20;

class Ordenamiento {
public:
    Ordenamiento() {
        // Inicializa el arreglo con valores específicos
        int valoresIniciales[20] = {64, 34, 25, 12, 22, 11, 90, 43, 4, 99, 45, 55, 66, 78, 89, 76, 54, 2, 3, 1};
        for (int i = 0; i < arregloSize; ++i) {
            arreglo[i] = valoresIniciales[i];
        }
    }

    void reinicializar() {
        // Reinicializa el arreglo con valores específicos
        int valoresIniciales[20] = {64, 34, 25, 12, 22, 11, 90, 43, 4, 99, 45, 55, 66, 78, 89, 76, 54, 2, 3, 1};
        for (int i = 0; i < arregloSize; ++i) {
            arreglo[i] = valoresIniciales[i];
        }
    }

    void imprimirArreglo() {
        for (int i = 0; i < arregloSize; ++i) {
            std::cout << arreglo[i] << " ";
        }
        std::cout << std::endl;
    }

    void bubbleSort() {
        for (int i = 0; i < arregloSize - 1; ++i) {
            for (int j = 0; j < arregloSize - i - 1; ++j) {
                if (arreglo[j] > arreglo[j + 1]) {
                    // Intercambia elementos
                    int temp = arreglo[j];
                    arreglo[j] = arreglo[j + 1];
                    arreglo[j + 1] = temp;
                }
            }
        }
    }

    void shellSort() {
        for (int gap = arregloSize / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < arregloSize; ++i) {
                int temp = arreglo[i];
                int j;
                for (j = i; j >= gap && arreglo[j - gap] > temp; j -= gap) {
                    arreglo[j] = arreglo[j - gap];
                }
                arreglo[j] = temp;
            }
        }
    }

    void radixSort() {
        int maximo = encontrarMaximo();
        for (int exp = 1; maximo / exp > 0; exp *= 10) {
            contarSort(exp);
        }
    }
void heapifyMonti(int arreglo[], int arregloSize, int i) {
    int mayor = i; // Inicializa el mayor como la raíz
    int izquierda = 2 * i + 1; // índice izquierdo del hijo
    int derecha = 2 * i + 2; // índice derecho del hijo

    // Si el hijo izquierdo es mayor que la raíz
    if (izquierda < arregloSize && arreglo[izquierda] > arreglo[mayor])
        mayor = izquierda;

    // Si el hijo derecho es mayor que la raíz
    if (derecha < arregloSize && arreglo[derecha] > arreglo[mayor])
        mayor = derecha;

    // Si el mayor no es la raíz
    if (mayor != i) {
        std::swap(arreglo[i], arreglo[mayor]);

        // Recursivamente hacer heapify en el subárbol afectado
        heapifyMonti(arreglo, arregloSize, mayor);
    }
}

void heapSort() {
    // Construye el monticulo (reorganiza el arreglo)
    for (int i = arregloSize / 2 - 1; i >= 0; i--)
        heapifyMonti(arreglo, arregloSize, i);

    // Extrae un elemento del montículo uno por uno
    for (int i = arregloSize - 1; i > 0; i--) {
        // Mueve la raíz al final
        std::swap(arreglo[0], arreglo[i]);

        // llama a heapify en el monticulo reducido
        heapifyMonti(arreglo, i, 0);
    }
}

private:
    int arreglo[arregloSize];

    int encontrarMaximo() {
        int max = arreglo[0];
        for (int i = 1; i < arregloSize; ++i) {
            if (arreglo[i] > max) {
                max = arreglo[i];
            }
        }
        return max;
    }

    void contarSort(int exp) {
        int resultado[arregloSize];
        int conteo[10] = {0};

        for (int i = 0; i < arregloSize; ++i) {
            conteo[(arreglo[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i) {
            conteo[i] += conteo[i - 1];
        }

        for (int i = arregloSize - 1; i >= 0; --i) {
            resultado[conteo[(arreglo[i] / exp) % 10] - 1] = arreglo[i];
            conteo[(arreglo[i] / exp) % 10]--;
        }

        for (int i = 0; i < arregloSize; ++i) {
            arreglo[i] = resultado[i];
        }
    }
};

int main() {
    Ordenamiento ordenamiento;

    int opcion;
    bool reinicializar = false;

    while (true) {

        std::cout << "\nElije una opcion:\n";
        std::cout << "1. Ordenar con Bubble Sort\n";
        std::cout << "2. Ordenar con Shell Sort\n";
        std::cout << "3. Ordenar con Radix Sort\n";
        std::cout << "4. Reinicializar el arreglo\n";
        std::cout << "5. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
            	ordenamiento.reinicializar();
            	std::cout << "Arreglo Original: ";
            	ordenamiento.imprimirArreglo();
                ordenamiento.bubbleSort();
                std::cout << "Arreglo ordenado con Bubble Sort: ";
                ordenamiento.imprimirArreglo();
                break;
            case 2:
            	ordenamiento.reinicializar();
            	std::cout << "Arreglo Original: ";
            	ordenamiento.imprimirArreglo();
                ordenamiento.shellSort();
                std::cout << "Arreglo ordenado con Shell Sort: ";
                ordenamiento.imprimirArreglo();
                break;
            case 3:
            	ordenamiento.reinicializar();
            	std::cout << "Arreglo Original: ";
            	ordenamiento.imprimirArreglo();
                ordenamiento.radixSort();
                std::cout << "Arreglo ordenado con Radix Sort: ";
                ordenamiento.imprimirArreglo();
                break;
            case 4:
                ordenamiento.reinicializar();
                std::cout << "Arreglo Original: ";
            	ordenamiento.imprimirArreglo();
                break;
			case 5:
			    ordenamiento.reinicializar();
			    std::cout << "Arreglo Original: ";
			    ordenamiento.imprimirArreglo();
			    ordenamiento.heapSort();
			    std::cout << "Arreglo ordenado con Heap Sort: ";
			    ordenamiento.imprimirArreglo();
			    break;
            case 6:
                return 0;
            default:
                std::cout << "Opción no valida. Intentalo de nuevo.\n";
        }
    }

    return 0;
}
