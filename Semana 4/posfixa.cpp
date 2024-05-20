#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

// Função para verificar se o caractere é um operador
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Função para verificar a precedência dos operadores
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Função para converter uma expressão infixa para posfixa
std::string infixToPostfix(const std::string &expression) {
    std::stack<char> ops; // Pilha para operadores
    std::string postfix;  // Resultado posfixo

    for (char c : expression) {
        if (std::isspace(c)) {
            continue; // Ignorar espaços em branco
        }
        if (std::isalnum(c)) {
            // Se for um operando, adiciona à saída
            postfix += c;
        } else if (c == '(') {
            // Se for um parêntese esquerdo, push na pilha
            ops.push(c);
        } else if (c == ')') {
            // Se for um parêntese direito, pop até encontrar '('
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            if (!ops.empty()) {
                ops.pop(); // Remove '('
            }
        } else if (isOperator(c)) {
            // Se for um operador, verifica a precedência
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                if (c == '^' && ops.top() == '^') break; // Associa da direita para a esquerda para '^'
                postfix += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    // Pop os operadores restantes na pilha
    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }

    return postfix;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // Ignorar o newline após N
    std::vector<std::string> expressions(N);

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, expressions[i]);
    }

    for (const std::string &expression : expressions) {
        std::cout << infixToPostfix(expression) << std::endl;
    }

    return 0;
}
