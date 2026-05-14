#ifndef FILA_H
#define FILA_H

typedef struct {
  link nos[100];
  int proximo;
  int anterior;
} Fila;

typedef struct {
  link nos[100];
  int proximo;
  int anterior;
} Fila;

void inicializarFila(Fila *f);
void colocar_na_fila(Fila *f, link no);
link tirar_da_fila(Fila *f);
int fila_vazia(Fila *f);


#endif
