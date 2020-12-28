#ifndef _MMCS_2020640287_h
#define _MMCS_2020640287_h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

typedef struct _Hoja {
    char caracter;
	int frecuencia;
	char codigo[8];
	struct _Hoja *izquierda;
	struct _Hoja *derecha;
}Arbol;

typedef struct _Nodo{
    char caracter;
    int frecuencia;
    char codigo[8];
    struct _Nodo *sig;
    struct _Nodo *anterior;
    struct Arbol *Arbol;
}Lista;

Arbol * crearArbol(int frecuencia,char caracter){
	Arbol * nuevo;
	nuevo = (Arbol *)malloc(sizeof(Arbol));
	nuevo->caracter = caracter;
	nuevo->frecuencia = frecuencia;
	strcpy(nuevo -> codigo, " ");
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	return nuevo;
}

Lista * crearLista(char caracter, int frecuencia, Arbol * arbol){
   Lista *nuevo;
	nuevo = (Lista *) malloc (sizeof(Lista));
	nuevo -> frecuencia = frecuencia;
	nuevo -> caracter = caracter;
	strcpy(nuevo -> codigo, " ");
	nuevo -> Arbol = arbol;
	nuevo -> sig = NULL;
	nuevo -> anterior = NULL;
	return nuevo;
 }

Lista * crearListaBi(char caracter, int frecuencia, Arbol * arbol, char binario [8]){
   Lista *nuevo;
	nuevo = (Lista *) malloc (sizeof(Lista));
	nuevo -> frecuencia = frecuencia;
	nuevo -> caracter = caracter;
	strcpy(nuevo -> codigo, binario);
	nuevo -> Arbol = arbol;
	nuevo -> sig = NULL;
	nuevo -> anterior = NULL;
	return nuevo;
 }

Lista * insertarInicio(char caracter, int frecuencia, Lista *inicio,Arbol * arbol){
    Lista * nuevo;
    nuevo = crearLista(caracter,frecuencia,arbol);
    if(inicio != NULL){
        nuevo->sig = inicio;
        inicio->anterior = nuevo;
    }
    return nuevo;
 }
 
Lista * insertarInicioBi(char caracter, int frecuencia, Lista *inicio,Arbol * arbol, char binario[8]){
    Lista * nuevo;
    nuevo = crearListaBi(caracter,frecuencia,arbol,binario);
    if(inicio != NULL){
        nuevo->sig = inicio;
        inicio->anterior = nuevo;
    }
    return nuevo;
 }
 
