/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
*/
#include "ARJA_2020640024.h"
char frase_aux[100];

int main (){

    Lista * listaAux = NULL;
    Arbol * arbolAux = NULL;
    Lista * listasin = NULL;
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

printf("ESTA ES LA LISTA ORIGINAL\n\n\n");
verLista(listaAux);

printf("\n\nCreando arbol de frecuencia\n");
crearArboldeFrecuencia(listaAux,listaAux,&arbolAux);
printf("\nMonstrando el arbol en postorden\n");
printf("\n\n\n ANTES DE ESTAR EN ARBOL\n");

postorden(arbolAux,arbolAux,2);

printf("\n\n\n");
listasin = postordenAgregar(arbolAux,listasin);

verLista(listasin);
char binarioString [200] = {" "};
Lista *listaAyuda = listasin;
int j;
for(i = 0; i< strlen(frase_aux);i++){
	for(j = 0; j < contarElementosLista(listasin); j++){
		
		if(frase_aux[i] == listaAyuda -> caracter){
			strcat(binarioString, listaAyuda -> codigo);
			break;
		}
		
		listaAyuda = listaAyuda -> sig;
	}
	
	listaAyuda = listasin;
}

printf("\n\nEL CODIGO ES: %s", binarioString);




return 0;}
