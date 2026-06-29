#include <iostream>
#include <cstdlib>  // Contiene rand() y srand() para los números aleatorios
#include <ctime>    // Contiene clock(), clock_t y CLOCKS_PER_SEC
#include "arreglos.h"


using namespace std;

void copiarArreglo(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

int main() {
    srand(time(NULL)); // Inicializa la semilla aleatoria

    // Imprime la cabecera en formato tabular (separado por tabulaciones '\t')
    std::cout << "Tamano\tBurbuja\tSeleccion\tInsercion\tMerge\tQuick\n";

    // Bucle que recorre las 10 longitudes requeridas
    for (int n = 500; n <= 5000; n += 500) {
        
        // Uso de memoria dinámica (new) para evitar Stack Overflow con arreglos grandes
        int* original = new int[n];
        int* auxiliar = new int[n];

        // Llenado del arreglo con valores aleatorios
        for (int i = 0; i < n; i++) {
            original[i] = rand() % 10000; // Números entre 0 y 9999
        }

        std::cout << n << "\t";

        // ================= PREPARACIÓN Y MEDICIÓN DE CADA ALGORITMO =================

        // 1. BURBUJA
        copiarArreglo(original, auxiliar, n);
        clock_t inicio = clock();
        bubbleSort(auxiliar, n);
        clock_t fin = clock();
        double t_burbuja = (double)(fin - inicio) / CLOCKS_PER_SEC;
        std::cout << t_burbuja << "\t";

        // 2. SELECCIÓN
        copiarArreglo(original, auxiliar, n);
        inicio = clock();
        selectionSort(auxiliar, n);
        fin = clock();
        double t_seleccion = (double)(fin - inicio) / CLOCKS_PER_SEC;
        std::cout << t_seleccion << "\t";

        // 3. INSERCIÓN
        copiarArreglo(original, auxiliar, n);
        inicio = clock();
        insertionSort(auxiliar, n);
        fin = clock();
        double t_insercion = (double)(fin - inicio) / CLOCKS_PER_SEC;
        std::cout << t_insercion << "\t";

        // 4. MERGE SORT
        copiarArreglo(original, auxiliar, n);
        inicio = clock();
        mergeSort(auxiliar, 0, n - 1);
        fin = clock();
        double t_merge = (double)(fin - inicio) / CLOCKS_PER_SEC;
        std::cout << t_merge << "\t";

        // 5. QUICK SORT
        copiarArreglo(original, auxiliar, n);
        inicio = clock();
        quickSort(auxiliar, 0, n - 1);
        fin = clock();
        double t_quick = (double)(fin - inicio) / CLOCKS_PER_SEC;
        std::cout << t_quick << "\n";

        // Liberación de memoria dinámica
        delete[] original;
        delete[] auxiliar;
    }

    return 0;
}

