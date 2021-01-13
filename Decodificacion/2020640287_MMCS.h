#ifndef _2020640287_MMCS_h
#define _2020640287_MMCS_h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _NodoL{
    char caracter;
    int frecuencia;
    char codigo[8];
    int ocupado;
    struct _NodoL *sig;
    struct _NodoL *anterior;
    struct _NodoL *izquierda;
	struct _NodoL *derecha;
}Lista;

Lista * crearLista(char caracter, int frecuencia, char binario[8]){
    Lista *nuevo;
	nuevo = (Lista *) malloc (sizeof(Lista));
	nuevo -> frecuencia = frecuencia;
	nuevo -> caracter = caracter;
	strcpy(nuevo -> codigo, binario);

	nuevo -> sig = NULL;
	nuevo -> anterior = NULL;
	nuevo -> izquierda = NULL;
	nuevo -> derecha = NULL;
	nuevo -> ocupado = 0;
	return nuevo;
 }

 Lista * crearListaBi(char caracter, int frecuencia, char binario [8]){
   Lista *nuevo;
	nuevo = (Lista *) malloc (sizeof(Lista));
	nuevo -> frecuencia = frecuencia;
	nuevo -> caracter = caracter;
	strcpy(nuevo -> codigo, binario);
	nuevo -> sig = NULL;
	nuevo -> anterior = NULL;
	nuevo -> izquierda = NULL;
	nuevo -> derecha = NULL;
	nuevo -> ocupado = 0;
	return nuevo;
 }


    int contarElementosLista(Lista *inicio){
    int total = 0;
    if(inicio == NULL){
        total = 0;
     }else{
        while(inicio != NULL){
            total++;
            inicio = inicio ->sig;
        }
     }
    return total;
 }

Lista * insertarInicio(char caracter, int frecuencia, Lista *inicio, char binario[8]){
    Lista * nuevo;
    nuevo = crearLista(caracter,frecuencia,binario);
    if(inicio != NULL){
        nuevo->sig = inicio;
        inicio->anterior = nuevo;
    }
    return nuevo;
 }

 Lista * insertarInicioBi(char caracter, int frecuencia, Lista *inicio, char binario[8]){
    Lista * nuevo;
    nuevo = crearListaBi(caracter,frecuencia,binario);
    if(inicio != NULL){
        nuevo->sig = inicio;
        inicio->anterior = nuevo;
    }
    return nuevo;
 }


 Lista * insertarFinal(char caracter, int frecuencia, Lista *inicio,char binario [8]){
   	Lista *nuevo;
	Lista *aux;
	nuevo = crearLista(caracter,frecuencia,binario);
	if(inicio == NULL){
		inicio= nuevo;
	}else{
		aux = inicio;
		while(aux->sig != NULL){
			aux= aux->sig;
		}
    nuevo ->anterior = aux;
	aux-> sig= nuevo;
	}
    return inicio;
 }

 Lista * insertarMedio(char caracter,  int frecuencia, int posicion, Lista *inicio, char binario [8]){
    Lista *aux = NULL;
    Lista *nuevo = NULL;
    nuevo = crearLista(caracter,frecuencia,binario);
    int x = 0;
    int tamanioL = 0;
    tamanioL = contarElementosLista(inicio);
    if(posicion >= 1 && posicion <= tamanioL){
        if(posicion == 1){
            inicio = insertarInicio(caracter,frecuencia,inicio,binario);
        }else{
            aux = inicio;
            for(x = 1; x<posicion-1;x++){
                aux = aux ->sig;
            }
            nuevo ->sig = aux ->sig;
            aux ->sig = nuevo;
            nuevo ->anterior = aux;
            nuevo ->sig ->anterior = nuevo;
        }
    }else{
        printf("Posicion invalida");
    }
    return inicio;
 }

 Lista*  borrarInicio(Lista * inicio){
    Lista * aux;
	aux=inicio;
	if(inicio !=NULL){
		inicio=inicio->sig;
		inicio ->anterior = NULL;
		free(aux);
	}
    return inicio;
 }

  Lista * popFinal(Lista *inicio){
	Lista *aux;
	Lista *fin;
	int a;
	if(inicio == NULL){
		printf("La Lista esta vacia");
	}else{
		aux = inicio;
		for( a = 1; a < contarElementosLista(inicio)-1;a++){
            aux = aux ->sig;
		}
		fin = aux->sig;
		aux ->sig = NULL;
		free(fin);
	}
    return inicio;
 }

