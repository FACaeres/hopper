#include "var.h"

void cria_fila_var(fila_var *_fila_var)
{
    _fila_var->inicio = _fila_var->final = NULL;
}

int fila_vazia_var(fila_var *_fila_var)
{
    if(_fila_var->inicio == NULL && _fila_var->final == NULL)
        return 1;
    else
        return 0;
}

int push_var(fila_var *_fila_var, char *_token_var)
{
    elementofila_var *novoElemento_var;
    novoElemento_var = (elementofila_var*) malloc(sizeof(elementofila_var));
    if (novoElemento_var == NULL)
        return 0;
    strcpy(novoElemento_var->token,_token_var);
    novoElemento_var->prox = NULL;
    if (fila_vazia_var(_fila_var))
        _fila_var->inicio = novoElemento_var;
    else
        (_fila_var->final)->prox = novoElemento_var;
    _fila_var->final = novoElemento_var;
   return 1;
}

int pop_var(fila_var *_fila_var, struct elementofila_var **_elemento_var)
{
    if (fila_vazia_var(_fila_var))
        return 0;
    *_elemento_var = (_fila_var->inicio);
    if (_fila_var->inicio == _fila_var->final)
      _fila_var->final = NULL;
    _fila_var->inicio = (_fila_var->inicio)->prox;
    return 1;
}

void pop_all_var(fila_var *_fila_var)
{
    while(!fila_vazia_var(_fila_var))
  {
        elementofila_var *ret;
        pop_var(_fila_var, &ret);
        printf("Expressao invalida: [%s].\n", ret->token);
        free(ret);
  }
}
