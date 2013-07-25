#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"


typedef struct 
{
  char nome[50];
  char escopo[50];
} item_key;

typedef struct 
{
    item_key key;
    char tipo[50];
    UT_hash_handle hh;
} item;

item l, *tmp, *records = NULL;

void hash_inserir(char *nome, char *escopo, char *tipo)
{
    item *r;
    r = (item*)malloc( sizeof(item) );
    memset(r, 0, sizeof(item));
    strcpy(r->key.nome, nome);
    strcpy(r->key.escopo, escopo);
    strcpy(r->tipo, tipo);
//    printf("adicionado: %s %s %s\n",r->key.nome, r->key.escopo, r->tipo);    
    HASH_ADD(hh, records, key, sizeof(item_key), r); 
}

int hash_consultar(char *nome, char *escopo)
{  
    item *p = malloc(sizeof(*p));;
    memset(&l, 0, sizeof(item));
    strcpy(l.key.nome, nome);
    strcpy(l.key.escopo, escopo);
    HASH_FIND(hh, records, &l.key, sizeof(item_key), p);
        
    if (p) 
    {	
//	    printf("encontrado: %s %s %s\n",p->key.nome, p->key.escopo, p->tipo);
		return 1;
    }
    else
    {
  // 	    printf("não encontrado encontrado: %s %s\n",nome, escopo);
    	return 0;
    }
}


