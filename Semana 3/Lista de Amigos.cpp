//Esse programa consiste em pegar uma lista de nomes (amigos) e uma lista de 
//indicação de novos nomes (amigos) e juntar ambas as listas, porém se 
//um nome for escrito ao após a incersão das duas listas ele indica que a segunda
//lista deve ser inserida antes dele quando elas forem juntadas

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {

  std::string line[2];
  std::vector<std::string> words; // Vetor para armazenar as palavras
  for(int i = 0; i < 2; i++){
    std::getline(std::cin, line[i]); // Lê a linha inteira

  }
  char indicacao[100];
  std::cin >> indicacao;

  //se não tem nenhuma indicação
  if(strcmp(indicacao,"nao")==0){
    
    //vai adicionar os valores das duas linhas em ordem
    for(int i = 0; i < 2; i++){
      //std::getline(std::cin, line[i]); // Lê a linha inteira
      std::istringstream iss(line[i]);



      // Lê cada palavra separadamente e as armazena no vetor
      std::string word;
      while (iss >> word) {  
          words.push_back(word);
          }
    }
    
  }
  //se tem uma indicação
  else{

    //pega os valores da primeira linha
    std::istringstream iss(line[0]);
    std::string word;
    
    //while que passa por cada palavra da primeira linha
    while (iss >> word) {  

      //se a palavra for igual a indicação, ele repete o processo de pegar os valores
      //e entrar em um while, mas da segunda linha(indicação) dos amigos
      //logo a lista de indicação será adicionada no vetor que possui os
      // nomes antes do amigo que foi indicado, após adicionar a linha de indicação
      // ele vai voltar para primeira linha a partir do nome que foi indicado
      if(word==indicacao){
         std::istringstream iss1(line[1]);
         std:: string word1;
        while(iss1>>word1){
          words.push_back(word1);
        }
      }
        words.push_back(word);
        }
  }



    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    // Exibe as palavras ordenadas


  return 0;

}