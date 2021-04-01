#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

main(){
  int valor, op, num, i;
  HEAP *heap;

  inicializarHeap(heap, 100);

  for(int i = 1; i < 10; i++){
    valor = rand() % 100;
    printf("Inserir %d\n", valor);
    inserir(heap, valor);
  }

  imprimirArranjo(*heap);

  while(op != 4){
    printf("[ 1 ] UpHeap\n");
    printf("[ 2 ] DownHeap\n");
    printf("[ 3 ] Remover\n");
    printf("[ 4 ] Sair\n");

    printf("Digitar op:");
    scanf("%d", &op);
    
    switch(op){
      
      case 1:
        upHeap(heap, heap->tamanhoAtual);
        imprimirArranjo(*heap);
      
      case 2:
         downHeapAux(heap,heap->tamanhoAtual);
        
          imprimirArranjo(*heap);
        
        break;
        
      case 3:
        printf("Entre com o valor a ser removido:");
        scanf("%d", &num);
        remover(heap, num);
        imprimirArranjo(*heap);
        break;
      }
  }
}