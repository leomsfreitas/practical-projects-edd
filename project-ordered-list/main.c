#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.c"

int main() {
    t_ordered_list *list_pair = create_ordered_list(5);
    t_ordered_list *list_odd = create_ordered_list(5);
    insert(list_pair, 10);
    insert(list_pair, 2);
    insert(list_pair, 8);
    insert(list_pair, 4);
    insert(list_pair, 12);
    insert(list_pair, 6);

    insert(list_odd, 1);
    insert(list_odd, 9);
    insert(list_odd, 5);
    insert(list_odd, 3);
    insert(list_odd, 7);
    insert(list_odd, 11);

    printf("Lista ordenada após inserções\n");
    printf("Lista de Pares: ");
    print_ordered_list(list_pair);
    printf("Lista de Impares: ");
    print_ordered_list(list_odd);

    t_ordered_list *list_numbers = merge(list_pair, list_odd);

    printf("Lista Mesclada: ");
    print_ordered_list(list_numbers);

    int search_value = 11;
    int index = search(list_numbers, search_value);
    if (index != -1) {
        printf("Elemento %d encontrado na posição %d.\n", search_value, index);
    } else {
        printf("Elemento %d não encontrado.\n", search_value);
    }

    int remove_value = 10;
    if (remove_by_value(list_numbers, remove_value)) {
        printf("Elemento %d removido com sucesso.\n", remove_value);
    } else {
        printf("Elemento %d não encontrado para remoção.\n", remove_value);
    }

    printf("Lista ordenada após remoção: ");
    print_ordered_list(list_numbers);

    destroy(list_numbers);
    destroy(list_pair);
    destroy(list_odd);

    return 0;
}