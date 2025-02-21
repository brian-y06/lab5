#include "intlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper Functions
void increase_list_cap(IntList *list) {
  list->capacity = (list->capacity + 1) * 2;
  list->data = (int *) realloc(list->data, sizeof(int) * list->capacity);
  if (list->data == NULL) {
    printf("ERROR: unable to increase list capacity");
    exit(1);
  } 
}

void print_list(IntList *list) {
  printf("------ Printing list ------\n");
  for (int i = 0; i < list->size; i++) {
    printf("List at %d = %d\n", i, list->data[i]);
  }
} 

// Checks if a index is valid for operations insert, delete, get
bool valid_index_std(IntList *list, int index) {
  if (index < 0 || index > list->size - 1) {
    return false;
  }
}

// Main Functions

// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
  *p_IntList = (IntList *)malloc(sizeof(IntList));

  (*p_IntList)->data = (int *) malloc(sizeof(int) * size);
  (*p_IntList)->size = size;
  (*p_IntList)->capacity = size * 2;
  memcpy((*p_IntList)->data, data_arr, sizeof(int) * size);
};


// Append new_elem to the end of list
void list_append(IntList *list, int new_elem) {
  if (list->capacity < list->size + 1) {
    increase_list_cap(list);
  }
  list->data[list->size] = new_elem;
  list->size += 1;
};

// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
// Function to insert new_elem at position index
void list_insert(IntList *list, int new_elem, int index) {
  if (!valid_index_std(list, index)) {
    printf("ERROR: Tried inserting at an invalid index.\n");
    exit(1);
  }
  
  // Ensure there is enough capacity for one more element.
  if (list->size >= list->capacity) {
      increase_list_cap(list);
  }
  // Calculate how many elements need to be shifted.
  int num_elements_after_index = list->size - index;
  // Shift elements to the right starting at index.
  memmove(&(list->data[index + 1]), &(list->data[index]), num_elements_after_index * sizeof(int));
  // Insert the new element.
  list->data[index] = new_elem;
  // Increment the size.
  list->size += 1;
}


// Delete the element at index index
void list_delete(IntList *list, int index) {
  if (!valid_index_std(list, index)) {
    printf("ERROR: Tried deleting at an invalid index.\n");
    exit(1);
  }
  int num_elements_after_index = list->size - index;

  memmove(list->data + index, list->data + index + 1, num_elements_after_index * sizeof(int));
  list->size -= 1;
};

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list) {
  free(list->data);
  free(list);
};

// Return the element at index index in list
int list_get(IntList *list, int index) {
  if (!valid_index_std(list, index)) {
    printf("ERROR: Tried getting at an invalid index.\n");
    exit(1);
  }
  return list->data[index];
};

