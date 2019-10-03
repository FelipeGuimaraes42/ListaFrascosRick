#include <iostream>

#include "include/listasimples.h"
#include "include/fila.h"

//Construtor do TAD ListaEncadeada
ListaEncadeada::ListaEncadeada(){
    _inicio= new Node_t();
    _fim= _inicio;
    _inicio->_prox= nullptr;
    _num_elementos= 0;
    //std::cout << "Lista Criada!" << std::endl;
}

//Destrutor padrão
ListaEncadeada::~ListaEncadeada(){}

/*A inserção de elementos é feita apenas no fim da lista, logo a função aloca uma memória para um novo fim
e o 'fim anterior' é alocado como o novo elemento*/
void ListaEncadeada::incluir_elemento(TipoItem item){
    _fim->_prox= new Node_t();
    _fim= _fim->_prox;
    _fim->_item= item;
    _fim->_prox = nullptr;
    _num_elementos ++;
    //std::cout << "Item " << item << " adicionado!" << std::endl;
}

/*Procura na lista o elemento passado por parâmetro usando dois ponteiros, pois não é duplamente
encadeada
Quando encontra o valor na lista, o ponteiro ant aponta para o prox do prox e remove o seg*/
void ListaEncadeada::remover_elemento(TipoItem item){
    //Testa se há elementos na lista
    if(_num_elementos==0){
        //std::cout << "Lista vazia!" << std::endl;
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
            //std::cout << "Item "<< item << " n encontrado!" << std::endl;
            return;
        }else{
            //std::cout << "Item " << seg->_item << " deletado!" << std::endl;
            ant->_prox= seg->_prox;
            //Atualiza o novo final se necessário
            if(ant->_prox == nullptr)
                _fim= ant;
            delete(seg);
            _num_elementos--;
        }
    }
}

//Apaga tudo da fila menos a célula cabeça
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
    
    //Verifica se está na lista, se estiver retorna 1
    for(i=0; i<_num_elementos; i++){
        if(ml== seg->_item){
            std::cout << 1 << std::endl;
            return;
        }
        ant= seg;
        seg= seg->_prox;
    }

    ant= _inicio;
    seg= ant->_prox;
    //Armazena na fila o valor dos frascos para fazer as combinações
    for(i=0; i<_num_elementos; i++){
        ant= seg;
        fila.incluir_elemento(ant->_item, 1);
        seg= seg->_prox;
    }

    Node_f *aux;
    Node_t *it;
    TipoItem temp=0;
    aux= fila._inicio->_prox;
    /*
        Esse loop aninhado é bem simples: duplica o primeiro elemento na fila e apaga ele da fila.
        Depois, soma e subtrai esses valores com os frascos e os compara com o valor que o usuário deseja medir.
        Se for o valor, retorna o número de operçãoes.
        Senão, adiciona esse novo valor na fila com o número de operações incrementado para um novo loop.
        O loop seguinte não tem verificação de consistência, pois todas as entradas são solucionáveis.
    */
    while(1){
            //\Iterador de frascos
            it= _inicio->_prox;
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
    }
    fila.limpar();
}