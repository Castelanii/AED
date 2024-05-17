# Como funciona uma Lista?

&emsp;&emsp;Uma Lista é uma estrutura na qual você tem liberdade para escolher a ordem de entrada e saida de um elemento.
 1. Quando um elemento for inserido poderá ser de `qualquer` posição da lista.
 2. Quando um elemento for removido, podera ser `qualquer` elemento da lista.

## Cada Elemento da lista *nó* tem um valor atribuido à ele e um ponteiro para o _próximo da lista (nó):_
~~~c++
struct Node {
    std::string info;
    Node* prox;
    Node(const std::string& value) : info(value), prox(nullptr) {}
};
~~~~


# As operações que eu usei da *lista*.

### Inserir elemento na lista no início.
~~~c++
Node* inserirIni(Node* lista, const std::string& v) {
    Node* novo = (Node*)malloc(sizeof(Node)); 
    novo->info = v; 
    novo->prox = lista; 
    lista = novo; 
    return lista; 
}
~~~

### Inserir elemento (fim)
~~~c++
Node* inserirFim(Node* lista, const std::string& v) {
    Node* novo = (Node*)malloc(sizeof(Node)); 
    novo->info = v; 
    novo->prox = nullptr; 

    if (lista == nullptr) {
        lista = novo;
    } else {
        Node* aux = lista;
        while (aux->prox != nullptr) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return lista; 
}

~~~

### Printar a Lista
~~~c++
void listar(Node* lista) {
    Node* elemento = lista;
    while (elemento != nullptr) {
        std::cout << elemento->info << std::endl;
        elemento = elemento->prox;
    }
}
void listarEspecifico(Node* lista, int c){
      Node* elemento;
    int posicao=1;
         for(elemento = lista; elemento!=NULL; elemento=elemento->prox){
             if(posicao == c)std::cout<< elemento->info << std::endl;
             posicao++;
      } 
}
~~~

### Remover elemento do meio da lista.

~~~c++
No removerdomeio(Node *f,int id){
  if(f->ini==NULL)return NULL;
  Node *aux, *prox,*lib;
  //acha o no com o id
  for(aux=NULL,prox = f->ini ; prox!=NULL && prox->identificador!=id ; aux=prox,prox= prox->prox )
    
  
  if (aux==f->fim)return f->ini;
  //se for o ultimo
  if(prox==f->fim){
    //se o ultimo for igual ao primeiro a fila se encerra
    if(f->fim==f->ini){
      delete f->ini;
      f->ini = NULL;
      f->fim = NULL;
    }
      //se não o aux (anterior) toma posse do ultimo
    else{
      lib = f->fim;
      aux->prox=NULL;
      f->fim = aux;
      
      delete lib;
    }
   
   return f->ini; 
  }
  //se for o primeiro
  if(prox==f->ini){
    //primeiro iguakl o ultimo
    if(f->fim==f->ini){
      delete f->ini;
      f->ini = NULL;
      f->fim = NULL;
    }

      //se não forem iguais o proximo da fila assume o primeiro
    else{
      lib = f->ini;
      f->ini = f->ini->prox;
      delete lib;
    }

    return f->ini;
  }
  
  //se o escolhido não tiver nada a ver nem com o primeiro nem com o ultimo o anterior tem que apontar para o proximo do escolhido

  lib = prox;
  aux->prox=prox->prox;
  prox = prox->prox;
  delete lib;
  return f->ini;
}

~~~

### Estrutura de ordenação com string (mergesort)

~~~c++
Node* merge(Node* esq, Node* dir) {
    Node* lista = nullptr;
    Node* ultimo = nullptr;

    while (esq != nullptr && dir != nullptr) {
        Node* novo = (Node*)malloc(sizeof(Node));
        if (esq->info <= dir->info) {
            novo->info = esq->info;
            esq = esq->prox;
        } else {
            novo->info = dir->info;
            dir = dir->prox;
        }
        novo->prox = nullptr;

        if (ultimo == nullptr) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    while (esq != nullptr) {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->info = esq->info;
        novo->prox = nullptr;
        if (ultimo == nullptr) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
        esq = esq->prox;
    }

    while (dir != nullptr) {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->info = dir->info;
        novo->prox = nullptr;
        if (ultimo == nullptr) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
        dir = dir->prox;
    }

    return lista;
}

Node* mergeSort(Node* lista, int t) {
    if (lista == nullptr || t <= 1) return lista;

    int meio = t / 2;
    Node* esq = nullptr;
    Node* dir = nullptr;
    Node* aux = lista;

    for (int i = 0; aux != nullptr && i < t; ++i) {
        if (i < meio) {
            esq = inserirFim(esq, aux->info);
        } else {
            dir = inserirFim(dir, aux->info);
        }
        aux = aux->prox;
    }

    esq = mergeSort(esq, meio);
    dir = mergeSort(dir, t - meio);

    return merge(esq, dir);
}
~~~

