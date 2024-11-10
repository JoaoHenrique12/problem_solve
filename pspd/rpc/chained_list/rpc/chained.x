#define VERSION_NUMBER 1

struct lista {
  int value;
  struct lista* nxt;
};

typedef struct lista Lista;

program SOMA_LISTA {
  version SOMA_LISTA_VERSION {
    int SOMAL(Lista) = 1;
  } = VERSION_NUMBER;
} = 0x13;
