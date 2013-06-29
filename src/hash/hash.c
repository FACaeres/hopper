#include <stdlib.h>
#include <stdio.h>
#include "uthash.h"

typedef struct {
  char *nome;
  char *escopo;
} item_key;

typedef struct {
    item_key key;
    char *tipo;
    UT_hash_handle hh;
} item;

item l, *p,  *tmp, *records = NULL;

void hash_inserir(char *nome, char *escopo, char *tipo)
{
    item *r;
    r = (item*)malloc( sizeof(item) );
    memset(r, 0, sizeof(item));
    r->key.nome = nome;
    r->key.escopo = escopo;
    r->tipo = tipo;
    HASH_ADD(hh, records, key, sizeof(item_key), r); 
}

int hash_consultar(char *nome, char *escopo)
{
	
    memset(&l, 0, sizeof(item));
    l.key.nome = nome;
    l.key.escopo = escopo;
    HASH_FIND(hh, records, &l.key, sizeof(item_key), p);
    
    if (p) 
    {	
	printf("encontrado: %s %s %s\n", p->key.nome, p->key.escopo, p->tipo);
	return 1;
    }
    else
    {
    	return -1;
    }
}
