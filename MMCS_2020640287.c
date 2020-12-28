#include "MMCS_2020640287.h"
#include <math.h>

char fraseCadena[100];
void limpiarEspacio(char cadena[200],char fraseCadena[100],Lista* binLimpio);
void agregarCeros(char cadena[200]);
void binarioDecimal(char cadena[200]);

int main (){

	FILE *frase = fopen("frase.txt","r");
    Lista * listaAux = NULL;
    Arbol * arbolAux = NULL;
    Lista * binLimpio = NULL;
    Lista *listaAyuda = NULL;
    char binarioString [200] = {" "};
    int i = 0,e = 0,j=0;
    
    system("color 0a");
    printf("\n\tMartin Moreno Cesar Sadrak 2020640287 UPIITA_IPN\n\n");
    printf("\t\t***Codificacion Huffman***\n\n");
    
    if(frase != NULL){
		while(feof(frase) == 0){
			fscanf(frase,"%c",&fraseCadena[e]);
			e++;
		}
	}
	fclose(frase);
	
	printf("\nFrase leida: %s\n",fraseCadena);
	
    for(i = 0; fraseCadena[i] != '\0'; i++){
        if(fraseCadena[i] == ' '){
            fraseCadena[i] = '_';
        }else{
            fraseCadena[i] = tolower(fraseCadena[i]);
        }
    }
    

listaAux = generarListaFrecuencia(fraseCadena);

listaAux=ordenarLista(listaAux);

printf("\n***Lista de frecuencias de caracteres***\n");
verLista(listaAux);

generarFrecuencia(listaAux,listaAux,&arbolAux);

crearCodigos(arbolAux,arbolAux,2);

binLimpio = quitarEspeciales(arbolAux,binLimpio);

limpiarEspacio(binarioString,fraseCadena,binLimpio);

agregarCeros(binarioString);

printf("\n\n***Codigos binarios y Decimales***\n");
binarioDecimal(binarioString);

imprimirArbolPost(arbolAux);

printf("\n\n***Codigo Binario***\n\n");
printf("%s\n\n", binarioString);

printf("\nEl archivo con el codigo se ha generado como codigo.bin \ny la llave se ha generado como llave.txt\n\n");


return 0;
}

void limpiarEspacio(char cadena[200],char fraseCadena[100],Lista* binLimpio){
	char nueva[200] = {" "};
	int a = 0;
	int i,j;
	Lista *listaAyuda = binLimpio;
	
	for(i = 0; i< strlen(fraseCadena);i++){
		for(j = 0; j < contarElementosLista(binLimpio); j++){
			if(fraseCadena[i] == listaAyuda -> caracter){
				strcat(cadena, listaAyuda -> codigo);
				break;
			}
			listaAyuda = listaAyuda -> sig;
		}
		listaAyuda = binLimpio;
	}
	
	
	for(i = 0; i<strlen(cadena);i++){
		if(cadena[i] != ' '){
			nueva[a]= cadena[i];
			a++; 
		}
	}
	strcpy(cadena,nueva);
}

void agregarCeros(char cadena[200]){
	char cero[2] = "0";
	int tamCadena = strlen(cadena);
	int numCeros = 7 - (tamCadena%7);
	int a;
	for(a = 0;a<numCeros;a++){
		strcat(cadena,cero);
	}
}

void binarioDecimal(char cadena[200]){
	FILE * archivoDecimal = fopen("codigo.bin","wb");
	int a,i=0,j,k=0,l = 0;
	int decimal=0;
	char binarioPeque[20] = {" "};
	char auxBin[200] = {" "};
	char auxDec[20] = {" "};
	int numInicial = strlen(cadena)/7;
	fwrite(&numInicial,sizeof(numInicial),1,archivoDecimal);
	//fprintf(archivoDecimal,"%i",numInicial);
		
	for(a=0; a<strlen(cadena);a++){
		binarioPeque[l] = cadena[a];
		i++;
		l++;
		if(i == 7){
			for(j=7;j>0;j--){
				if(binarioPeque[j-1] == '1'){
					decimal = decimal + (1 * pow(2,k));
					k++;
				}else if(binarioPeque[j-1] == '0'){
					decimal = decimal + (0 * pow(2,k));
					k++;
				}
			}
			printf("\nCodigo: %s con decimal %i",binarioPeque,decimal);
			fwrite(&decimal,sizeof(decimal),1,archivoDecimal);
		//	fprintf(archivoDecimal,"%i",decimal);
			k = 0;
			decimal = 0;
			i = 0;
			l=0;
		}
	}
	fclose(archivoDecimal);
}





