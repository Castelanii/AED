#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();
  std::string line[n];
  std::vector<std::string> words[n]; // Vetor para armazenar as palavras
  for(int i = 0; i < n; i++){
    std::getline(std::cin, line[i]); // Lê a linha inteira
  
  }

  
  for(int i = 0; i < n; i++){
    //std::getline(std::cin, line[i]); // Lê a linha inteira
    std::istringstream iss(line[i]);

    
    
    // Lê cada palavra separadamente e as armazena no vetor
    std::string word;
    while (iss >> word) {  
        words[i].push_back(word);
        }

    // Ordena as palavras
    std::sort(words[i].begin(), words[i].end());


    auto last = std::unique(words[i].begin(), words[i].end());
      words[i].erase(last, words[i].end());
  }
  
  

  //printa as palavras com um espaço entre elas
  for(int i = 0; i < n; i++){
    for (const auto& w : words[i]) {
      if(i == n-1)
         std::cout << w;
      else
        std::cout << w << " ";
    }
    std::cout << std::endl;
  }
    // Exibe as palavras ordenadas
  

  return 0;
  
}