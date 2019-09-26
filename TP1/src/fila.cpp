#include <iostream>

#include "../include/fila.h"

Fila::Fila(){
    _inicio= new Node_f();
    _fim= _inicio;
    _inicio->_prox= nullptr;
    _num_elementos= 0;
    std::cout << "Fila criada!" << std::endl;
}

Fila::~Fila(){}

void Fila::incluir_elemento(TipoItem ml, int iteracao){
    _fim->_prox= new Node_f();
    _fim= _fim->_prox;
    _fim->_item._ml= ml;
    _fim->_item._qtde= iteracao;
    _fim->_prox= nullptr;
    _num_elementos++;
    //std::cout << "Item adicionado!" << std::endl;
}

void Fila::remover_elemento(){
    if(_num_elementos== 0)
        return;
    Node_f *aux= _inicio;
    Node_f *seg= aux->_prox;
    aux->_prox= seg->_prox;
    delete seg;
    _num_elementos--;
    //std::cout << "Item removido!" << std::endl;
    if(aux->_prox== nullptr)
        _fim= aux;
}

void Fila::imprime(){
    Node_f *aux= _inicio->_prox;
    while(aux!= nullptr){
        std::cout << aux->_item._ml << "\t";
        aux= aux->_prox;
    }
    std::cout << std::endl;
}

void Fila::limpar(){
    while(_num_elementos> 0){
        Node_f *aux= _inicio;
        Node_f *seg= aux->_prox;
        aux->_prox= seg->_prox;
        delete seg;
        _num_elementos--;
        if(aux->_prox== nullptr)
            _fim= aux;
    }
}
