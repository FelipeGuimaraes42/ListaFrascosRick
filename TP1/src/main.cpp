#include <iostream>
#include "../include/listasimples.h"

int main() {
    ListaEncadeada Lista= ListaEncadeada();
    Lista.incluir_elemento(5);
    Lista.incluir_elemento(7);
    std::cout << "N: " << Lista._num_elementos << std::endl;
    Lista.imprime();
    Lista.remover_elemento(2);
    Lista.remover_elemento(5);
    Lista.remover_elemento(7);
    std::cout << "N: " << Lista._num_elementos << std::endl;
    Lista.imprime();
    Lista.incluir_elemento(5);
    Lista.remover_elemento(2);
    Lista.remover_elemento(5);
    Lista.remover_elemento(7);
    std::cout << "N: " << Lista._num_elementos << std::endl;
    Lista.imprime();
    Lista.incluir_elemento(7);
    Lista.remover_elemento(70);
    Lista.remover_elemento(7);
    std::cout << "N: " << Lista._num_elementos << std::endl;
    Lista.imprime();
    
    return 0;
}
