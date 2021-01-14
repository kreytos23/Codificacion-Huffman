#include "2020640287_deco_MMCS.h"

Lista * leerArchivo(FILE* llave, Lista * listaArbol);
void generarCodigoBin(FILE * binarioArc, char codigoBinPalabra [500]);

int main(){

	FILE *llave;
	FILE *binarioArc;
	FILE *frase;
	Lista *listaArbol = NULL,*listaLimpia = NULL;
	
    char palabra [50] = {""},llaveN[30] = {""},llaveB[30] = {""};
    char codigoBinPalabra [500] = {""};

	system("color 0a");
    printf("\t***Martin Moreno Cesar Sadrak 2020640287**\n\n");
    printf("\n\t\t***DECODIFICADOR**\n\n");
    printf("Nombre de la llave con extension: ");
    gets(llaveN);
    fflush(stdin);
    printf("\nNombre del Binario con extension: ");
    gets(llaveB);
    fflush(stdin);
	
    llave = fopen(llaveN,"r");
    binarioArc = fopen(llaveB,"rb");

    listaArbol = leerArchivo(llave,listaArbol);
    generarCodigoBin(binarioArc,codigoBinPalabra);
	
    fclose(binarioArc);
	fclose(llave);
	
	listaArbol = generarListaDeArbol(listaArbol);
	crearCodigos(listaArbol,listaArbol,2);
	
	printf("\n**********************************\n");
	printf("\nEl codigo binario de la palabra es:\n \n%s \n",codigoBinPalabra);
	
	listaLimpia = quitarEspeciales(listaArbol, listaLimpia);
	
	printf("\nLas Letras Fueron: \n");
	verLista(listaLimpia);
	printf("\n\n");
	
    generarPalabraCodificada(listaLimpia,codigoBinPalabra,palabra);
    printf("\n\n\tLa Frase Decodificada Es: %s\n",palabra);
    printf("\n\nLa Frase Decodificada Fue Escrita En El Archivo frase.txt\n",palabra);
    
    frase = fopen("frase.txt","w");
    for(i=0;i<strlen(palabra);i++){
        fprintf(frase,"%c",palabra[i]);
    }
	fclose(frase);
	return 0;
}

Lista * leerArchivo(FILE* llave, Lista * listaArbol){
    char caracter = NULL, binario[8] = {" "},punto = NULL;
    int frePunto = 0;
    int frecuencia;

	if(llave == NULL){
		perror("\nArchivo de llave no encontrado");
		exit(0);
	}else{
		while(feof(llave) == 0){
			fscanf(llave,"%c %d",&caracter,&frecuencia);
			if(caracter != ' '){
				punto = caracter;
				frePunto = frecuencia;
				listaArbol = insertarFinal(caracter,frecuencia,listaArbol,binario);
			}
		}
	}
	return listaArbol;
}

void generarCodigoBin(FILE * binarioArc, char codigoBinPalabra [500] ){
	int i = 0 ,k = 0,index = 0, j = 0,secciones ,numero = 0;
	char cadenaCeros [10] = {""},ceros[2] = {"0"};
    char binNumero[8] = {""};
		
	if(binarioArc == NULL){
    	perror("\nArchivo binario no encontrado");
    	exit(0);
    }else{
        fread(&secciones,sizeof secciones,1,binarioArc);
        for(i = 0;i<secciones;i++){
            fread(&numero,sizeof numero, 1, binarioArc);
            itoa(numero,binNumero,2);
            if(strlen(binNumero)!= 7){
            int cerosInsertar = 7-strlen(binNumero);
            for(j=0;j < cerosInsertar;j++){
                strcat(cadenaCeros,ceros);
            }
            }
            strcat(cadenaCeros,binNumero);
            strcat(codigoBinPalabra,cadenaCeros);
            strcpy(cadenaCeros,"");
        }
    }
}
