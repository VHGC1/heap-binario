#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "heap.h";

void criarNodo(HEAP * h, int tamanhoMax){
  h->A = (int*) malloc(sizeof(int)*(tamanhoMax+1));
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = tamanhoMax;
}


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

void downHeapAux(HEAP * h,int j){
  for(int i; i < j;i++){
    downHeap(h->tamanhoAtual,j);
  }
}

void upHeap(HEAP * h, int k){
  int temp;
  temp = h->A[k];

  while(k >= 1 && h->A[pai(k)] <= temp){
    h->A[k] = h->A[pai(k)];
    k = pai(k);
  }
  h->A[k] = temp;
}

void inserir(HEAP * h, int valor){
  if (h->tamanhoAtual < h->tamanhoMaximo){
    (h->tamanhoAtual)++;
    h->A[h->tamanhoAtual] = valor;
    printf("Valor inserido: %d\n", valor);

    printf("Iniciando upHeap para validar o heap-order\n");
    upHeap(h, h->tamanhoAtual);
    return;
  }
  printf("Inserção não realizada\n");
  return;
}

void imprimirArranjo(HEAP h){
  int tamanho = h.tamanhoAtual;
  int i;
  for (i=1;i<=tamanho;i++) printf("%d ",h.A[i]);
  printf("\n");
}

void remover(HEAP *h, int valor){
  int i;

  for(int i = 0; i < h->tamanhoAtual; ++i){
    if(h->A[i] == valor){
      h->A[i] = h->A[h->tamanhoAtual];
      (h->tamanhoAtual)--;
      printf("Valor removido: %d \n", valor);
      downHeap(h, i);
      return;
    }
  }
  printf("%d nao foi encontrado\n!", valor);
}

