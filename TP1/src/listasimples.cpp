#include <iostream>

#include "../include/listasimples.h"
#include "../include/fila.h"

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
        for(i=1; i<=_num_elementos; i++){
            if(seg->_item==item)
                break;
            else{
                ant= seg;
                seg= seg->_prox;
            }
        }
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

void ListaEncadeada::medicao(TipoItem ml){
    Fila fila= Fila();
    Node_t *ant, *seg;
    int i;
    ant= _inicio;
    seg= ant->_prox;
    
    //Verifica se está na lista
    for(i=0; i<_num_elementos; i++){
        if(ml== seg->_item){
            std::cout << "1" << std::endl;
            return;
        }
        ant= seg;
        seg= seg->_prox;
    }

    ant= _inicio;
    seg= ant->_prox;
    //Armazena na fila o valor dos frascos
    for(i=0; i<_num_elementos; i++){
        ant= seg;
        fila.incluir_elemento(ant->_item, 1);
        seg= seg->_prox;
    }

    Node_f *aux;
    Node_t *it;
    TipoItem temp=0;
    int cont;
          
    aux= fila._inicio->_prox;

    while(1){
        //for(i=0; i<fila._num_elementos; i++){  
            it= _inicio->_prox;
            cont= fila._num_elementos;
            //Implementar a soma e subtração de termos ;D
            for(i=0; i< _num_elementos; i++){
                //Soma
                temp = aux->_item._ml+  it->_item;
                if(temp== ml){
                    std::cout << aux->_item._qtde + 1 << std::endl;
                    return;
                }else{
                    fila.incluir_elemento(temp, aux->_item._qtde+1);
                }
                //Subtração
                temp= aux->_item._ml- it->_item;
                if(temp== ml){
                    std::cout << aux->_item._qtde + 1 << std::endl;
                    return;
                }else if(temp>0){
                    fila.incluir_elemento(temp, aux->_item._qtde+1);
                }
                it= it->_prox;
            }
            aux= aux->_prox;
            fila.remover_elemento();
        //}
    }
    fila.limpar();
    //fila.imprime();
}