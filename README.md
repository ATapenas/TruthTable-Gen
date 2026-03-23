# Gerador-TabelaVerdade ![C++](https://img.shields.io/badge/language-C++-blue)
Um simples gerador de tabela verdade para expressões de lógica proprosicional em c++

## Como isso funciona?

-Input do usuário
| ~      | Negação (NOT)   | ~p             
| &      | E  (AND)        | p & q          
| |      | OU (OR)         | p | q          
| ->     | Implicação      | p -> q         
| ==     | Bicondicional   | p == q         

- Tokenização
- Parsing via algoritmo Shunting Yard 
- Evaluação de expressão pós-fixa (Notação Polonesa Inversa)
- Output


