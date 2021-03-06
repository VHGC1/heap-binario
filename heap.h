#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int * A;
  int tamanhoAtual;
  int tamanhoMaximo;
}HEAP;

void criarNodo(HEAP * h, int tamanhoMax);
void destruirHeap(HEAP * h);
int pai(int i);
int filhoEsquerda(int i);
int filhoDireita(int i);
void downHeap(HEAP * h, int k);
void upHeap(HEAP * h,int k);
void inserir(HEAP * h, int valor);
void remover(HEAP * h, int valor);
void imprimirArranjo(HEAP p);
void remover(HEAP * h, int valor);


void menu();
