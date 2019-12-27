#include "llist.h"
#ifndef MAIN_H
#define MAIN_H
extern  LLIST *classlist;
void print_student(void *data);
int id_cmp( void *key, void *record);
int name_cmp( void *key, void *record);
void create_class_list();
void add_class();
void travle_class();
void print_class(void *data);
void travle_student(LLIST *ptr);
void menu();
#endif