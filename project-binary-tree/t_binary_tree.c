#include <stdio.h>
#include <stdlib.h>
#include "t_binary_tree.h"

t_node* create_node(char value) {
    t_node *node = (t_node*)malloc(sizeof(t_node));
    if (!node) return NULL;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

t_node* parse_tree(char **str) {
    if (**str != '(') return NULL;
    (*str)++;

    if (**str == ')') {
        (*str)++;
        return NULL;
    }

    char value = **str;
    (*str)++;

    // subárvore esquerda
    if (**str == ',') (*str)++;
    t_node *left = parse_tree(str);

    
    // subárvore direita
    if (**str == ',') (*str)++;
    t_node *right = parse_tree(str);

    if (**str == ')') (*str)++;

    t_node *node = create_node(value);
    node->left  = left;
    node->right = right;
    return node;
}

int is_valid_expression(char **rep) {
    if (**rep != '(') return 0; // inicio de subárvore?
    (*rep)++;

    // subárvore vazia
    if (**rep == ')') {
        (*rep)++;
        return 1;
    }

    if (**rep == '(' || **rep == ')' || **rep == ',' || **rep == '\0') return 0; // valida nó
    (*rep)++; // avança para o prox caractere

    if (**rep != ',') return 0; // virgula separadora
    (*rep)++; // avança para a subárvore esquerda

    if (!is_valid_expression(rep)) return 0; // subárvore esquerda
    if (**rep != ',') return 0; // virgula separadora
    (*rep)++; // avança para a subárvore direita

    if (!is_valid_expression(rep)) return 0; // subárvore direita
    if (**rep != ')') return 0; // fechamento
    (*rep)++; // avança para o prox caractere

    return 1;
}

int is_valid_tree_expression(char *representation) {
    char *rep = representation;
    return is_valid_expression(&rep) && *rep == '\0';
}

t_binary_tree* create(char *representation) {
    if (!is_valid_tree_expression(representation)) {
        printf("invalid\n");
        return NULL;
    }

    t_binary_tree *tree = (t_binary_tree*)malloc(sizeof(t_binary_tree));
    if (!tree) return NULL;
    tree->root = parse_tree(&representation);
    return tree;
}

void pre_order(t_node* root) {
    if (!root) return;
    printf("%c ", root->value);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(t_node* root) {
    if (!root) return;
    in_order(root->left);
    printf("%c ", root->value);
    in_order(root->right);
}

void post_order(t_node* root) {
    if (!root) return;
    post_order(root->left);
    post_order(root->right);
    printf("%c ", root->value);
}

t_node* find_node(t_node* root, char value) {
    if (!root) return NULL;
    if (root->value == value) return root;

    t_node* left_result = find_node(root->left, value);
    if (left_result) return left_result;

    return find_node(root->right, value);
}

int height(t_node* root) {
    if (!root) return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

void print_tree(t_node* root, int space) {
    if (!root) return;

    space += 3;

    print_tree(root->right, space);

    printf("\n");
    for (int i = 3; i < space; i++) {
        printf(" ");
    }
    printf("%c", root->value);

    print_tree(root->left, space);
}

void destroy_tree(t_node* root) {
    if (!root) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}