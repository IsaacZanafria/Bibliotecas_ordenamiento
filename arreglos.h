//#ifdef ARREGLOS_H
//#define ARREGLOS_H

#define PI 3.1416

#define CUADRADO(x) ((x)*(x))

//#define DEBUG

int sumaArreglo(int arr[], int n);
int maximo(int arr[], int n);
void cuadradoArreglo(int arr[], int n);
void imprimirArreglo(int arr[], int n);
int busquedaLineal(int arr[], int n, int objetivo);
int busquedaBinariaIterativa(int arr[], int n, int objetivo);
int busquedaBinariaRecursiva(int arr[], int n, int objetivo, int inicio, int fin);
void bubbleSort(int arr[],int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int inicio, int fin);
void merge(int arr[], int inicio, int mit, int fin);
void intercambiar (int &a, int &b);
int particionar(int arr[], int incio, int fin);
void quickSort(int arr[], int inicio, int fin);
//#endif

// mit = (inicio + fin)/2  inicio > fin 
