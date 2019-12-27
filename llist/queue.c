#include <stdio.h>
#include "queue.h"
QUEUE *queue_create(int size)
{
	return llist_create(size);
}
void queue_destroy(QUEUE *ptr)
{
	llist_destroy(ptr);
}
int queue_enq(QUEUE *ptr,void *data)
{
	return llist_insert(ptr,data,LLIST_BACKWARD);
}
static int always_match( void *p1, void *p2)
{
	return 0;
}
int queue_deq(QUEUE *ptr,void *data)
{
	return llist_fetch(ptr,data,NULL,always_match);
}
