# Projeto 03 – Fila do Banco

## Disciplina
**Estrutura de Dados – 2025/01**  
**Professor:** Jorge Francisco Cutigi

## Integrantes
Leo Freitas – SC3045366

## Objetivo
Simular uma fila de atendimento de banco com duas filas (geral e prioridade), respeitando a regra de que no máximo três clientes prioritários podem ser atendidos seguidamente antes de chamar um cliente da fila geral.

## Arquivos
- `t_queue.h` / `t_queue.c`: TAD Fila estática circular
- `bank_queue.h` / `bank_queue.c`: Lógica de atendimento com controle de prioridade
- `main.c`: Leitura dos comandos e controle do fluxo
- `makefile`: Automatiza a compilação

## Funcionalidades
- Inserção de clientes nas filas geral (`g`) e prioridade (`p`)
- Chamada do próximo cliente (`s`) conforme as regras
- Encerramento (`f`) com impressão da ordem de atendimento
- Fila estática circular para gerenciar os dados
- Liberação adequada de memória

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