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

item l, *tmp, *records = NULL;

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

struct item *hash_consultar(char *nome, char *escopo)
{
    item *p = malloc(sizeof(*p));;
    memset(&l, 0, sizeof(item));
    l.key.nome = nome;
    l.key.escopo = escopo;
    HASH_FIND(hh, records, &l.key, sizeof(item_key), p);

    if (p) 
    {	
	//printf("encontrado: %s %s %s\n", p->key.nome, p->key.escopo, p->tipo);
	return (p);
    } 
}




int main(int argc, char *argv[]) {
    item *item_busca;    
    hash_inserir("nome1", "escopo1", "tipo1");    
    item_busca = hash_consultar("nome1", "escopo1");
    printf("encontrado: %s %s %s\n", item_busca->key.nome, item_busca->key.escopo, item_busca->tipo);
    return 0;
}
