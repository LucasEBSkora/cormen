#include "../../utilidades/utilidades_ordenacao.h"
#include "../../utilidades/utilidades_tempo.h"

#include <stdio.h>
#include <stdlib.h>

void ordenarInsercao(int* A, unsigned int tamanho) {
  unsigned int i;
  int j;
  for( i = 1; i < tamanho; ++i) {
    int valor = A[i];
    j = i - 1;
    for (; j >= 0 && A[j] > valor; --j) A[j+1] = A[j];
    A[j + 1] = valor;
  }  
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Utiizacao: ex n\n\tonde:\n\t\tn = tamanho do conjunto aleatorio a ordenar\n");
    return -1;
  }

  unsigned int tamanho = atoi(argv[1]);


  int* A = geraVetorAleatorioEmIntervalo(tamanho, 0, 100);
    
  // imprimirVetor(A, tamanho);

  float t0 = getTempoAtual();

  ordenarInsercao(A, tamanho);

  float tf = getTempoAtual();

  printf("tempo necessario para ordenacao: %f\n", tf- t0);

  if (!verificarOrdenacao(A, tamanho)) {
    printf("eita, deu ruim\n");
    return -1;
  }

  // imprimirVetor(A, tamanho);

  free(A);
  return 0;
}