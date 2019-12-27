#ifndef TREE_H
#define TREE_H

typedef struct node
{
  struct node *lson, *rson, *father;
  char data[0];
}node;
typedef struct tree{
  int size;
  
}
void ll(node *);
void lr(node *);
void rr(node *);
void rl(node *);
int get_deep(node *);
void newdeep(node *);
node *create(node *, void *);
void tree_find(ndoe *, void *);
#endif