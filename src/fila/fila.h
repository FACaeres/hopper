#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct elementofila
{
    int lineNo;
    char* token;
    struct elementofila *prox;
}elementofila;

typedef struct fila
{
    elementofila *inicio;
    elementofila *final;
} fila;

void cria_fila(fila *_fila);
int fila_vazia(fila *_fila);
int push(fila *_fila, int _lineNo, char *_token);
int pop(fila *_fila, struct elementofila **_elemento);
void pop_all(fila *_fila);
#endif
