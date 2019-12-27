#ifndef QUEUE_H
#define QUEUE_H
#include "llist.h"
typedef LLIST QUEUE;
QUEUE *queue_create(int size);
void queue_destroy(QUEUE *);
int queue_enq(QUEUE *,void *data);
int queue_deq(QUEUE*,void *data);
#endif