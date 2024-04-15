#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
//struct para cada carctere
struct posicao{
  int posi;
  struct posicao* prox;
  std::string palavra;
};
//struct para cada palavra
typedef posicao *Pos;

int busca(Pos p, std::string palavra){
  Pos aux = p;
  
  while(aux != NULL){
    if(palavra==aux->palavra){
      std::cout << aux->posi;
    }
    aux= aux->prox;
  }
  std::cout << std::endl;
  return 0;
}
Pos push(Pos pilha, int x, std::string pala){
  Pos novo = (Pos)malloc(sizeof(posicao));
  novo->posi = x;
  novo->palavra= pala;
  novo->prox = pilha;
  return novo;
}
int main() {
  Pos posicao = NULL;
  std::string linha, palavra;

  // Lê uma linha inteira de entrada e armazena em 'linha'
  std::getline(std::cin, linha);
int i = 0;
  if(linha[0]!=' '){
    for(int x = 0; x<linha.size(); x++){
      if(linha[x]==' ')x = 10000;
      palavra[i] = linha[x];
    }
    posicao = push(posicao, i, palavra);
  }
    
  for(int i = 1; i < linha.size(); i++){
    if(linha[i] == ' '){
      std::string pala;
      int ini = i+1;
      for(int x = ++i; x<linha.size(); x++){
        if(linha[x]==' ')x = 10000;
        pala[i] = linha[x];
        i++;
      }
      push(posicao, ini, pala);
    }
    
  }
    int quantidade;
    std::cin >> quantidade;
    std::cin.ignore(); // Limpa o buffer de entrada

    std::string lin;

    for (int i = 0; i < quantidade; ++i) {
        // Lê uma linha inteira de entrada
        std::getline(std::cin, lin);

        // Cria um stringstream a partir da linha
        std::istringstream iss(lin);

        std::string palavra;

        // Lê a palavra até o primeiro espaço
        iss >> palavra;
      
        busca(posicao, palavra);
        
    }

    
  
}
