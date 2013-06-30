#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct elementofila
{
    char token[256];
    struct elementofila *prox;
}elementofila;

typedef struct fila
{
    elementofila *inicio;
    elementofila *final;
} fila;

void cria_fila(fila *_fila);
int fila_vazia(fila *_fila);
int push(fila *_fila, char *_token);
int pop(fila *_fila, struct elementofila **_elemento);
void pop_all(fila *_fila);
#endif
