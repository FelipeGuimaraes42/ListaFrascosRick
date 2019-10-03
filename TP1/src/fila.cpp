#include <iostream>

#include "include/fila.h"

//Construtor do TAD Fila
Fila::Fila(){
    _inicio= new Node_f();
    _fim= _inicio;
    _inicio->_prox= nullptr;
    _num_elementos= 0;
    //std::cout << "Fila criada!" << std::endl;
}

//Destrutor do TAD Fila
Fila::~Fila(){}

//Inclusão de elemento do final da fila
void Fila::incluir_elemento(TipoItem ml, int iteracao){
    _fim->_prox= new Node_f();
    _fim= _fim->_prox;
    _fim->_item._ml= ml;
    _fim->_item._qtde= iteracao;
    _fim->_prox= nullptr;
    _num_elementos++;
    //std::cout << "Item adicionado!" << std::endl;
}

//Remoção de elementos do início da fila
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

//Imprime todos os elementos da fila separados por tab
void Fila::imprime(){
    Node_f *aux= _inicio->_prox;
    while(aux!= nullptr){
        std::cout << aux->_item._ml << "\t";
        aux= aux->_prox;
    }
    std::cout << std::endl;
}

//Apaga tudo da fila menos a célula cabeça
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

/*Método que reduz a redundância de operações na fila, ou seja, não armazena valores repetidos.
Retorna falso se estiver na fila e verdadeiro caso contrário*/
bool Fila::comparar(int temp){
    Node_f *aux= _inicio;
    while(aux->_prox != nullptr){
        if(aux->_prox->_item._ml == temp)
            return false;
        else
            aux= aux->_prox;
    }
    return true;
}
