#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED



#endif // LISTA_H_INCLUDED
    /**
       Celda de una lista eficiente.
    */
    typedef struct celda celda_t;

    /**
        Estructura enlazada que representa una lista de enteros
    */
    typedef struct lista_eficiente *lista_t;

    /**
        Crea la lista vacia y la retorna.
        @returns la lista creada.
    */
    lista_t lista_crear();

    /**
        Inserta el elemento elem en la posicion pos de la lista.
        Si la posicion ya esta ocupada, sobreescribe el valor.
        Si la posicion es coincide con la cantidad de elementos, agrega el valor.
        @param lista lista en la que se va a insertar el elemento.
        @param elem elemento a insertar.
        @returns 1 si se procede exitosamente, 0 en caso contrario.
    */
    int lista_insertar(lista_t lista, unsigned int pos,int elem);

    /**
        Elimina el elemento en la posicion pos y reacomoda la lista.
        Si la posicion no es valida aborta con exit status LST_POS_INV.
        @param lista lista en la que se va a eliminar el elemento.
        @param pos posicion de la lista que sera eliminada.
        @returns 1 si se procede con exitosamente, 0 en caso contrario.
    */
    int lista_eliminar(lista_t lista, unsigned int pos);

    /**
        Retorna la cantidad de elementos en la lista.
        Si la lista no esta inicializada, el programa aborta con exit status LST_NO_INI.
        @param lista a la que se le consulta la cantidad de elementos.
        @returns la cantidad de elementos en la lista.
    */
    int lista_cantidad(lista_t lista);

    /**
        Retorna el elemento en la posicion pos de la lista.
        Si la posicion no es valida, aborta con exit status LST_POS_INV.
        @param lista lista a la que se le pide el elemento.
        @param pos posicion que contiene el elemento a obtener.
        @returns elemento en la posicion de la pos de la lista.
    */
    int lista_obtener(lista_t lista, unsigned int pos);

    /**
        Inserta el elemento elem en la ultima posicion de la lista.
        Si la lista no esta inicializada, aborta con exit status LST_NO_INI.
        @param lista lista donde adjuntar el elemento.
        @param elem elemento a adjuntar.
        @returns 1 si se procede exitosamente, 0 en caso contrario.
    */
    int lista_adjuntar(lista_t lista, int elem);

    /**
        Libera la memoria ocupada por lista y le asigna NULL.
        Si la lista no esta inicialisada, aborta con exit status LST_NO_INI.
        @param lista lista a destruir.
        @returns 1 en caso de exito.
    */
    int lista_destruir(lista_t* lista);
