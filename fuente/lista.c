    #include <stdio.h>
    #include <stdlib.h>
    #include "lista.h"
    #include "error.h"

    /**
       Celda de una lista eficiente.
    */
    struct celda{
        int elementos[4];
        struct celda* proxima_celda;
    };


    /**
        Estructura enlazada que representa una lista de enteros
    */
    struct lista_eficiente{
        unsigned int cantidad_elementos;
        celda_t* primera_celda;
    };

    //crea la estructura, asignando el lugar en memoria y devolviendo el puntero
    lista_t lista_crear(){
    lista_t lista;
    lista=(struct lista_eficiente*) malloc(sizeof(struct lista_eficiente));
    lista->cantidad_elementos=0;

    return lista;

    }

    //inserta el elemento elem en la posicion pos de la lista, devuelve 0 si no se pudo realizar la operacion, 1 en caso contrario
    int lista_insertar(lista_t lista,unsigned int pos,int elem){

        if(pos > lista->cantidad_elementos){//no puedo saltear posiciones
            return 0;
        }
        if(lista->cantidad_elementos == 0){//si la lista esta vacia, tengo que crear la primer celda
            lista->primera_celda = malloc(sizeof(struct celda));
        }
        int i;
        int celda = pos/4;
        int indice = pos%4;
        celda_t* actual = lista->primera_celda;
        for(i = 0; i < celda; i++){//busco la celda donde voy a insertar
            if(actual->proxima_celda == NULL){//si lo necesito, creo una celda mas
                actual->proxima_celda = (struct celda*)malloc(sizeof(struct celda));
                actual->proxima_celda->proxima_celda = NULL;
            }
        actual = actual->proxima_celda;
        }
        actual->elementos[indice] = elem;
        if(lista->cantidad_elementos == pos){//si no sobreescribi una posicion, aumento la cantidad de elementos
            lista->cantidad_elementos = lista->cantidad_elementos +1;
        }


        return 1;
    }

    //devuelve la cantidad de elementos en la lista, error si la lista no esta inicializada
    int lista_cantidad(lista_t lista){
        if(lista==NULL){
            exit (LST_NO_INI);
        }

        return lista->cantidad_elementos;
    }

    //devuelve el elemento en la posicion pos
    int lista_obtener(lista_t lista, unsigned int pos){
        if(lista == NULL || pos >= lista->cantidad_elementos){//error si la posicion es invalida
            exit(LST_POS_INV);
        }
        int i;
        int celda = pos/4;
        int indice = pos%4;
        celda_t* actual = lista->primera_celda;
        for(i = 0; i < celda; i++){//busco la celda
            actual = actual->proxima_celda;
        }
        return actual->elementos[indice];
    }

    //inserto elem en el final de la lista
    int lista_adjuntar(lista_t lista, int elem){
        return lista_insertar(lista,lista->cantidad_elementos,elem);
    }

    //libera la memoria asignada a la lista, error si la lista no esta inicializada
    int lista_destruir(lista_t* lista){
        if(lista == NULL){
        exit(LST_NO_INI);
        }
        free(*lista);
        return 1;

    }

    //elimina el elemento de la lista en la posicion pos
    int lista_eliminar(lista_t lista, unsigned int pos){

        if(lista == NULL || pos >= lista->cantidad_elementos){//error si la posicion es invalida
            exit(LST_POS_INV);
        }
        if(lista->cantidad_elementos == 1){//si solo tengo un elemento libero la celda
            lista->primera_celda->elementos[0] = 0;
            free(lista->primera_celda);
            lista->primera_celda = NULL;
        }
        else{
            int i;
            for(i = pos; i < lista->cantidad_elementos -1; i++){//arrastro todos los elementos a partir de pos una posicion hacia atras
                lista_insertar(lista,i,lista_obtener(lista,i+1));
            }
        }
        lista->cantidad_elementos--;

        return 1;
    }
