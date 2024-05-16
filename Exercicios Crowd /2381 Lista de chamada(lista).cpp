//2381 Lista de chamada(Lista), sim eu usei o gept nessa prq eu gastei 5 dias para não sair do 
//lugar entao fica com esses nodes (vou explicar lista no arquivo de lista encadeada)
#include <iostream>
#include <cstring>
#include <cstdlib> // Para o malloc

struct Node {
    std::string info;
    Node* prox;
    Node(const std::string& value) : info(value), prox(nullptr) {}
};

Node* inserirIni(Node* lista, const std::string& v) {
    Node* novo = (Node*)malloc(sizeof(Node)); 
    novo->info = v; 
    novo->prox = lista; 
    lista = novo; 
    return lista; 
}

Node* inserirFim(Node* lista, const std::string& v) {
    Node* novo = (Node*)malloc(sizeof(Node)); 
    novo->info = v; 
    novo->prox = nullptr; 

    if (lista == nullptr) {
        lista = novo;
    } else {
        Node* aux = lista;
        while (aux->prox != nullptr) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return lista; 
}

Node* merge(Node* esq, Node* dir) {
    Node* lista = nullptr;
    Node* ultimo = nullptr;

    while (esq != nullptr && dir != nullptr) {
        Node* novo = (Node*)malloc(sizeof(Node));
        if (esq->info <= dir->info) {
            novo->info = esq->info;
            esq = esq->prox;
        } else {
            novo->info = dir->info;
            dir = dir->prox;
        }
        novo->prox = nullptr;

        if (ultimo == nullptr) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    while (esq != nullptr) {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->info = esq->info;
        novo->prox = nullptr;
        if (ultimo == nullptr) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
        esq = esq->prox;
    }

    while (dir != nullptr) {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->info = dir->info;
        novo->prox = nullptr;
        if (ultimo == nullptr) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
        dir = dir->prox;
    }

    return lista;
}

Node* mergeSort(Node* lista, int t) {
    if (lista == nullptr || t <= 1) return lista;

    int meio = t / 2;
    Node* esq = nullptr;
    Node* dir = nullptr;
    Node* aux = lista;

    for (int i = 0; aux != nullptr && i < t; ++i) {
        if (i < meio) {
            esq = inserirFim(esq, aux->info);
        } else {
            dir = inserirFim(dir, aux->info);
        }
        aux = aux->prox;
    }

    esq = mergeSort(esq, meio);
    dir = mergeSort(dir, t - meio);

    return merge(esq, dir);
}

void listar(Node* lista) {
    Node* elemento = lista;
    while (elemento != nullptr) {
        std::cout << elemento->info << std::endl;
        elemento = elemento->prox;
    }
}
void listarEspecifico(Node* lista, int c){
      Node* elemento;
    int posicao=1;
         for(elemento = lista; elemento!=NULL; elemento=elemento->prox){
             if(posicao == c)std::cout<< elemento->info << std::endl;
             posicao++;
      } 
}
int main() {
    int n, k;
    std::cin >> n >> k;
    Node* listaor = nullptr;
    std::string nome;

    for (int y = 0; y < n; ++y) {
        std::cin >> nome;
        listaor = inserirIni(listaor, nome);
    }

  
    listaor = mergeSort(listaor, n);

    listarEspecifico(listaor,k);


    // Liberar memória
    while (listaor != nullptr) {
        Node* temp = listaor;
        listaor = listaor->prox;
        delete temp;
    }

    return 0;
}
