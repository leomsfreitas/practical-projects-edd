#ifndef BANK_QUEUE_H
#define BANK_QUEUE_H
#include "t_queue.h"

typedef struct {
    t_queue *general_queue;
    t_queue *priority_queue;
    int priority_count;
} bank_queue;

bank_queue *create_bank_queue();
char* call_next_client(bank_queue *bq);
void destroy_bank_queue(bank_queue *bq);

#endif