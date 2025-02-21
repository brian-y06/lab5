#include "intlist.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void test_create_list_from_data() { 
  int data_arr[]  = {1,2,3,4,5};
  IntList *list;
  create_list_from_data(&list, data_arr, 5);

  assert(list->data[0] == 1);
  assert(list->data[1] == 2);
  assert(list->data[2] == 3);
  assert(list->data[3] == 4);
  assert(list->data[4] == 5);

  assert(list->size == 5);
  assert(list->capacity == 10);
}

void test_list_append() {
  int data_arr[]  = {1,2,3,4,5};
  IntList *list;
  create_list_from_data(&list, data_arr, 5);
  
  list_append(list, 6);
  assert(list->size == 6);
  assert(list->capacity == 10);
  assert(list->data[5] == 6);
}

void test_list_append_cap() {
  int data_arr[] = {1};
  IntList *list;
  create_list_from_data(&list, data_arr, 1);

  list_append(list, 2);
  assert(list->data[1] == 2);
  list->data = (int *) realloc(list->data, sizeof(int) * list->capacity);
  
  list_append(list, 3);

  assert(list->capacity == 6);
  assert(list->size == 3);
  assert(list->data[2] == 3);

  list_append(list, 4);
  assert(list->capacity == 6);
  assert(list->size == 4);
  assert(list->data[3] == 4);
}

void test_list_insert() {
  int data_arr[] = {1, 2, 3, 4, 5};
  IntList *list;
  create_list_from_data(&list, data_arr, 5);

  list_insert(list, 7, 2);

  assert(list->data[0] == 1);
  assert(list->data[1] == 2);
  assert(list->data[2] == 7);
  assert(list->data[3] == 3);
  assert(list->data[4] == 4);
  assert(list->data[5] == 5);
}

void test_list_delete() {
  int data_arr[] = {1, 2, 3, 4, 5};
  IntList *list;
  create_list_from_data(&list, data_arr, 5);

  list_delete(list, 2);
  assert(list->data[0] == 1);
  assert(list->data[1] == 2);
  assert(list->data[2] == 4);
  assert(list->data[3] == 5);
  assert(list->size == 4);
}

void test_list_destroy() {
  int data_arr[] = {1,2,3};
  IntList *list;
  
  create_list_from_data(&list, data_arr, 3);

  list_destroy(list);
}

void test_list_get() {
  int data_arr[] = {1, 2, 3};
  IntList *list;

  create_list_from_data(&list, data_arr, 3);

  assert(list_get(list,2) == 3);
}

int main() {
  test_create_list_from_data();
  test_list_append();
  test_list_append_cap();
  test_list_insert();
  test_list_delete();
  test_list_destroy();
  test_list_get();
}
