#include "../include/listasimples.h"
#include <iostream>

ListaEncadeada::ListaEncadeada(ListaEncadeada *Lista){
    Lista->_inicio= new Node_t();
    Lista->_fim= nullptr;
    Lista->_inicio->_prox= nullptr;
}

ListaEncadeada::~ListaEncadeada(){}

void ListaEncadeada::incluir_elemento(TipoItem item, ListaEncadeada *Lista){
    Lista->_fim->_prox= new Node_t();
    Lista->_fim= Lista->_fim->_prox;
    Lista->_fim->_item= item;
    Lista->_fim->_prox = nullptr;
    Lista->_num_elementos ++;
}

void ListaEncadeada::remover_elemento(TipoItem item, ListaEncadeada *Lista){
    if(Lista->_num_elementos==0)
        return;
    int cont=0;
    Node_t *ant= Lista->_inicio;
    Node_t *seg= ant->_prox;
    while(seg->_item!= item && seg->_prox!= nullptr){
        ant= seg;
        seg= seg->_prox;
        cont ++;
    }
    if(cont>= Lista->_num_elementos){
        return;
    }else{
        ant->_prox= seg->_prox;
        if(ant->_prox == nullptr)
            Lista->_fim= ant;
        delete(seg);
    }
}

void ListaEncadeada::imprime(const ListaEncadeada *Lista){
    Node_t *aux= Lista->_inicio->_prox;
    while(aux!= nullptr){
        std::cout << aux->_item << std::endl;
        aux= aux->_prox;
    }
}