#include <stdio.h>
#include <stdlib.h>
#include "arvore binaria.h"
#include "fila.h"







void inicializarFila(Fila *f) {
    f->proximo = 0;
    f->anterior = 0;
}

void colocar_na_fila(Fila *f, link no) {
  f->nos[f->anterior] = no;
  f->anterior++;
}

link tirar_da_fila(Fila *f) {
  link no_removido = f->nos[f->proximo];
  f->proximo++;

  return no_removido;
}

int fila_vazia(Fila *f) {
  return (f->proximo == f->anterior);
}
