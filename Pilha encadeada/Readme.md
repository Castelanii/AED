# Como funciona uma pilha?

&emsp;&emsp;Uma pilha é uma estrutura na qual o primeiro a entrar será o ultimo a sair, (FILO).
 1. Quando um elemento for inserindo sera sempre no `final` da pilha.
 2. Quando um elemento for removido será sempre o `ultimo` da pilha.

## Cada Elemento da pilha *nó* tem um valor atribuido à ele e um ponteiro para o _próximo da pilha (nó):_
~~~c++
typedef struct pilha{
    char info;
    struct pilha *prox;
}P;
typedef P *Pil;
~~~~



# As operações que eu usei da *Pilha*.

### Inserir elemento na pilha.
~~~c++
Pil push(Pil p, char c){
  Pil novo = (Pil) malloc(sizeof(P));
  novo->info=c;
  novo->prox=p;
  return novo;  
}

~~~

### Remoção de elemento
~~~c++
Pil pop(Pil p, char *c){
  if(p==nullptr)return nullptr;
  Pil aux= p;
  *c = aux->info;

  p = p->prox;  //o proximo vai ser o novo topo
  delete aux; //remove o nó excluido (ultimo topo)
  return p;
}

~~~



