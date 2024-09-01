#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector {
  int *data;
  size_t size;
};

typedef struct {
  char *str;
  size_t len;
} String;

void init_vector(struct Vector *v, size_t size) {
  v->data = malloc(size * sizeof(int));
  v->size = size;
}
void free_vector(struct Vector *v) {
  free(v->data);
  v->data = NULL;
  v->size = 0;
}

String *create_string(const char *str) {
  String *s = malloc(sizeof(String));
  s->len = strlen(str); // no of bytes before null terminatorw
  s->str = malloc(s->len + 1);
  strcpy(s->str, str);
  return s;
}

void init_string(String *s, const char *str) {
  s->len = strlen(str); // strlen does not include the null terminator
  s->str = malloc(s->len + 1);
  strcpy(s->str, str); // strcpy(dest, src) does not check for buffer overflow
}

void free_string(String *s) {
  free(s->str);
  s->str = NULL;
  s->len = 0;
}

int main(int argc, char *argv[]) {
  struct Vector v;
  init_vector(&v, 10);

  for (int i = 0; i < v.size; i++) {
    v.data[i] = i;
    printf("v.data[%i]: %i\n", i, v.data[i]);
  }

  String *s = create_string("HelloWorld");

  printf("String: %s\n", s->str);

  free_vector(&v);
  free_string(s);
  free(s);
  return 0;
}
