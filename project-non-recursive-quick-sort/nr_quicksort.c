#include <stdio.h>
#include <stdlib.h>
#include "t_stack.h"

int partition(int *array, int low, int high) {
    int i = low - 1;
    int j = high + 1;
    int pivot = array[(low + high) / 2];

    while (i < j) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    return j;
}

void nr_quick_sort(int *array, int size) {
    if (size < 2) return;

    t_stack *stack = create_stack();

    if (!stack) return;

    push(stack, 0); // high
    push(stack, size - 1); // low

    while (!is_empty(stack)) {
        int high = pop(stack);
        int low = pop(stack);

        int pivot_index = partition(array, low, high);

        if (low < pivot_index) {
            push(stack, low);
            push(stack, pivot_index);
        }

        if (pivot_index + 1 < high) {
            push(stack, pivot_index + 1);
            push(stack, high);
        }
    }
    
    clear(stack);
    free(stack);
}