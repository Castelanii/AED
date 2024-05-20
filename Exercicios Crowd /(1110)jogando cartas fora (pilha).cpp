// Esse código consistem em pegar cartas de um baralho, remover uma de cada vez,
// e colocar a proxima(novo topo) na base, e queremos achar a carta que sobrou
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

struct Bar {
  int valor;
  struct Bar *prox;
};
typedef struct Bar *Ba;

Ba Push(Ba b, int v) {
  Ba novo = (Ba)malloc(sizeof(Bar));
  novo->valor = v;
  novo->prox = b;
  return novo;
}
Ba pop(Ba b, int *v) {
  Ba aux = b;
  if (aux == NULL) {
    return NULL;
  }
  *v = b->valor;
  b = b->prox;
  free(aux);
  return b;
}

Ba inserirbase(Ba b, int v) {
  Ba novo = (Ba)malloc(sizeof(Bar));
  novo->valor = v;
  novo->prox = NULL;
  if (b == NULL)
    return novo;
  Ba aux;
  for (aux = b; aux->prox != NULL; aux = aux->prox)
    ;
  // std::cout << "aux: " << aux->valor << std::endl;
  aux->prox = novo;
  return b;
}
void limparPilha(Ba &b) {
  int temp;
  while (b != NULL) {
    b = pop(b, &temp);
  }
}

int main() {
  int n = 1, a, k;
  Ba b = NULL;
  std::cin >> n;

  while (n != 0) {
    for (int i = n; i != 0; i--) {
      b = Push(b, i);
    }

    std::cout << "Discarded cards: ";
    bool primeiro = true;

    while (b->prox != NULL) {
      if (!primeiro)
        std::cout << ", ";
      std::cout << b->valor;
      b = pop(b, &k);

      // move nova carta
      b = inserirbase(b, b->valor);
      b = pop(b, &k);
      primeiro = false;
    }
    std::cout << std::endl;
    std::cout << "Remaining card: " << b->valor << std::endl;
    std::cin >> n;
    limparPilha(b);
  }
}
