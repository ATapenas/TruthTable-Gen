# Gerador-TabelaVerdade ![C++](https://img.shields.io/badge/language-C++-blue)
Um simples gerador de tabela verdade para expressões de lógica proprosicional em c++

## Como isso funciona?

-Input do usuário
| Symbol | Name                | Example        |
|--------|---------------------|----------------|
| ~      | Negation (NOT)      | ~p             |
| &      | AND                 | p & q          |
| \|     | OR                  | p \| q         |
| ->     | Implication         | p -> q         |
| ==     | Biconditional       | p == q         |
| ( )    | parentheses         | (p -> q) & s   |

- Tokenização
- Parsing via algoritmo Shunting Yard 
- Evaluação de expressão pós-fixa (Notação Polonesa Inversa)
- Output


