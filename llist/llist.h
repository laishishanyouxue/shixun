#ifndef LLIST_H
#define LLIST_H
#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2
struct llist_node_st
{
	struct llist_node_st *prev;
	struct llist_node_st *next;
	char data[0];
};
typedef struct
{
	int size;
	struct llist_node_st head;
}LLIST;
LLIST *llist_create(int size);
int llist_insert(LLIST *ptr,const void *data,int mode);
void llist_travle(LLIST *ptr,void (*op)(void *));
void * llist_find(LLIST *ptr, void *key,int (*cmp)( void *, void *));
void llist_delete(LLIST *ptr,void *key,int (*cmp)( void *, void *));
int llist_fetch(LLIST *ptr,void *data,void *key,int (*cmp)( void *, void *));
void llist_destroy(LLIST *ptr);
#endif