#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank_queue.h"

#define MAX_NAME_LEN 100
#define INITIAL_CAPACITY 16

int main(int argc, char const *argv[]) {
    bank_queue *bank = create_bank_queue();
    if (!bank) return 1;

    char command, name[MAX_NAME_LEN];
    char **served = (char**) malloc(sizeof(char*) * INITIAL_CAPACITY);
    int served_count = 0, served_capacity = INITIAL_CAPACITY;

    while (scanf(" %c", &command) == 1) {
        if (command == 'f') break;

        if (command == 'g' || command == 'p') {
            scanf(" %s", name);
            char *client_name = strdup(name);
            if (!client_name) continue;

            if (command == 'g') {
                enqueue(bank->general_queue, client_name);
            } else {
                enqueue(bank->priority_queue, client_name);
            }
        }

        if (command == 's') {
            char *next = call_next_client(bank);
            if (next) {
                if (served_count == served_capacity) {
                    served_capacity *= 2;
                    served = realloc(served, sizeof(char*) * served_capacity);
                    if (!served) return 1;
                }
                served[served_count++] = next;
            }
        }
    }

    for (int i = 0; i < served_count; i++) {
        puts(served[i]);
        free(served[i]);
    }

    free(served);
    destroy_bank_queue(bank);
    return 0;
}
