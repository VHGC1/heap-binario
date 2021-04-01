#include <stdio.h>
#include "heap.c"

main(){
  int valor, op;
  HEAP heap;
//valores adicionados no heap
//options
//imprimir
//sort

  inicializarHeap(&heap, 100);

  for(int i = 1; i < 32; i++){
    valor = rand() % 100;
    printf("Inserir %d\n", valor);
    inserir(&heap, valor);
  }

  imprimirArranjo(heap);

  
  /*
  while(op != 4){
    printf("[ 1 ] UpHeap");
    printf("[ 2 ] DownHeap");
    printf("[ 3 ] Remover")
    printf("[ 4 ] Sair")

    printf("Digitar op:")
    scanf("%d", op);

    switch(op){
      case 1:
        upHeap();
        break;
      case 2:
        downHeap;
        break;
      case 3;
        remove();
        break;
    }
    
    system("cls");
  }
  
  */
}