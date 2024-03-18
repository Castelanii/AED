#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>


//função para verificar se a coluna do sudoku possui algum numero repetido 
int coluna(char sudoku[9][9], int coluna){
 int i, j;

  //for para passar dentre os numeros 1 a 9
  for (j = 1; j < 10; j++){
    int contador = 0;

    //for para passar dentre as colunas do sudoku verificando quantas vezes o numero j aparece
    for(i = 0; i < 9; i++){
       //'0' + caractere faz o caractere virar um inteiro
      if(sudoku[i][coluna] == ('0' + j)){
        contador++;
      } 
    }
    if ( contador> 1){
      return 0;
    }
  }


  return 1;
}
//função para verificar se a linha do sudoku possui algum numero repetido
int linha(char sudoku[9][9], int linha){
 int i, j;

  //for para passar dentre os numeros 1 a 9
  for (j = 1; j < 10; j++){
    int contador = 0;

    //for para passar dentre as linhas do sudoku verificando quantas vezes o numero j aparece
    for(i = 0; i < 9; i++){
      if(sudoku[linha][i] == j){
        contador++;
      } 
    }
    if ( contador> 1){
      return 0;
    }
  }

  return 1;
}


//função para verificar se a submatriz 3x3 do sudoku possui algum numero repetido
int submatriz(char sudoku[9][9], int linha, int coluna){
  int i, j, k;

  //for para passar dentre os numeros 1 a 9
  for (j = 1; j < 10; j++){
    int contador = 0;

    //for para passar dentre as linhas e colunas da submatriz verificando quantas vezes o numero j aparece
    for(i = 0; i < 3; i++){
      for(k = 0; k < 3; k++){
        if(sudoku[linha+k][coluna+i] == ('0' + j)){
          contador++;
        }
      }
    }
    if (contador >1) return 0;
  }

  return 1;
}
//função para verificar se o sudoku está completo
int completo(char sudoku[9][9]){
  int i,j, zeros = 0;
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if(sudoku[i][j] == ('0' + 0))
        zeros++;
    }
  }
  if(zeros == 0)
    return 1;

  return 0;
}


int sudoku(char sudoku[9][9]){
    int j, i;

  //função para verificar se a coluna do sudoku possui algum numero repetido
  for (j = 0; j < 9; j++){
    if(coluna(sudoku, j) == 0)
      return 0;
  }
  //função para verificar se a linha do sudoku possui algum numero repetido
  for (i = 0; i < 9; i++){
    if(linha(sudoku, i) == 0)
      return 0;
  }

  //função para verificar se a submatriz 3x3 do sudoku possui algum numero repetido
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      if(submatriz(sudoku, i*3, j*3) == 0)
        return 0;
    }
  }

  return 1;
}
//função para pedir para o usuário preencher os zeros
int preencher(char sudo[9][9]){
  for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
          std::cout << sudo[i][j] << " ";
      }
      std::cout << std::endl;
  }
  int linha, coluna;
  char numero;
  std::cout <<"Digite a linha e a coluna que deseja preencher: ";
  std::cin >> linha >> coluna;
  std::cout <<"Digite o numero que deseja preencher: ";
  std::cin >> numero;
  sudo[linha-1][coluna-1] = numero;
  if(sudoku(sudo)==1){
    if(completo(sudo)==1)
      return 1;
  }else{
    std::cout <<"Sudoku invalido\n";
    sudo[linha-1][coluna-1] = '0';
  }


  return 0;

}
//Função print

//função main do código
int main() {
  std::ifstream arquivo("sudoku.txt");
  int i,j;
  char sudo[9][9];
  // Verifica se o arquivo foi aberto corretamente
  if (!arquivo) {
      std::cerr << "Erro ao abrir o arquivo." << std::endl;
      return 1;
  }

  
  // Lê o arquivo linha por linha e imprime na tela
  for(i = 0; i < 9; i++){
    std::string linha;
    getline(arquivo, linha);
    for(j = 0; j < 9; j++){
      sudo[i][j]= linha[j];
    }
  }
  /*for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
          std::cout << sudo[i][j] << " ";
      }
      std::cout << std::endl;
  }*/
  while(completo(sudo)!=1 || sudoku(sudo)!=1){
    preencher(sudo);
  }
  std::cout << completo(sudo);
  

  // Fecha o arquivo
  arquivo.close();


  
  

return 0;

}
