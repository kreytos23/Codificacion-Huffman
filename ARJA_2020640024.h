#ifndef _ARJA_2020640024_h
#define _ARJA_2020640024_h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXIMO(i,d) (((i)>(d))?(i):(d))


//Declaración del arbol
typedef struct _NodoA{
    char caracter;
	int frecuencia;
	struct _NodoA *izquierda;
	struct _NodoA *derecha;
}Arbol;

//Declaración de la lista
typedef struct _NodoL{
    char caracter;
    int frecuencia;
    char codigo[8];
    struct _NodoL *sig;
    struct _NodoL *anterior;
    struct Arbol *Arbol;
}Lista;

//Crear arbol

Arbol * crearArbol(int frecuencia,char caracter){
	Arbol * nuevo;
	nuevo = (Arbol *)malloc(sizeof(Arbol));
	nuevo->caracter = caracter;
	nuevo->frecuencia = frecuencia;
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	return nuevo;

}

//Crear lista
Lista * crearLista(char caracter, int frecuencia, Arbol * arbol){
   Lista *nuevo;
	nuevo = (Lista *) malloc (sizeof(Lista));
	nuevo -> frecuencia = frecuencia;
	nuevo -> caracter = caracter;
	nuevo -> Arbol = arbol;
	nuevo -> sig = NULL;
	nuevo -> anterior = NULL;
	return nuevo;
 }

 //Insertar datos en el arbol
/*
Nodo *insertarArbol(Nodo * arbol, int frecuencia,char caracter){
	Nodo * raiz;
	Nodo * nuevo;

	nuevo = crear(frecuencia,caracter);

	if(arbol==NULL){
		return nuevo;
	}else{
		raiz=arbol;
		while(raiz!=NULL){
			if(nuevo->dato > raiz->dato){
				if(raiz->derecha==NULL){
				raiz->derecha=nuevo;
				return arbol;
				}else{
					raiz=raiz->derecha;
				}
			}else{
				if(raiz->izquierda==NULL){
					raiz->izquierda=nuevo;
					return arbol;
				}else{
					raiz=raiz->izquierda;
				}

			}
		}
	}

}
*/


                                                    //Funciones para la lista
