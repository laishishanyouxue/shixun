#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "tree.h"
struct person
{
	int id;
	char name[20];
	char sex[10];
};
void print_person(void *data)
{
	struct person *p=data;
	printf("id=%d\tname=%s\tsex=%s\n",p->id,p->name,p->sex);
}

struct TREE{
  char data[10];
  int deep=0;
};
int main()
{
	// STACK *list;
	// list=stack_create(sizeof(struct person));
	// struct person person1={1,"zs","女"};
	// struct person person2={2,"ls","女"};
	// struct person person3={3,"ww","女"};
	// struct person person4={4,"zl","女"};
	// struct person person5={5,"sq","女"};
	// struct person person6={6,"qq","女"};
	// stack_push(list,&person1);
	// stack_push(list,&person2);
	// stack_push(list,&person3);
	// stack_push(list,&person4);
	// stack_push(list,&person5);
	// stack_push(list,&person6);
	// struct person p;
	// while(stack_pop(list,&p)!=-1)
	// {
	// 	print_person(&p);
	// }
	// stack_destroy(list);
  
  // printf("***********\n");
  
  // queue_enq(list,&person1);
	// queue_enq(list,&person2);
	// queue_enq(list,&person3);
	// queue_enq(list,&person4);
	// queue_enq(list,&person5);
	// queue_enq(list,&person6);
  
	// while(queue_deq(list,&p)!=-1)
	// {
	// 	print_person(&p);
	// }
	// queue_destroy(list);
	// list=NULL;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{

	}
}
