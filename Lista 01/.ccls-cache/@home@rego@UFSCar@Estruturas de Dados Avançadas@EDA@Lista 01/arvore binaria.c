#include <stdio.h>
#include <stdlib.h>
#include "arvore binaria.h"







int altura(link raiz) {
    // Convenção comum: árvore com 1 nó terá altura 0
    if (raiz == NULL) // Caso base: árvore vazia tem altura -1
        return -1;

    // Calcula recursivamente a altura da subárvore esquerda
    int hEsquerda = altura(raiz->esquerda); 
    // Calcula recursivamente a altura da subárvore direita
    int hDireita = altura(raiz->direita);

    // Retorna a maior altura entre as subárvores + 1 (nível da raiz)
    if (hEsquerda > hDireita) 
        return hEsquerda + 1; // Altura da subárvore esquerda maior
    else
        return hDireita + 1; // Altura da subárvore direita maior
}

link inserir(link raiz, int valor) {
    // Caso base: encontrou posição vazia e cria novo nó para a árvore
    if (raiz == NULL) {
        raiz = malloc(sizeof(struct node)); // Aloca memória
        raiz->chave = valor;                // Armazena o valor
        raiz->esquerda = NULL;                   // Inicializa filho esquerdo
        raiz->direita = NULL;                   // Inicializa filho direito
        return raiz;                        // Retorna o novo nó
    }

    // Estratégia de inserção:
    // escolhe a subárvore com menor (ou igual) altura
    // para tentar manter a árvore balanceada
    if (altura(raiz->esquerda) <= altura(raiz->direita))
        // Insere recursivamente na subárvore esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        // Insere recursivamente na subárvore direita
        raiz->direita = inserir(raiz->direita, valor);

    return raiz; // Retorna a raiz atualizada
}

void percursoPreOrdem(link raiz) {
     if (raiz != NULL) { // Verifica se a árvore é vazia
        printf("%i ", raiz->chave);  // Visita a raiz
        percursoPreOrdem(raiz->esquerda); // Percorre a subárvore esquerda
        percursoPreOrdem(raiz->direita); // Percorre a subárvore direita  
     }
}

void percursoInOrdem(link raiz) {
     if (raiz != NULL) { // Verifica se a árvore é vazia
        percursoInOrdem(raiz->esquerda); // Percorre a subárvore esquerda
        printf("%i ", raiz->chave); // Visita a raiz
        percursoInOrdem(raiz->direita); // Percorre a subárvore direita   
     }
}

void percursoPosOrdem(link raiz) {
     if (raiz != NULL) { // Verifica se a árvore é vazia
        percursoPosOrdem(raiz->esquerda); // Percorre a subárvore esquerda
        percursoPosOrdem(raiz->direita); // Percorre a subárvore direita
        printf("%i ", raiz->chave);  // Visita a raiz
     }
}

void imprimirPreOrdem(link raiz) {
     printf("(");
     if (raiz != NULL) {
        printf("%i ", raiz->chave);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);    
     }
     printf(")");
}

void imprimirInOrdem(link p, int b) {
     int i;
     if (p == NULL) {
        for (i = 0; i < b; i++) printf("-----");
        printf("NULL\n");
        return;
     }
     imprimirInOrdem(p->direita, b + 1);
     for (i = 0; i < b; i++) printf("-----");
     printf("%i\n", p->chave);
     imprimirInOrdem(p->esquerda, b + 1);
}
