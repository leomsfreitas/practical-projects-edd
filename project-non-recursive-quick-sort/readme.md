# Projeto 02 – QuickSort Não Recursivo

## Disciplina
**Estrutura de Dados – 2025/01**  
**Professor:** Jorge Francisco Cutigi

## Integrantes
Leo Freitas – SC3045366

## Objetivo
Implementar o algoritmo QuickSort de forma iterativa, utilizando uma TAD `t_stack` em C para simular a pilha da recursão.

## Arquivos
- `nr_quicksort.h` / `nr_quicksort.c`: Implementação do QuickSort não recursivo
- `t_stack.h` / `t_stack.c`: TAD Pilha utilizada pelo algoritmo
- `main.c`: Leitura da entrada e execução da ordenação
- `makefile`: Automatiza a compilação do projeto

## Funcionalidades
- QuickSort iterativo com controle manual da pilha
- Política de inserção que favorece processar a menor partição primeiro (reduz uso da pilha)
- Entrada e saída por terminal padrão
- Gerenciamento completo de memória

## Respostas exigidas
> A estratégia faz sentido e foi implementada: priorizei o processamento da partição menor para garantir que o uso da pilha fique em O(log n).

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