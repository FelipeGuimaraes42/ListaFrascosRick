#include "../include/listasimples.h"
#include <iostream>

ListaEncadeada::ListaEncadeada(){
    _inicio= new Node_t();
    _fim= _inicio;
    _inicio->_prox= nullptr;
    _num_elementos= 0;
    std::cout << "Lista Criada!" << std::endl;
}

ListaEncadeada::~ListaEncadeada(){}

void ListaEncadeada::incluir_elemento(TipoItem item){
    _fim->_prox= new Node_t();
    _fim= _fim->_prox;
    _fim->_item= item;
    _fim->_prox = nullptr;
    _num_elementos ++;
    std::cout << "Item " << item << " adicionado!" << std::endl;
}

void ListaEncadeada::remover_elemento(TipoItem item){
    if(_num_elementos==0){
        std::cout << "Lista vazia!" << std::endl;
        return;
    }else{
        int i;
        Node_t *ant= _inicio;
        Node_t *seg= ant->_prox;
        //while(seg->_item!= item && cont<_num_elementos ){
        /*while(seg->_item!= item && seg->_prox!= nullptr){
            ant= seg;
            seg= seg->_prox;
            cont ++;
        }*/
        for(i=1; i<=_num_elementos; i++){
            if(seg->_item==item)
                break;
            else{
                ant= seg;
                seg= seg->_prox;
            }
        }
        //std::cout << cont << std::endl;
        if(i>_num_elementos){
            std::cout << "Item "<< item << " n encontrado!" << std::endl;
            return;
        }else{
            std::cout << "Item " << seg->_item << " deletado!" << std::endl;
            ant->_prox= seg->_prox;
            if(ant->_prox == nullptr)
                _fim= ant;
            delete(seg);
            _num_elementos--;
        }
    }
}

void ListaEncadeada::imprime(){
    Node_t *aux= _inicio->_prox;
    while(aux!= nullptr){
        std::cout << aux->_item << "\t";
        aux= aux->_prox;
    }
    std::cout << std::endl;
}