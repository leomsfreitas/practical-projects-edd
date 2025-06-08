#ifndef T_STACK_H
#define T_STACK_H

typedef struct _node {
    int item;
    struct _node* next;
} node;

typedef struct 
{
    node *top;
    int size;
} t_stack;

t_stack* create_stack();
int push(t_stack *stack, int item);
int pop(t_stack *stack);
int is_empty(t_stack *stack);

#endif