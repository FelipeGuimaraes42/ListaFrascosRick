#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

typedef int TipoItem;

struct Node_t{
    TipoItem _item;
    Node_t *_prox; 
};

struct ListaEncadeada{
    Node_t *_inicio, *_fim;
    int _num_elementos= 0;

    ListaEncadeada();
    ~ListaEncadeada();
    
    void incluir_elemento(TipoItem);
    void remover_elemento(TipoItem);
    void imprime();
    void medicao(TipoItem);
};


#endif