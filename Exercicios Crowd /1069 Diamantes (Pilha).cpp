//1069 diamantes bruno castelani
#include <iostream>
typedef struct pilha{
    char info;
    struct pilha *prox;
}P;
typedef P *Pil;

Pil push(Pil p, char c){
  Pil novo = (Pil) malloc(sizeof(P));
  novo->info=c;
  novo->prox=p;
  return novo;  
}

Pil pop(Pil p, char *c){
  if(p==nullptr)return nullptr;
  Pil aux= p;
  *c = aux->info;

  p = p->prox;  //o proximo vai ser o novo topo
  delete aux; //remove o nó excluido (ultimo topo)
  return p;
}

int qtddiamante(Pil p){
  Pil c1=nullptr;
  char lixo,inf,c;
  int qtd=0;
  while(p!=nullptr){
   
    if(c1!=nullptr){

      p = pop(p,&c);
      if(c=='<'){
          c1 = pop(c1,&lixo);
          qtd++;
      }
      if(c=='>')c1 = push(c1, c);
    }else{
  
      p = pop(p,&inf);
      if(inf=='>')c1 = push(c1, inf);
    
    }
  }
  return qtd;
}
int main() {
  int i,j,n;
  std::cin >> n;
  
  char c[n][100];
  
 
  Pil p[n];
  int q[n];

  for(i = 0; i < n; i++){
     p[i]=nullptr;
     std::cin >> c[i];
    
    for(j = 0; c[i][j]!='\0' ; ++j) // a condição do meio do for indica que a posição atual do vetor de caracteres foi preenchida e portanto não é'\0'
      {
        p[i] = push(p[i],c[i][j]);
      }
      q[i]=qtddiamante(p[i]);
  }
  for(i = 0; i < n; i++)std:: cout << q[i] << std::endl;
  
  
}
