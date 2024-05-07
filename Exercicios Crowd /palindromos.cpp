#include <iostream>

struct lista{
  int info;
  char c;
  struct lista *prox;
};

typedef struct lista *Lista;

Lista inseririni(Lista l, int v, char c){
  Lista novo = (Lista) malloc(sizeof(struct lista));
  novo->info = v;
  novo->prox = l;
  novo->c=c;
  return novo;
}

int buscaboll(Lista *l, char ch){
    Lista aux = *l;
    while(aux != NULL){
        if(aux->c == ch) {
          aux->info = aux->info + 1;
          return 1;
        }
      aux=aux->prox;
    }
  return 0;
}

int main() {
  
  int j;
  
  
  std::string palavra;
  
  while(std::cin>>palavra){
    Lista l = NULL;
  for(j = 0; j < palavra.size(); j++){
    
    if(buscaboll(&l, palavra[j])!=1)  l=inseririni(l, 1, palavra[j]);
  
  }
  int qtd=0;
  if(palavra.size()%2==0) {
    for(Lista aux = l; aux != NULL; aux = aux->prox){
      if(aux->info%2!=0) qtd++;
    }
    if(qtd>0)  std::cout << qtd-1;
    else std::cout << "0";
      
  }else{
    for(Lista aux = l; aux != NULL; aux = aux->prox){
      if(aux->info%2!=0) qtd++;
    }
    if(qtd>0)  std::cout << qtd-1;
    else std::cout << "0";
  
   
  }
    
    
  
  std::cout << std::endl;
}
  

}
