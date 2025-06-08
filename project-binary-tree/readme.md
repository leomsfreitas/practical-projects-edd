# Projeto 04 – Árvore Binária

## Disciplina
**Estrutura de Dados – 2025/01**  
**Professor:** Jorge Francisco Cutigi

## Integrantes
Leo Freitas – SC3045366

## Objetivo
Implementar uma estrutura de árvore binária em C com suporte a operações básicas, como criação, percursos, busca de nós, cálculo de altura e impressão visual da árvore. A árvore é construída a partir de uma representação textual validada.

## Arquivos
- `t_binary_tree.h` / `t_binary_tree.c`: Implementação da TAD Árvore Binária
- `main.c`: Leitura de comandos e execução das operações na árvore
- `makefile`: Automatiza a compilação do projeto

## Funcionalidades
- Criação de árvores binárias a partir de representações em string
- Validação da representação textual para garantir que apenas árvores válidas sejam criadas
- Percursos em pré-ordem, em-ordem e pós-ordem
- Busca de nós por valor
- Cálculo da altura de subárvores
- Impressão visual da árvore no terminal
- Gerenciamento completo de memória

## Compilação
Com o `makefile` incluso, basta executar no terminal:

```bash
make
./main_program
```

Para limpar os arquivos objeto e binário:
```bash
make clean
```