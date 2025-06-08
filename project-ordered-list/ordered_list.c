#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"

/*
Leo Freitas - SC3045366

1. Lista ordenada facilita achar dados rápido (pode usar busca binária), e tudo já fica organizado. Mas inserir ou remover é mais lento, porque tem que mexer em vários elementos pra manter a ordem.
    - Busca: O(log n) usando busca binária.
    - Inserção: O(n), pois pode ser necessário deslocar vários elementos.
    - Remoção: O(n), pois também pode ser necessário deslocar elementos.

2. Eu optei por duplicar o espaço da memória sempre que ela enchesse, reduzindo a frequência de realocações e melhorando a eficiência.
*/

t_ordered_list *create_ordered_list(int max) {
    t_ordered_list *t = (t_ordered_list *)malloc(sizeof(t_ordered_list));
    t->items = (int *)malloc(sizeof(int) * max);
    t->max = max;
    t->n = 0;
    return t;
}

int size(t_ordered_list *ordered_list) {
    return ordered_list->n;
}

int is_empty(t_ordered_list *ordered_list) {
    return ordered_list->n <= 0;
}

int is_full(t_ordered_list *ordered_list) {
    return ordered_list->n >= ordered_list->max;
}

void destroy(t_ordered_list *ordered_list) {
    free(ordered_list->items);
    free(ordered_list);
}

void clear(t_ordered_list *ordered_list) {
    ordered_list->n = 0;
}

int insert(t_ordered_list *ordered_list, int value) {
    int temp;
    if (is_full(ordered_list)) {
        ordered_list->max = ordered_list->max * 2;
        ordered_list->items = (int *)realloc(ordered_list->items, ordered_list->max * sizeof(int));
    }

    int i;
    for (i = 0; i < ordered_list->n; i++) {
        if (*(ordered_list->items + i) >= value)
            break;
    }
    for (int j = ordered_list->n; j > i; j--) {
        *(ordered_list->items + j) = *(ordered_list->items + j - 1);
    }

    *(ordered_list->items + i) = value;
    ordered_list->n++;
    return 1;
}

int search(t_ordered_list *ordered_list, int value) {
    for (int i = 0; i < ordered_list->n; i++) {
        if (*(ordered_list->items + i) == value)
            return i;
    }
    return -1;
}

int remove_by_index(t_ordered_list *ordered_list, int index) {
    if (index + 1 > ordered_list->n && index < 0)
        return 0;
    for (int i = index; i < ordered_list->n - 1; i++) {
        *(ordered_list->items + i) = *(ordered_list->items + i + 1);
    }
    ordered_list->n--;
    return 1;
}

int remove_by_value(t_ordered_list *ordered_list, int value) {
    for (int i = 0; i < ordered_list->n; i++) {
        if (*(ordered_list->items + i) == value)
            return remove_by_index(ordered_list, i);
    }
    return 0;
}

int remove_end(t_ordered_list *ordered_list) {
    if (is_empty(ordered_list))
        return 0;

    ordered_list->n--;
    return 1;
}

void print_ordered_list(t_ordered_list *ordered_list) {
    for (int i = 0; i < ordered_list->n; i++) {
        printf("%d\t", *(ordered_list->items + i));
    }
    printf("\n");
}

t_ordered_list *merge(t_ordered_list *ordered_list_1, t_ordered_list *ordered_list_2) {
    int new_max = ordered_list_1->n + ordered_list_2->n;
    t_ordered_list *merge_list = create_ordered_list(new_max);
    merge_list->max = new_max;

    for (int i = 0; i < ordered_list_1->n; i++) {
        insert(merge_list, *(ordered_list_1->items + i));
    }

    for (int i = 0; i < ordered_list_2->n; i++) {
        insert(merge_list, *(ordered_list_2->items + i));
    }
    return merge_list;
}