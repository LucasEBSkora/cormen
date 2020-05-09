#include "../../utilidades/utilidades_ordenacao.h"
#include "../../utilidades/utilidades_tempo.h"

#include <stdio.h>
#include <stdlib.h>

void merge(int *A, unsigned int l, unsigned int m, unsigned int r, int* aux) {
  unsigned int i; 
  unsigned int j;
  unsigned int k;

  i = l;
  j = m + 1;
  k = l;

  while (i <= m && j <= r) {
    if (A[i] < A[j]) 
      aux[k++] = A[i++];
    else 
      aux[k++] = A[j++];
  }

  while (i <= m) 
    aux[k++] = A[i++];

  while (j <= r)
    aux[k++] = A[j++];


  for (i = l; i <= r; ++i) A[i] = aux[i];
}


void ordenarIntercalacao(int* A, unsigned int l, unsigned int r, int* aux) {
  if (l < r) {
    unsigned int p = (r + l)/2;
    ordenarIntercalacao(A, l, p, aux);
    ordenarIntercalacao(A, p + 1, r, aux);
    merge(A, l, p, r, aux);
  }
}


int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Utiizacao: ex n\n\tonde:\n\t\tn = tamanho do conjunto aleatorio a ordenar\n");
    return -1;
  }

  unsigned int tamanho = atoi(argv[1]);


  int* A = geraVetorAleatorioEmIntervalo(tamanho, 0, 100);

  int* aux = malloc(sizeof (int) * tamanho);
  
  // imprimirVetor(A, tamanho);

  float t0 = getTempoAtual();

  ordenarIntercalacao(A, 0, tamanho - 1, aux);

  float tf = getTempoAtual();

  printf("tempo necessario para ordenacao: %f\n", tf- t0);

  if (!verificarOrdenacao(A, tamanho)) {
    printf("eita, deu ruim\n");
    return -1;
  }

  // imprimirVetor(A, tamanho);

  free(A);
  free(aux);
  return 0;
}