#include "fila.h"

void cria_fila_error(filaError *_fila)
{
    _fila->inicio = _fila->final = NULL;
}

int fila_vazia_error(filaError *_fila)
{
    if(_fila->inicio == NULL && _fila->final == NULL)
        return 1;
    else
        return 0;
}

int push_error(filaError *_fila, char *_msg, int _lineno, char *_token)
{
    //printf("DEBUG:%d - %s - %s\n", _lineno, _msg, _token);
    elementofilaError *novoElemento;
    novoElemento = (elementofilaError*) malloc(sizeof(elementofilaError));
    if (novoElemento == NULL)
        return 0;
    strcpy(novoElemento->token,_token);
    strcpy(novoElemento->msg,_msg);
    novoElemento->lineno = _lineno;

    novoElemento->prox = NULL;
    if (fila_vazia_error(_fila))
        _fila->inicio = novoElemento;
    else
        (_fila->final)->prox = novoElemento;
    _fila->final = novoElemento;
   return 1;
}

int pop_error(filaError *_fila, struct elementofilaError **_elemento)
{
    if (fila_vazia_error(_fila))
        return 0;
    *_elemento = (_fila->inicio);
    if (_fila->inicio == _fila->final)
      _fila->final = NULL;
    _fila->inicio = (_fila->inicio)->prox;
    return 1;
}

void pop_all_error(filaError *_fila)
{
    while(!fila_vazia_error(_fila))
  {
        elementofilaError *ret;
        pop_error(_fila, &ret);
        printf("**ERRO-Linha: %d -%s %s\n",ret->lineno,ret->msg, ret->token);
        free(ret);
  }
}
