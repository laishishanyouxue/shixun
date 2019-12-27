#ifndef BANK_H
#define BANK_H
typedef struct bank{
  struct bank *l, *r;
  char data[0];
}bank;
typedef struct BANKLIST{
  int size;
  bank head;
}BANKLIST;

BANKLIST *bank_create(int size);
int bank_insert(BANKLIST *ptr,const void *data,int mode);
void bank_travle(BANKLIST *ptr,void (*op)(void *));
void * bank_find(BANKLIST *ptr, void *key,int (*cmp)( void *, void *));
void bank_delete(BANKLIST *ptr,void *key,int (*cmp)( void *, void *));
int bank_fetch(BANKLIST *ptr,void *data,void *key,int (*cmp)( void *, void *));
void bank_destroy(BANKLIST *ptr);
#endif