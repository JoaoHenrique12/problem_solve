#ifndef UTILS_H

struct lista {
  int value;
  struct lista* nxt;
};

typedef struct lista Lista;


void print_list(Lista* l);
void print_sum(Lista* l);

#endif // !UTILS_H
