#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "lista.h"
#include <string.h>
#include "error.h"

/**
    Calcula la suma de los operandos de la lista y lo devuelve
    @param operandos la lista de operandos
    @returns el resultado de la suma de los operandos
*/
int suma(lista_t* operandos){
    while(lista_cantidad(*operandos)>1){//mientras tenga mas de un operando, saco dos de la lista, los opero y los vuelvo a guardar en la lista
        int operando2 = lista_obtener(*operandos,0);
        int operando1 = lista_obtener(*operandos,1);
        lista_eliminar(*operandos,0);
        lista_eliminar(*operandos,0);
        lista_adjuntar(*operandos,(operando1+operando2));
    }
    int resultado;
    resultado = lista_obtener(*operandos,0);
    lista_eliminar(*operandos,0);
    return resultado;
}

/**
    Calcula la resta de los operandos de la lista y lo devuelve
    @param operandos la lista de operandos
    @returns el resultado de la resta de los operandos
*/
int resta(lista_t* operandos){
    int operando2 = lista_obtener(*operandos,0);
    int operando1 = lista_obtener(*operandos,1);
    int resultado;
    resultado = operando1 - operando2;
    lista_eliminar(*operandos,0);
    lista_eliminar(*operandos,0);
    return resultado;
}

/**
    Calcula la multiplicacion de los operandos de la lista y lo devuelve
    @param operandos la lista de operandos
    @returns el resultado de la multiplicacion de los operandos
*/
int mult(lista_t* operandos){
    while(lista_cantidad(*operandos)>1){//mientras tenga mas de un operando, saco dos de la lista, los opero y los vuelvo a guardar en la lista
        int operando2 = lista_obtener(*operandos,0);
        int operando1 = lista_obtener(*operandos,1);
        lista_eliminar(*operandos,0);
        lista_eliminar(*operandos,0);
        lista_adjuntar(*operandos,(operando1*operando2));
    }
    int resultado;
    resultado = lista_obtener(*operandos,0);
    lista_eliminar(*operandos,0);
    return resultado;
}

/**
    Calcula la division de los operandos de la lista y lo devuelve
    @param operandos la lista de operandos
    @returns el resultado de la division de los operandos
*/
int divi(lista_t* operandos){
    int operando2 = lista_obtener(*operandos,0);
    int operando1 = lista_obtener(*operandos,1);
    int resultado;
    resultado = operando1 / operando2;
    lista_eliminar(*operandos,0);
    lista_eliminar(*operandos,0);
    return resultado;
}

/**
    Imprime el texto de ayuda por pantalla
*/
void imprimir_ayuda(){
    printf("---------------------------------------------------\n");
    printf("|Proyecto N_1 Organizacion de Computadoras C2 2016|\n");
    printf("---------------------------------------------------\n");
    printf("Este programa calcula el resultado de una expresion matematica ingresada por el usuario en preorden\n");
    printf("Una vez ejecutado el programa, debera ingresar la expresion en preorden y bien parentizada\n");
    printf("Si la expresion no esta bien ingresada, el programa aborta con un valor de error de acuerdo a lo siguiente: \n");
    printf("2: Expresion mal formada, falta o exceso de parentesis\n");
    printf("5: Desmasiados operandos para el operador\n");
    printf("6: Insuficientes operandos para el operador\n");
    printf("7: Operando invalido\n");
    printf("8: Operador desconocido o invalido\n");
    printf("---------------------------------------------------\n");

}

/**
    Calcula el resultado de una expresion matematica ingresada por el usuario en notacion prefija y lo muestra por pantalla
*/
int main(int argc, char *argv[]){

    //Si el argumento es "h" se imprime el texto de ayuda y termina el programa
    if(argc > 1){
        int i;
        for(i = 1; i< argc; i++){
            if(strcmp(argv[i], "h")){
                printf("%s no es un argumento valido\n",argv[i]);
            }
            else{
                imprimir_ayuda();
                exit(EXITO);
            }
        }
    }

    char exp[50];
    printf("ingrese una expresion \n");
    scanf("%[^\n]",exp);

    //declaracion de variables y estructuras que vamos a utilizar
    int longitud;
    longitud=strlen(exp);
    pila_t mipila;
    mipila = pila_crear();
    lista_t milista;
    milista = lista_crear();
    int balance = 0;

    int i;
    for(i = 0; i< longitud; i++){//iteramos sobre toda la entrada

        if(exp[i] == ' ' || exp[i] == '\0'){//estos caracteres no me interesan
            continue;
        }

        if(exp[i] != ')'){//apilo hasta encontrar un ')'
            if(exp[i] == '('){//cuento los '(' para luego ver si estan balanceados
                balance++;
            }
            else{
                if(exp[i] <= '9' && exp[i] >= '0'){//si es un numero tengo que ver si tiene mas de un digito y luego lo apilo
                    int num;
                    num = atoi(&exp[i]);
                    int j = 0;
                    while(exp[i] <= '9' && exp[i] >= '0'){
                        i++;
                        j++;
                    }
                    i--;
                    char str[j+2];
                    sprintf(str,"%d",num);
                    apilar(&mipila,str);

                }
                else{
                    if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){//los operadores los apilo
                        char c = exp[i];
                        char str1[2] = {c, '\0'};
                        char str2[5] = "";
                        strcpy(str2,str1);
                        apilar(&mipila,str2);
                    }
                    else{//en cualquier otro caso, es un caracter invalido
                        exit(OPRD_INV);
                    }
                }
            }
        }
        else{//si encontre un ')'
            balance--;
            if(balance<0){//checkeo el balance de parentesis
                exit(EXP_MALF);
            }
            while((strcmp(tope(mipila),"+") && strcmp(tope(mipila),"-") && strcmp(tope(mipila),"*") && strcmp(tope(mipila),"/"))){//desapilo y guardo en la lista hasta encontrar un operador
                lista_adjuntar(milista,atoi(desapilar(&mipila)));
                if(pila_vacia(mipila)){
                    exit(EXP_MALF);
                }
            }
            if(lista_cantidad(milista)<2){
                exit(OPND_INSUF);
            }
            char operador;
            operador = desapilar(&mipila)[0];
            int res;
            res = 0;
            switch(operador){//llama a la funcion acorde al operador encontrado
                case '+':{
                    res = suma(&milista);
                    break;
                }
                case '-':{
                    if(lista_cantidad(milista) > 2){
                        exit(OPND_DEMAS);
                    }
                    res = resta(&milista);
                    break;
                }
                case '*':{
                    res = mult(&milista);
                    break;
                }
                case '/':{
                    if(lista_cantidad(milista) > 2){
                        exit(OPND_DEMAS);
                    }
                    res = divi(&milista);
                    break;
                }
            }
            char r[5];
            sprintf(r,"%d",res);//transformo el resultado de int a string para apilarlo
            apilar(&mipila,r);//apilo el resultado parcial
        }
    }
    if(balance){//vuelvo a checkear el balance por ultima vez
        exit(EXP_MALF);
    }
    printf("El resultado es: %s\n",desapilar(&mipila));
    lista_destruir(&milista);

    exit(EXITO);

}