Lista * insertarFinal(char caracter, int frecuencia, Lista *inicio,Arbol * arbol){
   	Lista *nuevo;
	Lista *aux;
	nuevo = crearLista(caracter,frecuencia,arbol);
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

Lista * insertarMedio(char caracter,  int frecuencia, int posicion, Lista *inicio, Arbol * arbol){
    Lista *aux = NULL;
    Lista *nuevo = NULL;
    nuevo = crearLista(caracter,frecuencia,arbol);
    int x = 0;
    int tamanioL = 0;
    tamanioL = contarElementosLista(inicio);
    if(posicion >= 1 && posicion <= tamanioL){
        if(posicion == 1){
            inicio = insertarInicio(caracter,frecuencia,inicio,arbol);
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

Lista *  borrarInicio(Lista * inicio){
    Lista * aux;
	aux=inicio;
	if(inicio !=NULL){
		inicio=inicio->sig;
		inicio ->anterior = NULL;
		free(aux);
	}
    return inicio;
 }
 
Lista * listaFrecuencia(char frase[100]){

     Lista * nuevo = NULL;
     Lista * aux = NULL;
     int posi = 0, signo = 0;
     int a;
     
    	for(a = 0; a < strlen(frase); a++){
            if(nuevo == NULL){
                nuevo = insertarInicio(frase[posi],1,nuevo,NULL);
            }else{
            aux = nuevo;
            if(aux->caracter == frase[posi]){
                aux->frecuencia++;
                signo = 1;
            }
            while(aux->sig != NULL && signo==0){
                if(aux->caracter == frase[posi]){
                    aux->frecuencia++;
                    signo = 1;
                }else{
                    aux = aux->sig;
                    signo = 0;
                    }
                if(aux->caracter == frase[posi]){
                    aux->frecuencia++;
                    signo = 1;
                    }
            }
            if(signo == 0){
                nuevo = insertarFinal(frase[posi],1,nuevo,NULL);
            }
            signo=0;

            }
            posi++;
     }
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
 
int frecuenciaEnPosicion(int posicion, Lista *inicio){
	Lista *aux = inicio;
    int x = 0, frecuencia = 0;
    int tamanio = contarElementosLista(inicio);

    if(posicion >= 1 && posicion <= tamanio){
            for(x = 1; x<posicion;x++){
                aux = aux ->sig;
            }
    }
    frecuencia = aux->frecuencia;
    return frecuencia;
}

char caracterEnPosicion(int posicion, Lista *inicio){
    int tamanio = contarElementosLista(inicio);
	int x=0;
            for(x = 1; x<posicion;x++){
                inicio = inicio ->sig;
            }
    return inicio->caracter;
}
 
void cambiarValorEn(int posicion, char caracter, int frecuencia, Lista *inicio){
    Lista *aux = inicio;
    int x = 0;
    int tamanio = contarElementosLista(inicio);

    if(posicion >= 1 && posicion <= tamanio){
            for(x = 1; x<posicion;x++){
                aux = aux ->sig;
            }
            aux->caracter=caracter;
            aux->frecuencia=frecuencia;

    }else{
        printf("Posicion no valida");
    }
}

Lista * ordenarLista(Lista * inicio){
    int frecuencia = 0,encontrar = 0,i = 0,j = 0;
    char caracter;

    for(i= 1; i<= contarElementosLista(inicio); i++){

        frecuencia = frecuenciaEnPosicion(i,inicio);
        caracter = caracterEnPosicion(i,inicio);
        j = i-1;
            while(j>=1 && ((frecuenciaEnPosicion(j,inicio))> frecuencia)){
                cambiarValorEn(j+1,caracterEnPosicion(j,inicio),frecuenciaEnPosicion(j,inicio),inicio);
                j--;
            }

        cambiarValorEn(j+1,caracter,frecuencia,inicio);
    }
    return inicio;
}

void generarFrecuencia(Lista * Inicio,Lista * InicioOriginal, Arbol **Raiz){
    Arbol * izquierda;
    Arbol * derecha;
    Arbol * papa;
    Lista * auxL = InicioOriginal;
    int tamanio = 0, frecuencia_aux=0,aux = 1,posicion = 0;
    
    if(Inicio == NULL){
        while(auxL->sig!=NULL){
            auxL = auxL->sig;
        }
        *Raiz = auxL->Arbol;
    }else{
        if(Inicio->sig==NULL){
            while(auxL->sig!=NULL){
            auxL = auxL->sig;
        }
        *Raiz = auxL->Arbol;
        }else{

            if(Inicio->Arbol != NULL){
                izquierda = Inicio->Arbol;
            }else{
                izquierda = crearArbol(Inicio->frecuencia,Inicio->caracter);
            }

            Inicio = Inicio->sig;

            if(Inicio->Arbol != NULL){
                derecha = Inicio->Arbol;
            }else{
                derecha = crearArbol(Inicio->frecuencia,Inicio->caracter);
            }
            Inicio = Inicio->sig;
            frecuencia_aux = derecha->frecuencia + izquierda->frecuencia;
            papa = crearArbol(frecuencia_aux,'*');
            papa->izquierda = izquierda;
            papa->derecha =  derecha;

            while(auxL != NULL && posicion==0){
                if((papa->frecuencia+1) <= auxL->frecuencia){
                    posicion=1;
                }
                else{
                    aux++;
                }
                auxL=auxL->sig;
            }
            tamanio = contarElementosLista(InicioOriginal) + 1;
            if(tamanio>aux){
                InicioOriginal = insertarMedio(papa->caracter,papa->frecuencia,aux,InicioOriginal,papa);
            }
            else{
                InicioOriginal = insertarFinal(papa->caracter,papa->frecuencia,InicioOriginal,papa);
            }
            generarFrecuencia(Inicio,InicioOriginal,&(*Raiz));
        }
    }
}

char x[8] = {" "};
int i=0;
char vacio[8] = {" "};

void crearCodigos(Arbol * raiz, Arbol * raiz1 , int dir){
	
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

Lista * quitarEspeciales(Arbol * raiz, Lista * lista){

	if(raiz!=NULL){
		
		lista = quitarEspeciales(raiz->izquierda,lista);
		lista = quitarEspeciales(raiz->derecha,lista);
		if(raiz -> caracter != '*')
		lista = insertarInicioBi(raiz->caracter,raiz->frecuencia, lista,NULL, raiz -> codigo);	
	}
	
	return lista;
}

void imprimirArbolPost(Arbol * raiz,FILE * arbol){
	if(arbol == NULL){
		perror("\nNo se pudo abrir el archivo\n");
	}
	if(raiz!=NULL){
		imprimirArbolPost(raiz->izquierda,arbol);
		imprimirArbolPost(raiz->derecha,arbol);
		fprintf(arbol,"%c %d ",raiz->caracter,raiz->frecuencia);
	}
}

#endif
