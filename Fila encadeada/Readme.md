# Como funciona uma fila?

&emsp;&emsp;Uma fila é uma estrutura na qual o primeiro a entrar será o primeiro a sair, (FIFO).
 1. Quando um elemento for inserindo sera sempre no `final` da fila.
 2. Quando um elemento for removido será sempre o `primeiro elemento` da fila.

## Cada Elemento da fila *nó* tem um valor atribuido à ele e um ponteiro para o _próximo da fila (nó):_
~~~c++
struct no{
    int identificador;
    no *prox;

};
typedef struct no *No;
~~~~

## A estrutura da *fila* contém um ponteiro para o primeiro elemento e para o ultimo elemento:
~~~c++
struct fila{
      No ini;
      No fim;
};
typedef struct fila *Fila;
~~~

# As operações que eu usei da *fila*.
### Iniciar a fila.
~~~c++
Fila iniciar(){
    Fila novo = (Fila) malloc(sizeof(struct fila));
    novo->ini = NULL;
    novo->fim = NULL;
    return novo;
}
~~~
Perceba que a estrutura da `fila` precisa ser inicializada visto que ela é uma `estrutura de base`.

### Inserir elemento na fila.
~~~c++
No inserir(Fila f, int id){

  //note que quando inserimos um novo nó usamos um malloc nele para que ele passe a existir.
    No no = (No) malloc(sizeof(struct no));
    no->identificador = id;
  
    //o nó que entra é sempre o ultimo elemento então ele aponta para o ultimo topo
    no->prox = NULL;
  
    //Código para verificar se o no é o primeiro elemento da fila, se for o ini recebe ele
    if(f->ini == NULL)f->ini = no; 
    else f->fim->prox= no;
    //se não o atual fim aponta para o novo

  //o final da fila é o novo nó
  f->fim = no;

  return no;
}

~~~

### Remoção de elemento (inicio)
~~~c++
No remover (Fila f, int *v) {

	if (f == NULL) return NULL;
  //pega o elemento que pretendemos remover
	No lib = f->ini; 
	if (f->ini == NULL) return NULL;

	//o ponteiro pega o dado do elemento removido
	*v = lib->identificador;
	if (f->ini == f->fim) f->fim = NULL;

//o novo inicio é o proximo do elemento removido
	f->ini = lib->prox;

//libera o espaço do elemento removido
	delete lib;

// Retorna o Novo Início da Fila
	return f->ini; 
}
~~~

### Printar a Fila
~~~c++
void printfil(Fila f){
  No elemento;
  
  //Este for irá rodar até que o prox do ultimo elemento seja = NULL, ou seja ele rodou até o ultimo elemento da fila
  for(elemento = f->ini; elemento->prox!=NULL; elemento=elemento->prox){
    std::cout << elemento->identificador << " ";
  } 
  
  //Perceba que o for para antes de printar o ultimo elemento da fila, logo ele temos que printá-lo manualmente
  std::cout<< elemento->identificador << std::endl;
  //fizemos isso para que possamos encerrar a linha sem o espaço que tem no cout dentro do for, já que o beecrowd tem esses problemas
  
  return;
}
~~~
