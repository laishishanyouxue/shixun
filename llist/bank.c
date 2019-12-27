#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"
#if 0
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
#endif
LLIST *llist_create(int size)
{
	LLIST *new;
	new=malloc(sizeof(*new));
	if(new==NULL)
	{
		return NULL;
	}
	new->size=size;
	new->head.prev=new->head.next=&new->head;
	return new;
}

int llist_insert(LLIST *ptr,const void *data,int mode)
{
	struct llist_node_st *newnode;
	newnode=malloc(sizeof(*newnode)+ptr->size);
	if(newnode==NULL)
	{
		return -1;
	}
	memcpy(newnode->data,data,ptr->size);
	if(mode==LLIST_FORWARD)
	{
		newnode->next=ptr->head.next;
		newnode->prev=&ptr->head;
	}
	else if(mode==LLIST_BACKWARD)
	{
		newnode->next=&ptr->head;
		newnode->prev=ptr->head.prev;
	}
	newnode->next->prev=newnode;
	newnode->prev->next=newnode;
	return 0;
}
void llist_travle(LLIST *ptr,void (*op)(void *))
{
	struct llist_node_st *cur;
	for(cur=ptr->head.next;cur!=&ptr->head;cur=cur->next)
	{
		op(cur->data);
	}
}
static struct llist_node_st *find__(LLIST *ptr, void *key,int (*cmp)( void *, void *))
{
	struct llist_node_st *cur;
	for(cur=ptr->head.next;cur!=&ptr->head;cur=cur->next)
	{
		if(cmp(key,cur->data)==0)
		{
			break;
		}
	}
	return cur;	
}

void * llist_find(LLIST *ptr, void *key,int (*cmp)( void *, void *))
{
	struct llist_node_st *node;
	node=find__(ptr,key,cmp);
	if(node==&ptr->head)
	{
		return NULL;
	}
	return node->data;
}

void llist_delete(LLIST *ptr,void *key,int (*cmp)( void *, void *))
{
	struct llist_node_st *node;
	node=find__(ptr,key,cmp);
	if(node==&ptr->head)
	{
		return;
	}
	node->next->prev=node->prev;
	node->prev->next=node->next;
	free(node);
}
int llist_fetch(LLIST *ptr,void *data,void *key,int (*cmp)( void *, void *))
{
	struct llist_node_st *node;
	node=find__(ptr,key,cmp);
	if(node==&ptr->head)
	{
		return -1;
	}
	memcpy(data,node->data,ptr->size);
	node->next->prev=node->prev;
	node->prev->next=node->next;
	free(node);
	return 0;
}
void llist_destroy(LLIST *ptr)
{
	struct llist_node_st *cur,*save;
	for(cur=ptr->head.next;cur!=&ptr->head;cur=save)
	{
		save=cur->next;
		free(cur);
	}
	free(ptr);
}