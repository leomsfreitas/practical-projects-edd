#include <stdlib.h>
#include "bank_queue.h"

bank_queue* create_bank_queue() {
    bank_queue *bq = (bank_queue*) malloc(sizeof(bank_queue));
    if (!bq) return NULL;

    bq->general_queue = create_queue();
    bq->priority_queue = create_queue();
    bq->priority_count = 0;

    if (!bq->general_queue || !bq->priority_queue) {
        destroy_queue(bq->general_queue);
        destroy_queue(bq->priority_queue);
        free(bq);
        return NULL;
    }

    return bq;
}

char* call_next_client(bank_queue *bq) {
    if (!bq) return NULL;

    int has_priority = !is_empty(bq->priority_queue);
    int has_general = !is_empty(bq->general_queue);

    if (has_priority && bq->priority_count < 3) {
        bq->priority_count++;
        return dequeue(bq->priority_queue);
    }

    if (has_general) {
        bq->priority_count = 0;
        return dequeue(bq->general_queue);
    }

    if (has_priority) {
        return dequeue(bq->priority_queue);
    }

    return NULL;
}

void destroy_bank_queue(bank_queue *bq) {
    if (!bq) return;
    destroy_queue(bq->general_queue);
    destroy_queue(bq->priority_queue);
    free(bq);
}