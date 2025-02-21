#if !defined(MYSTR_H)
#define MYSTR_H
typedef struct mystr{
  char *block;
  int sz;
  int capacity;
} mystr;


void create_string(mystr **p_p_s);

void set_char(mystr *p_s, int ind, char c);

void append_str(mystr *p_s, const char *src);

#endif

