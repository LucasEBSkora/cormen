/*
  Entrada: Duas sequências A e B de n bits A= <a1,a2,...,an> e B = <b1, b2, ..., bn> 
  representando dois números em base binária

  Saída: Uma terceira sequência C de n+1 bits C = <c1, c2, ..., c_{n+1}> tal que C = A + B
*/

#define N 8

#include <stdio.h>

#include "../../utilidades/utilidades_ordenacao.h"

int main () {
  int A[N] = {0, 0, 0, 1, 0, 1, 0, 1};
  int B[N] = {1, 0, 1, 0, 1, 1, 1, 1};
  int C[N + 1] = {0};

  printf("0, ");
  imprimirVetor(A, N);
  printf("0, ");
  imprimirVetor(B, N);

  int i;
  int resto = 0;

  for (i = N - 1; i >= 0; --i) {
    C[i + 1] = (A[i] && !B[i] && !resto) || (!A[i] && B[i] && !resto) || (!A[i] && !B[i] && resto) || (A[i] && B[i] && resto);
    resto = (A[i] && B[i]) || (A[i] && resto) || (B[i] && resto);
  }

  C[0] = resto;

  imprimirVetor(C, N + 1);
  return 0;
}