//Insercion de datos
Lista * insertarInicio(char caracter, int frecuencia, Lista *inicio,Arbol * arbol){
    Lista * nuevo;
    nuevo = crearLista(caracter,frecuencia,arbol);
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


//Tamanio de la lista
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

 //Ver lista
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

 //Generar la lista de frecuencia
 Lista * generarListaFrecuencia(char frase[100]){

     Lista * nuevo = NULL;
     Lista * aux = NULL;

     int posicion = 0, encontrar = 0;
     while(frase[posicion]!='\0'){
            if(nuevo == NULL){
                nuevo = insertarInicio(frase[posicion],1,nuevo,NULL);
            }else{
            aux = nuevo;
            if(aux->caracter == frase[posicion]){
                aux->frecuencia++;
                encontrar = 1;
            }
            while(aux->sig != NULL && encontrar==0){
                if(aux->caracter == frase[posicion]){
                    aux->frecuencia++;
                    encontrar = 1;
                }else{
                    aux = aux->sig;
                    encontrar = 0;
                    }
                if(aux->caracter == frase[posicion]){
                    aux->frecuencia++;
                    encontrar = 1;
                    }
            }
            if(encontrar == 0){
                nuevo = insertarFinal(frase[posicion],1,nuevo,NULL);
            }
            encontrar=0;

            }
            posicion++;
     }

    verLista(nuevo);
    return nuevo;

 }
//Ordenar lista de frecuencia
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


//Borrar elementos de la lista

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
/*
Arbol * arbolEnPosicion(int posicion, Lista *inicio){
    int tamanio = contarElementosLista(inicio);
	int x=0;
            for(x = 1; x<posicion;x++){
                inicio = inicio ->sig;
            }

    return inicio->Arbol;
}
*/

Lista * ordenarLista(Lista * inicio){
    int minimo=0;
    int frecuencia_Aux=0;
    int encontrar = 0;
    int aux =0;
    char caracter_aux='c';
    Arbol * arbol_aux=NULL;
    Lista * auxL = inicio;
    int aux1,aux2;
    for(aux1=1; aux1<=contarElementosLista(inicio)-1;aux1++){
        minimo = aux1;
        frecuencia_Aux = frecuenciaEnPosicion(aux1,inicio);
        caracter_aux = caracterEnPosicion(aux1,inicio);
        for(aux2=aux1+1;aux2<=contarElementosLista(inicio);aux2++){
            if(frecuenciaEnPosicion(aux2,inicio)<=frecuencia_Aux){
                minimo=aux2;
                frecuencia_Aux = frecuenciaEnPosicion(aux2,inicio);
                caracter_aux = caracterEnPosicion(aux2,inicio);
            }
        }

        cambiarValorEn(minimo,caracterEnPosicion(aux1,inicio),frecuenciaEnPosicion(aux1,inicio),inicio);
        cambiarValorEn(aux1,caracter_aux,frecuencia_Aux,inicio);
       /* printf("\nComprobando el orden de la lista\n");
        verLista(inicio);
        system("PAUSE");*/
    }
    verLista(inicio);
   inicio =  borrarInicio(inicio);
   verLista(inicio);
     while(auxL != NULL && encontrar==0){
                if(2 <= auxL->frecuencia){
                    encontrar=1;
                }
                else{
                    aux++;
                }
                auxL=auxL->sig;
            }
            printf("\nPosicion: %d\n",aux);
    inicio = insertarMedio('.',1,aux,inicio,NULL);
    verLista(inicio);
    return inicio;
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

//Crear el arbol de frecuencias

void crearArboldeFrecuencia(Lista * Inicio,Lista * InicioOriginal, Arbol **Raiz){
    Arbol * izquierda;
    Arbol * derecha;
    Arbol * papa;
    Lista * auxL = InicioOriginal;


    int tamanio = 0, frecuencia_aux=0,aux = 1,posicion = 0;
    printf("\nDebuguiando\n");
    verLista(Inicio);
    if(Inicio == NULL){
        printf("\nLa lista esta vacia (para generar el arbol)");
        while(auxL->sig!=NULL){
            auxL = auxL->sig;
        }
        printf("\nMe encuentro aqui1\n");
        *Raiz = auxL->Arbol;
    }else{
        if(Inicio->sig==NULL){
            while(auxL->sig!=NULL){
            auxL = auxL->sig;
        }
        printf("\nMe encuentro aqui2\n");
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
            printf("\nTamanio: %d\nPosicion: %d",tamanio,aux);
            if(tamanio>aux){
                InicioOriginal = insertarMedio(papa->caracter,papa->frecuencia,aux,InicioOriginal,papa);
            }
            else{
                InicioOriginal = insertarFinal(papa->caracter,papa->frecuencia,InicioOriginal,papa);
            }
            verLista(InicioOriginal);
            printf("\n\n");
            crearArboldeFrecuencia(Inicio,InicioOriginal,&(*Raiz));

        }


    }

}


void generarListaArbolPreorden(Arbol * Raiz,Lista **Inicio){
    if (Raiz !=NULL){
        *Inicio = insertarFinal(Raiz->caracter,Raiz->frecuencia,Inicio,NULL);

        if(Raiz->izquierda!=NULL){
            generarListaArbolPreorden(Raiz->izquierda,&*Inicio);
        }
        if(Raiz->derecha!=NULL){
                generarListaArbolPreorden(Raiz->derecha,&*Inicio);

        }
    }
    else{
        printf("\El arbol esta vacio\n");
    }
}

void crearArchivoDeArbol(Arbol * Raiz, Lista * Inicio){
    FILE * Archivo;
    Lista * aux;
    aux = Inicio;

    Archivo = fopen("ArbolPreOdern.txt","a");

    if(Archivo==NULL){
        printf("Error al abrir el archivo ArbolPreorden.txt");
    }
    else{
        generarListaArbolPreorden(Raiz,&aux);
        verLista(aux);
        while(aux!=NULL){
                if(aux->caracter=='*'){
                    fprintf(Archivo,"%c %d",aux->caracter,aux->frecuencia);
                }else{
                    fprintf(Archivo,"%c %d",aux->caracter,aux->frecuencia);
                }
                aux = aux->sig;
        }
        system("PAUSE");
    }
    fclose(Archivo);
}





/*
void crearArboldeFrecuencia(Lista * Inicio, Lista * Referencia, Arbol **Raiz){
    Arbol * izquierda;
    Arbol * derecha;
    Arbol * papa;


    int frecuencia_aux = 0;
    int tamanio = 0;

    Lista * apRecorre = Referencia;
    int i = 1;
    int selector = 0;


    if (Inicio == NULL){
        printf("\nLista vacia (Creado Arbol Frecuencia)\n");
        while(apRecorre->sig!=NULL){
            apRecorre = apRecorre ->sig;
        }
        printf("\nMe encuentro aqui 1\n\n");
        *Raiz = apRecorre->Arbol;

    }
    else{
        if(Inicio==NULL){
            while(apRecorre->sig!=NULL){
                apRecorre=apRecorre->sig;
            }
            printf("\nMe encuentro aqui2\n\n");
            *Raiz = apRecorre->Arbol;
        }
        else{
                //Creando hijos a la izquierda
            if(Inicio->Arbol!=NULL){
                izquierda=Inicio->Arbol;
            }
            else{
                izquierda = crearArbol(Inicio->frecuencia,Inicio->caracter);
            }
            Inicio = Inicio->sig;
            //Creando hijos a la derecha
            if(Inicio->Arbol!=NULL){
                derecha = Inicio->Arbol;
            }
            else{
                derecha = crearArbol(Inicio->frecuencia,Inicio->caracter);
            }
            Inicio = Inicio ->sig;

            //Creando nodos padre e hijos
            frecuencia_aux = derecha->frecuencia + izquierda->frecuencia;
            papa = crearArbol(frecuencia_aux,'*');
            papa->derecha = derecha;
            papa->izquierda = izquierda;

            printf("Datos del papa\n Frecuencia: %d\t Caracter: %c\n",papa->frecuencia,papa->caracter);

            while(apRecorre!=NULL && selector==0){
                if((papa->frecuencia+1)<=apRecorre->frecuencia){
                    selector = 1;
                }
                else{
                    i++;
                }
                apRecorre = apRecorre->sig;
            }


            tamanio = contarElementosLista(Referencia)+1;
            printf("\nTamanio Lista: %d\n",tamanio);
            printf("Posicion: %d\n",i);

            if(tamanio>=i){
                Referencia = insertarMedio(papa->caracter,papa->frecuencia,i,Referencia,papa);
            }
            else{
                Referencia = insertarFinal(papa->caracter,papa->frecuencia,Referencia,papa);
            }
            verLista(Referencia);
            system("PAUSE");
            crearArboldeFrecuencia(Inicio,Referencia,&(*Raiz));


        }
    }
}

*/




//Insertar datos en el arbol
/*
void moverIzquierda(Nodo ** arbol){
	Nodo * aux1;
	Nodo * aux2;

	aux2 = (*arbol);
	aux1 = (*arbol)->izquierda;

	while(aux1->derecha!=NULL){
		aux2 = aux1;
		aux1 = aux1->derecha;
	}
	(*arbol)->dato = aux1->dato;
	if(aux2 == (*arbol))
		aux2->izquierda = aux1->izquierda;
	else
		aux2->derecha = aux1->izquierda;

	(*arbol)=aux1;
}

void borrarArbol(Nodo ** arbol, int buscar){
	Nodo * aux;
	if(*(arbol)==NULL){
		printf("\nNO EXISTE EL NODO A BORRAR");
	}else{
		if(buscar < (*arbol)->dato)
		borrar(&(*arbol)->izquierda,buscar);
		else if(buscar > (*arbol)->dato)
		borrar(&(*arbol)->derecha,buscar);
		if(buscar == (*arbol)->dato){
			aux = (*arbol);
			if(aux->izquierda==NULL)
			(*arbol)=aux->derecha;
			else if(aux->derecha==NULL)
			(*arbol) = aux->izquierda;
			else
			moverIzquierda(&aux);
			free(aux);

		}
	}

}*/


/*
  Nodo* borrarFinal(Nodo *inicio){
	Nodo *aux;
	Nodo *fin;
	if(inicio == NULL){
		printf("La lista esta vacia");
	}else{
		aux = inicio;
		int x = 0;
		for(x = 1; x < contarElementos(inicio)-1; x++){
            aux = aux ->sig;
		}
		fin = aux->sig;
		aux ->sig = NULL;
		free(fin);
	}
    return inicio;
 }

 Nodo * borrarMedio(Nodo *inicio,int posicion){
    Nodo *aux = inicio;
    Nodo *fin = NULL;
    int x = 0;
    int tamanioL = contarElementos(inicio);
    if(posicion >= 1 && posicion <= tamanioL){
        if(posicion == 1){
            inicio = borrarInicio(inicio);
        }else if(posicion == contarElementos(inicio)){
            inicio = borrarFinal(inicio);
        }else{
            for(x = 1; x<posicion-1;x++){
                aux = aux ->sig;
            }
            fin = aux->sig;
            aux ->sig = fin ->sig;
            fin ->sig ->anterior = aux;
            free(fin);
        }
    }else{
        printf("Posicion invalida");
    }
    return inicio;
 }
*/
 //Recorrer arbol en preorder el arbol

 /*void preorder(Arbol * raiz){
	if(raiz!=NULL){
		printf("Caracter : %c\tFrecuencia : %d\n",raiz->caracter,raiz->frecuencia);
		preorder(raiz->izquierda);
		preorder(raiz->derecha);
	}
}
*/
char x[8] = {" "};
int i=0;
char vacio[8] = {" "};
/*
void agregarBinario(Lista *lista, char binario[8], char caracter){
	int j;
	for(j=0; j<contarElementosLista(lista); j++){
		if(caracter == lista -> caracter){
			strcpy(lista -> codigo, binario);
			break;
		}
		else{
			lista = lista -> sig;
		}	
	}
	
}*/
void postorden(Arbol * raiz, Arbol * raiz1 , int dir){
	
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
		
		postorden(raiz->izquierda,raiz1, 0);
		if(raiz == raiz1){
		strcpy(x,vacio);
		i = 0;
		printf("%i entra _%s_ \n\n",i, x);
		}
		postorden(raiz->derecha,raiz1,1);
		
		printf("Caracter: %c\tFrecuencia: %d Codigo: %s \n",raiz->caracter,raiz->frecuencia, x);
	//	agregarBinario(lista, x,raiz->caracter);
		x[i]=' ';
		i--;
	}
	
}



#endif _ARJA_2020640024_h
