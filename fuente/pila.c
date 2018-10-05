#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include <string.h>

/**
    Estructura que representa una pila de strings.
*/
typedef struct pila{
    char* elemento;
    struct pila* proximo_elemento;
}*pila_t;

//asigna el lugar en memoria y devuelve el puntero
pila_t pila_crear(){
    pila_t pila;
    pila=(struct pila*) malloc(sizeof(struct pila));
    pila->elemento=NULL;
    return pila;
}

//devuelve el string del tope de la pila, error si la pila esta vacia
char* tope(pila_t pila){
    if(pila->elemento==NULL)
        exit(PIL_VACIA);
    else
        return pila->elemento;
}

//desapila el string del tope y lo devuelve, error si la pila esta vacia
char* desapilar(pila_t* pila){
    char* elem = NULL;
    if((*pila)->elemento==NULL)
        exit(PIL_VACIA);
    else{
        elem=(*pila)->elemento;
        pila_t act=*pila;
        *pila=(*pila)->proximo_elemento;
        free(act);
    }
    return elem;
}

//agrega el string str al tope de la pila, error si la pila no esta inicializada, devuelve 1 en caso de exito
int apilar(pila_t* pila,char* str){
    if(pila==NULL)
        exit(PIL_NO_INI);
    else{
        pila_t nuevo = pila_crear();
        nuevo->elemento = strdup(str);
        nuevo->proximo_elemento = *pila;
        *pila = nuevo;
        return 1;

    }
}

//devuelve 1 si la pila esta vacia, 0 si no lo esta. Error si no esta inicializada
int pila_vacia(pila_t pila){
    if(pila == NULL){
    exit(PIL_NO_INI);
    }
    return pila->elemento == NULL;
}


