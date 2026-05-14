#include <stdio.h>
#include <stdlib.h>
#include "arvore binaria.h"
#include "fila.h"






void percurso_nivel(link raiz) {
  if (raiz == NULL) return;

  Fila fila;
  inicializarFila(&fila);

  colocar_na_fila(&fila, raiz);

  while (!fila_vazia(&fila)) {
    link no_processamento = tirar_da_fila(&fila);
    printf("%d ", no_processamento->chave);

    if (no_processamento->esquerda != NULL) colocar_na_fila(&fila, no_processamento->esquerda);
    if (no_processamento->direita != NULL) colocar_na_fila(&fila, no_processamento->direita);

  }

  return;
}

int main(void) {
    link Arvore = NULL; // Inicializar a Árvore Binária (AB) vazia
 
    Arvore = inserir(Arvore, 50); // Inserir 50 na AB
    Arvore = inserir(Arvore, 40); // Inserir 40 na AB
    Arvore = inserir(Arvore, 60); // Inserir 60 na AB
    Arvore = inserir(Arvore, 35); // Inserir 35 na AB
    Arvore = inserir(Arvore, 45); // Inserir 45 na AB
    Arvore = inserir(Arvore, 55); // Inserir 55 na AB
    Arvore = inserir(Arvore, 65); // Inserir 65 na AB

    percurso_nivel(Arvore);

    return 0;
}
