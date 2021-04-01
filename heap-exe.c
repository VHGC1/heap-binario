#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

main(){
  int valor, op, num;
  HEAP heap;
//valores adicionados no heap
//options
//imprimir
//sort

  inicializarHeap(&heap, 100);

  for(int i = 1; i < 10; i++){
    valor = rand() % 100;
    printf("Inserir %d\n", valor);
    inserir(&heap, valor);
  }

  imprimirArranjo(heap);
  

  
  /*
  while(op != 3){
    printf("[ 1 ] DownHeap");
    printf("[ 2 ] Remover")
    printf("[ 3 ] Sair")

    printf("Digitar op:")
    scanf("%d", op);

    switch(op){
      case 1:
        downHeap;
        break;
      case 2;
      printf("Entre com o valor a ser removido:");
      scanf("%d")
        remove(heap, num);
        break;
    }
    
    system("cls");
  }
  
  */
}