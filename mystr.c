#include "mystr.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void create_string(mystr **p_p_s) {
  *p_p_s = (mystr *) malloc(sizeof(mystr));
  if(*p_p_s == NULL) {
    prtinf("ERROR: failed to create mystr");
    exit(1);
  }
  (*p_p_s)->capacity = 100;
  (*p_p_s)->block = (char *) malloc((*p_p_s->capacity) * sizeof(char));
  (*p_p_s)->block[0] = '\0';


  (*p_p_s)->sz = 0;

};

void set_char(mystr *p_s, int ind, char c) {
  if (ind >= p_s->sz || ind < 0) {
    printf("ERROR: index %d out of bounds\n", ind);
    exit(1);
  }
  (p_s->block)[ind] = c;
};

void append_str(mystr *p_s, const char *src) {
  if(ps->capacity < p_s->sz + strlen(src)) {
    int new_capacity = (ps->capacity + strlen(str) + 1) * 2;
    p_s->block = (char *) realloc(new_capacity * sizeof(char));
    
    if(p_s->block == NULL) {
      printf("ERROR: string too large\n");
      exit(1);
    }
    p_s->capacity = new_capacity;
    p_s->sz = strlen(rc) + p_s->sz;
  }
  strcat(p_s->block, src);
};


