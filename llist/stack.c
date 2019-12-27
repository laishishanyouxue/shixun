#include <stdio.h>
#include "stack.h"
STACK * stack_create(int size)
{
	return llist_create(size);
}
void stack_destroy(STACK *ptr)
{
	llist_destroy(ptr);
}
int stack_push(STACK *ptr,void *data)
{
	llist_insert(ptr,data,LLIST_FORWARD);
}
static int always_match( void *p1, void *p2)
{
	return 0;
}
int stack_pop(STACK *ptr,void *data)
{
	return llist_fetch(ptr,data,NULL,always_match);
}
