#ifndef FILA_H
#define FILA_H

typedef int TipoItem;

struct Medida{
    int _qtde= 0;
    int _ml;
};

struct Node_f{
    Medida _item;
    Node_f *_prox; 
};


struct Fila{
    Node_f *_inicio, *_fim;
    int _num_elementos= 0;

    Fila();
    ~Fila();
    
    void incluir_elemento(TipoItem, int);
    void remover_elemento();
    void imprime();
    void limpar();
};


#endif