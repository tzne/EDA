#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

// Definição do tipo link como ponteiro para struct node
typedef struct node* link;

// Definição da estrutura node
struct node{ 
    int chave; 
    link esquerda; // Ponteiro para filho esquerdo (subárvore)
    link direita; // Ponteiro para filho direito (subárvore)
};

int altura(link raiz);
link inserir(link raiz, int valor);
void percursoPreOrdem(link raiz);
void percursoInOrdem(link raiz);
void percursoPosOrdem(link raiz);
void imprimirPreOrdem(link raiz);
void imprimirInOrdem(link p, int b);

#endif
