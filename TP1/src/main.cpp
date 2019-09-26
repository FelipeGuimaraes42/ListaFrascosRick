#include <iostream>
#include <string>
#include "../include/listasimples.h"
#include "../include/fila.h"

int main() {
    ListaEncadeada Lista= ListaEncadeada();
    /*Fila fila= Fila();
    fila.incluir_elemento(5, 1);
    fila.incluir_elemento(6, 2);
    fila.incluir_elemento(7, 2);
    fila.imprime();
    fila.remover_elemento();
    fila.remover_elemento();
    fila.remover_elemento();
    fila.remover_elemento();
    fila.imprime();
    fila.incluir_elemento(5, 1);
    fila.imprime();*/

    while(1){
        std::string opcao;
        TipoItem item;
        std::cin >> item >> opcao;

        //Teste
        if(opcao[0]=='e'){
            break;
        }else if(opcao[0]== 'i'){
            Lista.incluir_elemento(item);
        }else if(opcao[0]== 'r'){
            Lista.remover_elemento(item);
        }else if(opcao[0]== 'p'){
            Lista.medicao(item);
        }else{
            std::cout << "Opcao invalida. Tente de novo!" << std::endl;
        }
    }
    
    return 0;
}
