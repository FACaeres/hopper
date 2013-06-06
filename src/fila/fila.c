#include "fila.h"

void cria_fila(fila *_fila)
{
    _fila->inicio = _fila->final = NULL;
}

int fila_vazia(fila *_fila)
{
    if(_fila->inicio == NULL && _fila->final == NULL)
        return 1;
    else
        return 0;
}

int push(fila *_fila, int _lineNo, char *_token)
{
    elementofila *novoElemento;
    novoElemento = (elementofila*) malloc(sizeof(elementofila));
    if (novoElemento == NULL)
        return 0;
    novoElemento->lineNo = _lineNo;
    novoElemento->token = _token;
    novoElemento->prox = NULL;
    if (fila_vazia(_fila))
        _fila->inicio = novoElemento;
    else
        (_fila->final)->prox = novoElemento;
    _fila->final = novoElemento;
   return 1;
}

int pop(fila *_fila, struct elementofila **_elemento)
{
    if (fila_vazia(_fila))
        return 0;
    *_elemento = (_fila->inicio);
    if (_fila->inicio == _fila->final)
      _fila->final = NULL;
    _fila->inicio = (_fila->inicio)->prox;
    return 1;
}

void pop_all(fila *_fila)
{
    while(!fila_vazia(_fila))
  {
        elementofila *ret;
        pop(_fila, &ret);
        printf("Expressao invalida: [%s], linha [%d].\n", ret->token ,ret->lineNo);
        free(ret);
  }

}
