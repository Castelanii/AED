//Exercicio 2460 beecrowd
//Bruno Castelani Gouveia
#include <iostream>

//structs para formatação da fila
struct no{
    int identificador;
    no *prox;

};
typedef struct no *No;
struct fila{
      No ini;
      No fim;
};
typedef struct fila *Fila;

//A fila precisa de inicação já que ela é uma estrutura de base*
//*estrutura de base é o que colocarei como nome para elementos que tem fim em si mesmos, por exemplo a struct Fila não tem um prox apontando para outra fila
//ou algo do genero, ela depende apenas dela mesma, então não podemos fazer Fila receber seu próximo visto que não há um, explicarei melhor sobre isso ao
//longo do código
//esse não é nenhum conceito proficional, só um meio q eu usei para lembrar de quando devo ou não inicializar um elemento
//outra forma de saber isso é se existe uma função de inserir do tipo da struct, tal que nela será ultilizado o malloc para que o elemento deixe de ser NULL
//já que não tem nenhuma função de adição que insira uma Fila, deve haver uma para definir o seu elemento inicial
Fila iniciar(){
    Fila novo = (Fila) malloc(sizeof(struct fila));
    novo->ini = NULL;
    novo->fim = NULL;
    return novo;
}

//função para inserção dos nós na fila
No inserir(Fila f, int id){

  //note que quando inserimos um novo nó usamor um malloc nele para que ele exista.
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


No removerdomeio(Fila f,int id){
  if(f->ini==NULL)return NULL;

  /*No aux = NULL;
  No prox = f->ini;
  No lib = NULL;

  // Encontrar o nó com o identificador especificado
  while (prox != NULL && prox->identificador != id) {
      aux = prox;
      prox = prox->prox;
  }

  // Se não encontrou o nó com o identificador
  if (prox == NULL)
      return f->ini;*/

  
  No aux, prox,lib;
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

//função para printar a fila
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

int main() {
  int n, m, k,id,id2;
  Fila fila;
  fila = iniciar();
  std::cin >> n;
  for(k = 0; k < n; k++){
    std::cin>> id;
    //Perceba que a fila não recebe nada, e sim o nó dentro dela
    fila->fim = inserir(fila, id);
  }
  std::cin >> m;
  for(k=0;k < m; k++){
    std::cin >> id2;
    fila->ini = removerdomeio(fila, id2);
  }

  printfil(fila);

}
