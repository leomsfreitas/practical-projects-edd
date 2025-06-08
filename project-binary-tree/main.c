#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_binary_tree.h"

#define MAX_COMMAND_SIZE 16
#define MAX_INPUT_SIZE 256

int main() {
    t_binary_tree *tree = NULL;
    char command[MAX_COMMAND_SIZE];
    char input[MAX_INPUT_SIZE];

    while (scanf("%s", command) == 1) {
        if (strcmp(command, "create") == 0) {
            scanf("%s", input);
            tree = create(input);
        }
        else if (strcmp(command, "print") == 0) {
            if (tree) print_tree(tree->root, 0);
            printf("\n");
        }
        else if (strcmp(command, "pre") == 0) {
            if (tree) pre_order(tree->root);
            printf("\n");
        }
        else if (strcmp(command, "in") == 0) {
            if (tree) in_order(tree->root);
            printf("\n");
        }
        else if (strcmp(command, "post") == 0) {
            if (tree) post_order(tree->root);
            printf("\n");
        }
        else if (strcmp(command, "height") == 0) {
            char node_value;
            scanf(" %c", &node_value);
            if (tree) {
                t_node *node = find_node(tree->root, node_value);
                if (node) printf("%d", height(node));
                printf("\n");
            }
        }
        else if (strcmp(command, "exit") == 0) {
            destroy_tree(tree);
            break;
        }
        else {
            printf("invalid\n");
        }
    }
    return 0;
}
