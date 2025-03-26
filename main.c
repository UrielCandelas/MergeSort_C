#include <stdio.h>

void merge(int *arr, int inicio, int fin, int medio)
{
  int tam1 = (medio - inicio) + 1;
  int tam2 = fin - medio;

  int A[tam1];
  int B[tam2];

  for (int i = 0; i < tam1; i++)
  {
    A[i] = arr[inicio + i];
  }
  for (int i = 0; i < tam2; i++)
  {
    B[i] = arr[medio + 1 + i];
  }

  int i = 0, j = 0;
  int k = inicio;
  while (i < tam1 && j < tam2)
  {
    if (A[i] <= B[j])
    {
      arr[k] = A[i];
      i++;
    }
    else
    {
      arr[k] = B[j];
      j++;
    }
    k++;
  }
  while (i < tam1)
  {
    arr[k] = A[i];
    i++;
    k++;
  }
  while (j < tam2)
  {
    arr[k] = B[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr, int inicio, int fin)
{
  if (inicio < fin)
  {
    int medio = (inicio + fin) / 2;
    mergeSort(arr, inicio, medio);
    mergeSort(arr, medio + 1, fin);
    merge(arr, inicio, fin, medio);
  }
}

int main(void)
{
  int SIZE;
  printf("Ingrese la cantidad de elementos para el array\n");
  scanf("%d", &SIZE);
  int array[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    int valor;
    printf("Ingrese el dato numero: %d del array\n", i + 1);
    scanf("%d", &valor);
    array[i] = valor;
  }
  mergeSort(array, 0, SIZE - 1);
  printf("---------\n");
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d\n", array[i]);
  }
}