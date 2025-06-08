#include <stdlib.h>
#include <string.h>
#include "t_queue.h"

t_queue* create_queue() {
    t_queue *queue = (t_queue*) malloc(sizeof(t_queue));
    if (!queue) return NULL;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int is_empty(t_queue *queue) {
    return queue->size == 0;
}

int is_full(t_queue *queue) {
    return queue->size == MAX_SIZE;
}

int enqueue(t_queue *queue, char *value) {
    if (!queue || is_full(queue)) return 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;
    return 1;
}

char* dequeue(t_queue *queue) {
    if (!queue || is_empty(queue)) return NULL;

    char *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return value;
}

int destroy_queue(t_queue *queue) {
    if (!queue) return 0;

    for (int i = 0; i < queue->size; i++) {
        int idx = (queue->front + i) % MAX_SIZE;
        free(queue->data[idx]);
    }

    free(queue);
    return 1;
}