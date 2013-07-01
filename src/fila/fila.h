#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elementofilaError
{
    char token[256];
    char msg[256];
    int  lineno;
    struct elementofilaError *prox;
}elementofilaError;

typedef struct filaError
{
    elementofilaError *inicio;
    elementofilaError *final;
} filaError;

void cria_fila_error(filaError *_fila);
int fila_vazia_error(filaError *_fila);
int push_error(filaError *_fila, char *_msg, int _lineno, char *_token);
int pop_error(filaError *_fila, struct elementofilaError **_elemento);
void pop_all_error(filaError *_fila);

#endif
