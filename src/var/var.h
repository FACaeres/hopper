#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elementofila_var
{
    char token[256];
    struct elementofila_var *prox;
}elementofila_var;

typedef struct fila_var
{
    elementofila_var *inicio;
    elementofila_var *final;
} fila_var;

void cria_fila_var(fila_var *_fila_var);
int fila_vazia_var(fila_var *_fila_var);
int push_var(fila_var *_fila_var, char *_token_var);
int pop_var(fila_var *_fila_var, struct elementofila_var **_elemento_var);
void pop_all_var(fila_var *_fila);
#endif
