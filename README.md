# Gerador de Tabela Verdade ![C++](https://img.shields.io/badge/language-C++-blue)

Um programa em C++ que analisa expressões de lógica proposicional e gera automaticamente a tabela verdade completa.

## Operadores Suportados

| Símbolo | Nome            | Exemplo        |
|--------|-----------------|----------------|
| ~      | Negação (NOT)   | ~p             |
| &      | E (AND)         | p & q          |
| \|     | OU (OR)         | p \| q         |
| ->     | Implicação      | p -> q         |
| ==     | Bicondicional   | p == q         |
| ( )    | Parênteses      | (p -> q) & s   |

## Como funciona

1. **Entrada do usuário**
   - O usuário digita uma expressão lógica.

2. **Tokenização**
   - A expressão é dividida em tokens (variáveis, operadores, parênteses).

3. **Parsing (Algoritmo Shunting Yard)**
   - A expressão é convertida para Notação Polonesa Inversa (RPN).

4. **Avaliação do RPN**
   - A expressão em RPN é avaliada.

5. **Saída**
   - A tabela verdade completa é gerada.

## Exemplo

Entrada:
(p & q) -> r

Saída:
p q r | resultado
0 0 0 | 1
0 0 1 | 1
0 1 0 | 1
0 1 1 | 1
1 0 0 | 0
1 0 1 | 1
1 1 0 | 0
1 1 1 | 1
