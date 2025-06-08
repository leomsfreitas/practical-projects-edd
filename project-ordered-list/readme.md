# Projeto 01 – Lista Ordenada (TAD)

## Disciplina
**Estrutura de Dados – 2025/01**  
**Professor:** Jorge Francisco Cutigi

## Integrantes
Leo Freitas – SC3045366

## Objetivo
Implementar uma TAD `t_ordered_list` em C que armazena inteiros de forma ordenada, com alocação dinâmica e expansão automática da memória.

## Arquivos
- `ordered_list.h`: Definições da TAD
- `ordered_list.c`: Implementações
- `main.c`: Testes da TAD

## Funcionalidades
- Inserção ordenada
- Redimensionamento automático (duplicação)
- Busca, remoção (por índice, valor ou final)
- Impressão e mesclagem de listas
- Gerenciamento completo de memória

## Respostas exigidas
> **Ponto forte/fraco:**  
> Ordem facilita buscas (ex: binária), mas insere/remover exige reorganização.  
> - Busca: O(log n) (busca binária)
> - Inserção: O(n)
> - Remoção: O(n)

> **Expansão:**  
> Memória duplicada ao atingir o limite.

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