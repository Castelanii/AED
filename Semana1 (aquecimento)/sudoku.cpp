#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


//Função principal
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

//função main do código
int main() {
  int n;
  std::cin >> n;
  char  s[n][9][9];
  for (int i=0;i<n;i++){
    for (int x = 0; x < 9; x++){
      for (int y = 0; y < 9; y++)
        std::cin >> s[i][x][y];
    }
   
  }
  for(int i=0;i<n;i++){
     if(sudoku(s[i]) == 1)  printf("Instancia %d\nSIM\n\n",i+1);
    else printf("Instancia %d\nNAO\n\n",i+1);
  }
  
   

}