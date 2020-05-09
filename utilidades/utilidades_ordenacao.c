#include "utilidades_ordenacao.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void imprimirVetor(int *A, unsigned int tamanho) {
  unsigned int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

unsigned short verificarOrdenacao(int *A, int tamanho) {
  unsigned int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}

int* geraVetorAleatorioEmIntervalo(int tamanho, int a, int b) {
  if (b < a) return NULL;

  srand(time(NULL));

  int *v = malloc(sizeof (int) * tamanho); 

  int i;
  for (i = 0; i < tamanho; ++i) v[i] = a + rand()%(b - a) ;

  return v;
}


int* geraVetorCrescente(int tamanho) {
  int *v = malloc(sizeof (int) * tamanho);
  int i;
  for(i = 0; i < tamanho;++i) v[i] = i;
  return v;
}

int* geraVetorDecrescente(int tamanho) {
  int *v = malloc(sizeof (int) * tamanho);
  int i;
  for(i = tamanho - 1; i >= 0 ; --i) v[i] = i;
  return v;
}