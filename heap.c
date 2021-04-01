#include <stdio.h>
#include <malloc.h>
#include "heap.h";

void destruirHeap(HEAP * h){
  int tamanho = h->tamanhoMaximo;
  free(h->A);
  h->tamanhoMaximo=0;
  h->tamanhoAtual=0;
}

int pai(int i){
  return i/2;
}

int filhoEsquerda(int i){
  return 2*i;
}

int filhoDireita(int i){
  return 2*i + 1;
}

void downHeap(HEAP * h, int k){
  int i, temp;
  
  temp = h->A[k];

  while(k <= (h->tamanhoAtual)/2){
    i = filhoEsquerda(k);
    if((filhoEsquerda(k) <= h->tamanhoAtual) && (h->A[filhoDireita(k)] < h->A[filhoDireita(k)]))
      i++;
    if(temp >= h->A[i])
      break;
    h->A[k] = h->A[i];
    k = i;  
  }
  h->A[k] = temp;
}

void inserir(HEAP * h, int valor){
  if (h->tamanhoAtual < h->tamanhoMaximo){
    (h->tamanhoAtual)++;
    h->A[h->tamanhoAtual] = valor;
    printf("Valor inserido: %d\n", valor);
  }
}

void imprimirArranjo(HEAP h){
  int tamanho = h.tamanhoAtual;
  int i;
  for (i=1;i<=tamanho;i++) printf("%d ",h.A[i]);
  printf("\n");
}

void inicializarHeap(HEAP * h, int tamanhoMax){
  h->A = (int*) malloc(sizeof(int)*(tamanhoMax+1));
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = tamanhoMax;
}
