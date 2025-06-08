#ifndef T_QUEUE_H
#define T_QUEUE_H

#define MAX_SIZE 100

typedef struct {
    char *data[MAX_SIZE];
    int front;
    int rear;
    int size;
} t_queue;

t_queue *create_queue();
int is_empty(t_queue *queue);
int is_full(t_queue *queue);
int enqueue(t_queue *queue, char *value);
char* dequeue(t_queue *queue);
int destroy_queue(t_queue *queue);

#endif