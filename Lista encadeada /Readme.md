### Remover elemento do meio da lista.

~~~c++
No removerdomeio(Fila f,int id){
  if(f->ini==NULL)return NULL;
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

~~~