Lista * popInter(Lista *inicio,int posicion){
    Lista *aux = inicio;
    Lista *fin = NULL;
    int i = 0;
    int longitudLista = contarElementosLista(inicio);
    if(posicion >= 1 && posicion <= longitudLista){
        if(posicion == 1){
            inicio = borrarInicio(inicio);
        }else if(posicion == contarElementosLista(inicio)){
            inicio = popFinal(inicio);
        }else{
            for(i = 1; i<posicion-1;i++){
                aux = aux ->sig;
            }
            fin = aux->sig;
            aux ->sig = fin ->sig;
            free(fin);
        }
    }else{
        printf("Posicion no valida");
    }
    return inicio;
 }

Lista * quitarEspeciales(Lista * raiz, Lista * lista){

	if(raiz!=NULL){

		lista = quitarEspeciales(raiz->izquierda,lista);
		lista = quitarEspeciales(raiz->derecha,lista);
		if(raiz -> caracter != '*')
		lista = insertarInicioBi(raiz->caracter,raiz->frecuencia, lista, raiz -> codigo);
	}

	return lista;
}

void verLista(Lista *inicio){
     if(inicio == NULL){
        printf("La lista esta vacia");
     }else{
        while(inicio != NULL){
            printf("\nCaracter: %c\t Frecuencia: %d Codigo: %s",inicio->caracter,inicio->frecuencia, inicio ->codigo);
            inicio = inicio ->sig;
        }
     }
 }

Lista * generarListaDeArbol(Lista * listaLeida){
	Lista * nodoEspecial;
	Lista * iterador = listaLeida;
	int numOcupados = 0;

	while(iterador != NULL){
		while(iterador -> caracter != '*' ){
			iterador = iterador -> sig;
		}

		nodoEspecial = iterador;
		iterador = iterador -> anterior;

		while(numOcupados < 2){
			if(iterador -> ocupado == 1 ){
				iterador = iterador -> anterior;
			}else{
				iterador ->ocupado = 1;
				if(numOcupados == 0){
					nodoEspecial -> derecha = iterador;
				}else if(numOcupados == 1){
					nodoEspecial -> izquierda = iterador;
				}
				iterador = iterador -> anterior;
				numOcupados++;
			}
		}
		numOcupados = 0;
		iterador = nodoEspecial -> sig;
		if(nodoEspecial -> sig == NULL){
			listaLeida = nodoEspecial;
		}
	}
	return listaLeida;
}

char x[8] = {" "};
int i=0;
char vacio[8] = {" "};

void crearCodigos(Lista * raiz, Lista * raiz1 , int dir){

	if (raiz != NULL){
	if(dir == 0 ){
		x[i]='0';
		i++;
		}
	if(dir == 1){
		x[i]='1';
		i++;
		}
	}
	if(raiz!=NULL){
		crearCodigos(raiz->izquierda,raiz1, 0);
		if(raiz == raiz1){
			strcpy(x,vacio);
			i = 0;
		}
		crearCodigos(raiz->derecha,raiz1,1);
		strcpy(raiz -> codigo, x);
		x[i]=' ';
		i--;
	}
}

void postorden( Lista * raiz){
	if(raiz!=NULL){
		postorden(raiz->izquierda);
		postorden(raiz->derecha);
		printf("Nodo: %c %d %s, \n",raiz->caracter,raiz->frecuencia, raiz -> codigo);
	}
}

char codigoEnPosicion(int posicion, Lista *inicio, int index){
    int tamanio = contarElementosLista(inicio);
	int x=0;
            for(x = 1; x<posicion;x++){
                inicio = inicio ->sig;
            }
  char codigoS[8] = {""};
  strcpy(codigoS,inicio->codigo);
  //printf(" %c Entro Letra %c\n",codigoS[index],inicio->caracter);
    return codigoS[index];
}

void generarPalabraCodificada(Lista * listaLimpia,char* codigoBin,char *palabra ){
int i = 0,j = 0,index = 0,k = 0,ini = 0;

    for(i=0;i<strlen(codigoBin)-1;i++){
        Lista *candidatos = NULL;
        Lista *aux = listaLimpia;
        index = 0;
        for(j=1;j<=contarElementosLista(listaLimpia);j++){
            if(codigoEnPosicion(j,listaLimpia,index) == codigoBin[i] ){
                candidatos = insertarInicio(aux->caracter,aux->frecuencia,candidatos,aux->codigo);
            }
            aux = aux->sig;
        }
        index++;
        i++;
        ini = 0;
        while(contarElementosLista(candidatos)!= 1){
            if(ini != 0){
                index++;
                i++;
            }
            for(j=1;j<=contarElementosLista(candidatos);j++){
                if(codigoEnPosicion(j,candidatos,index) != codigoBin[i]){
                    candidatos = popInter(candidatos,j);j--;
                   }
                   ini =1;
            }
        }
        if(candidatos->caracter == '_'){
        	palabra[k] = ' ';
		}else{
			palabra[k]=candidatos->caracter;
		}
        index = 0;
        k++;
    }
}

#endif //_2020640287_MMCS_h
