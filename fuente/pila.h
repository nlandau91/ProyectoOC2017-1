#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED



#endif // PILA_H_INCLUDED

/**
    Estructura que representa una pila de strings.
*/
typedef struct pila *pila_t;

/**
    Crea una pila vacia y la retorna.
    @return la pila creada.
*/
pila_t pila_crear();

/**
    Retorna el string que se encuentra en el tope de la pila.
    Si la pila se ecuentra vacia, aborta su ejecucion con exit status PIL_VACIA.
    @param pila la pila a la que se le consulta el tope.
    @returns el string en el tope de la pila.
*/
char* tope(pila_t pila);

/**
    Elimina el string que se encuentra en el tope de la pila y lo retorna.
    Si la pila se encuentra vacia, aborta su ejecucion con exit status PIL_VACIA.
    @param pila la pila a la que debe realizarse el desapilar.
    @returns el string que se encuentra en el tope.
*/
char* desapilar(pila_t* pila);

/**
    Inserta el string str en el tope de la pila.
    Si la pila no se encuentra inicializada, finaliza la ejecucion con exit status PILA_NO_INI.
    @param pila la pila en la que se va a apilar str.
    @param str el string que va a ser apilado.
    @returns 1 si la insercion fue exitosa.
*/
int apilar(pila_t* pila,char* str);

/**
    Consulta si la pila esta vacia.
    Si la pila no se encuentra inicializada, finaliza la ejecucion con exit status PIL_NO_INI.
    @param pila la pila a la que debe realizarse la consulta.
    @returns 1 si la pila esta vacia, 0 en caso contrario.
*/
int pila_vacia(pila_t pila);
