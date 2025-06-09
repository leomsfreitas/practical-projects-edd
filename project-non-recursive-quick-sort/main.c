#include <stdio.h>
#include <stdlib.h>
#include "nr_quicksort.h"

/* 
A estratégia faz sentido e foi implementada: priorizei o processamento da partição menor para garantir que o uso da pilha fique em O(log n).
*/

int main() {
    int N;
    scanf("%d", &N);

    int *array = (int *)malloc(N * sizeof(int));
    if (!array) return 1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    nr_quick_sort(array, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}