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

void maxHeapify(HEAP * h, int i){
  int esq = filhoEsquerda(i);
  int dir = filhoDireita(i);
  int temp;
  int maior = i;
  if ((esq <= h->tamanhoAtual) && (h->A[esq]>h->A[i])) maior = esq;
  if ((dir <= h->tamanhoAtual) && (h->A[dir]>h->A[maior])) maior = dir;
  if (maior != i) {
     temp = h->A[i];
     h->A[i] = h->A[maior];
     h->A[maior] = temp;
     maxHeapify(h,maior);
  }
}

void upHeap(HEAP * h){
  int i;
  int metadeTamanho = h->tamanhoAtual/2;
  for (i=metadeTamanho;i>0;i--) maxHeapify(h,i);
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
