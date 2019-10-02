#include <iostream>
#include <cstdio>
#include "include/listasimples.h"
#include "include/fila.h"

char opcao;
TipoItem item;

int main() {
    ListaEncadeada Lista= ListaEncadeada();
    while(scanf("%d %c", &item, &opcao) != EOF){
        if(opcao=='e' || item==0){
            break;
        }else if(opcao== 'i'){
            Lista.incluir_elemento(item);
        }else if(opcao== 'r'){
            Lista.remover_elemento(item);
        }else if(opcao== 'p'){
            Lista.medicao(item);
        }else{
            std::cout << "Opcao invalida. Tente de novo!" << std::endl;
        }
    }
    
    return 0;
}