#ifndef T_BINARY_TREE_H
#define T_BINARY_TREE_H

typedef struct _node {
    char value;
    struct _node* left;
    struct _node* right;
} t_node;

typedef struct {
    t_node* root;   
} t_binary_tree;

t_binary_tree* create(char *representation);
void pre_order(t_node* root);
void in_order(t_node* root);
void post_order(t_node* root);
t_node* find_node(t_node* root, char value);
int height(t_node* root);
void print_tree(t_node* root, int space);

#endif