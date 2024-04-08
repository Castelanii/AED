#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Função para verificar se o caractere é um operador
bool ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função para retornar a precedência do operador
int precedencia(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Função para converter expressão infix para postfix
string infixParaPosfixa(string infix) {
    stack<char> pilha;
    string posfixa = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Se o caractere for um operando, adicione ao resultado
        if (isalnum(c))
            posfixa += c;
        // Se o caractere for um parêntese esquerdo, empilhe
        else if (c == '(')
            pilha.push(c);
        // Se o caractere for um parêntese direito, desempilhe até encontrar o parêntese esquerdo correspondente
        else if (c == ')') {
            while (!pilha.empty() && pilha.top() != '(') {
                posfixa += pilha.top();
                pilha.pop();
            }
            pilha.pop(); // Desempilhe o parêntese esquerdo
        }
        // Se o caractere for um operador
        else if (ehOperador(c)) {
            // Desempilhe os operadores com precedência maior ou igual ao operador atual
            while (!pilha.empty() && precedencia(pilha.top()) >= precedencia(c)) {
                posfixa += pilha.top();
                pilha.pop();
            }
            // Empilhe o operador atual
            pilha.push(c);
        }
    }

    // Desempilhe todos os operadores restantes
    while (!pilha.empty()) {
        posfixa += pilha.top();
        pilha.pop();
    }

    return posfixa;
}

int main() {
     int n, i;
    cin >> n;
    string expressao_infixa[n];
   
    for(i=0;i<n;i++)cin >> expressao_infixa[n];
    
    for(i=0;i<n;i++){
         string expressao_posfixa = infixParaPosfixa(expressao_infixa[n]);
         cout <<  expressao_posfixa << endl;
    }
   
    

    return 0;
}
