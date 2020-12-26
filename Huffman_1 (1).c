/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
*/
#include "ARJA_2020640024.h"
char frase_aux[100];

int main (){

    Lista * listaAux = NULL;
    Arbol * arbolAux = NULL;
    int aux_while=0;
    printf("Introduzca su frase:\n");
    gets(frase_aux);
    fflush(stdin);

    while(frase_aux[aux_while]!=NULL){
            if(frase_aux[aux_while]==' '){
                frase_aux[aux_while]='_';
            }else{
                frase_aux[aux_while] = tolower(frase_aux[aux_while]);
            }
        aux_while++;
    }
printf("\nFrase:%s\n",frase_aux);
printf("\nLista de frecuencia desordenada\n");
listaAux = generarListaFrecuencia(frase_aux);
printf("\nLista de frecuencia ordenada\n");
listaAux=ordenarLista(listaAux);

printf("\n\n\n");
verLista(listaAux);

printf("\n\nCreando arbol de frecuencia\n");
crearArboldeFrecuencia(listaAux,listaAux,&arbolAux);
printf("\nMonstrando el arbol en postorden\n");

postorden(arbolAux,arbolAux,2);






return 0;}
