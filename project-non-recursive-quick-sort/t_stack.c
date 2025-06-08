#include <stdlib.h>
#include "t_stack.h"

t_stack* create_stack() {
    t_stack *stack = (t_stack*)malloc(sizeof(t_stack));
    if (!stack) return NULL;
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

int push(t_stack *stack, int item) {
    node *new_node = (node*)malloc(sizeof(node));
    if (!new_node) return 0;

    new_node->item = item;
    new_node->next = stack->top;

    stack->top = new_node;
    stack->size++;
    return 1;
}

int pop(t_stack *stack) {
    if (is_empty(stack)) return 0;

    node *temp = stack->top;
    int item = temp->item;

    stack->top = temp->next;
    free(temp);

    stack->size--;
    return item;
}

int is_empty(t_stack *stack) {
    return stack->size <= 0;
}

int clear(t_stack *stack) {
    if (!stack) return 0;

    node *current = stack->top;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    stack->top = NULL;
    stack->size = 0;

    return 1;
}