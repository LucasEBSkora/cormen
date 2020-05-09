#ifndef __UTILIDADES_ORDENACAO_H__
#define __UTILIDADES_ORDENACAO_H__

//Imprime o vetor inteiro
void imprimirVetor(int *A, unsigned int tamanho);
unsigned short verificarOrdenacao(int *A, int tamanho);

//Verifica se ele está ordenado (mas não se os elementos são os mesmos do vetor inicial)
int* geraVetorAleatorioEmIntervalo(int tamanho, int a, int b);
int* geraVetorAleatorio(int tamanho);
int* geraVetorCrescente(int tamanho);
int* geraVetorDecrescente(int tamanho);

#endif