#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"
#include "student.h"
struct student
{
	int id;
	char name[40];
	int math;
};
struct class
{
	int class_id;
	char class_name[40];
	LLIST *studentlist;
};
LLIST *classlist=NULL;
void print_student(void *data)
{
	struct student *p=data;
	printf("id=%d\tname=%s\t,math=%d\n",p->id,p->name,p->math);
}
int id_cmp( void *key, void *record)
{
	int *id=key;
	struct student *pstu=record;
	return *id-pstu->id;
}
int name_cmp( void *key, void *record)
{
	char *name=key;
	struct student *pstu=record;
	return strcmp(name,pstu->name);
}
void create_class_list()
{
	classlist=llist_create(sizeof(struct class));
}
void add_class()
{
	struct class c;
	c.studentlist=llist_create(sizeof(struct student));
	printf("学生id:");
	scanf("%d",&c.class_id);
	printf("学生name:");
	scanf("%s",c.class_name);
	while(1)
	{
		struct student stu;
		int id;
		printf("瀛︾敓id:(杈撳叆-1琛ㄧず杈撳叆缁撴潫)");
		scanf("%d",&id);
		if(id==-1)
		{
			break;
		}
		stu.id=id;
		printf("瀛︾敓濮撳悕:");
		scanf("%s",stu.name);
		printf("瀛︾敓鎴愮哗:");
		scanf("%d",&stu.math);
		llist_insert(c.studentlist,&stu,LLIST_BACKWARD);
	}
	llist_insert(classlist,&c,LLIST_BACKWARD);
}
void travle_class()
{
	llist_travle(classlist,print_class);
}
void print_class(void *data)
{
	struct class *p_class=data;
	printf("鐝骇id:%d\n",p_class->class_id);
	printf("鐝骇name:%s\n",p_class->class_name);
	 travle_student(p_class->studentlist);
}
void travle_student(LLIST *ptr)
{
	llist_travle(ptr,print_student);
}
void menu()
{
	int x=0;
	while(1)
	{
		printf("学生管理系统\n");
		printf("1銆佹柊澧炵彮绾n");
		printf("2銆佺幇瀹炲叏閮ㄧ彮绾т俊鎭痋n");
		printf("3銆侀€€鍑篭n");
		scanf("%d",&x);
		if(x==1)
		{
			add_class();
		}
		else if(x==2)
		{
			travle_class();
		}
		else if(x==3)
		{
			break;
		}
		else
		{
			printf("杈撳叆閿欒\n");
		}
	}
}
int main()
{
	create_class_list();
	menu();	
	return 0;
}
