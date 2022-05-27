#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define TAM_MAX 20



struct TUsuario {
        char usuario[50];
        char clave[10]; 
		int puntos;          
};

usingnamespace_std;


//definicion de funciones

int operacionesmat();
int enigmas ();
int palabdes();
int dadosiguales();
int letraperdida ();



int main(){
	
	 system("color 9f");// cambia el color de la pantalla del juego
	
	int eleccion;
	int juegoTerminado = 0;
	int sesionIniciada = 0;
	struct TUsuario usuarios[TAM_MAX];
    int contador;
    int i;
    char usuarioActual[50];
	char clave[50];
    char opcion;
    FILE*pfile;
    

    
    // Primero se pregunta cuantos jugadores hay inicialmente
    system("cls");
    printf("Indica el numero de jugadores que hay inicialmente:\n");
    scanf("%d", &contador);
    fflush(stdin);
    // Pedimos los datos de los usuarios
    for(i=0; i<contador; i++) {
            printf("Introduce el nombre de usuario:\n");
            scanf("%s", usuarios[i].usuario);
            fflush(stdin);
            printf("Introduce la clave elegida:\n");            
            scanf("%s", usuarios[i].clave);
            fflush(stdin);
            usuarios[i].puntos = 200;
            
    }
    pfile = fopen("Usuarios.txt","w+");
    if (pfile == NULL) {
        printf("Error.No existe el fichero\n");
        fclose(pfile);
        return 0;
    }
    else {
    	for (i = 0; i < contador; i++){
    		fprintf(pfile,"%s %s %d", usuarios[i].usuario, usuarios[i].clave, usuarios[i].puntos);
    		fprintf(pfile, "\n");
		}
    	fclose(pfile);
	}   
	
    do {
            fflush(stdin);
            system("cls");
            if (juegoTerminado == 0){
            	printf("Bienvenidos a nuestro Scape room.\n");
	            printf("Elige la opcion deseada:\n");
	            printf("A -Iniciar sesion con tu usuario.\n");
	            printf("B -Elige nivel de dificultad.\n");
	            printf("C -Instrucciones del scape room.\n");
	            printf("S - Salir.\n");
	            scanf("%c", &opcion);
			}
			else{
				printf("Felicidades has completado el juego\n");
    			printf("Es admirable tu inteligencia\n");
  			    printf("Conseguiste escapar de este Scape room con: ");
   				printf("%d", usuarios[i].puntos);
   				printf("\n");
   				system("pause");
			   	pfile = fopen("Usuarios.txt","w+");
			    if (pfile == NULL) {
			        printf("Error.No existe el fichero\n");
			        fclose(pfile);
			        return 0;
			    }
			    else {
			    	fprintf(pfile,"%s %s %d", usuarios[i].usuario, usuarios[i].clave, usuarios[i].puntos);
			    	fprintf(pfile, "\n");
			    	fclose(pfile);
				}   
				opcion = 'S';
			}            
            switch(opcion) {
                    case 'A':
                            printf("Introduce el nombre del nuevo usuario:\n");
							fflush(stdin);
							scanf("%s",&usuarioActual);
							printf("Introduce la clave elegida:\n");
            				fflush(stdin);
            				scanf("%s", &clave);							
            				    
                        	int encontrado = 0;
                            i = -1;
                            while(i < TAM_MAX && encontrado == 0){
                            	i++;
                            	if (strcmp(usuarios[i].usuario, usuarioActual) == 0 && strcmp(usuarios[i].clave, clave) == 0)
                            		encontrado = 1;
							}
							if (encontrado == 0){
								printf("Usuario no encontrado o clave incorrecta\n");
								system("pause");
							}
							else{
								sesionIniciada = 1;
								printf("Sesion iniciada correctamente\n");
								system("pause");
							}
								
                            break;
                    case 'B':
                    		system("cls");
                    		if (sesionIniciada == 1){
                    			printf("Pulsa 1 para nivel facil:\n");
	                            printf("Pulsa 2 para nivel dificil:\n");	
	                            scanf("%i",&eleccion);
	                            fflush(stdin);
	                            usuarios[i].puntos -= operacionesmat();
						        usuarios[i].puntos -= enigmas ();
								usuarios[i].puntos -= palabdes();
								juegoTerminado = 1;						    
								if(eleccion == 2) {
									juegoTerminado = 0;						
									usuarios[i].puntos -= dadosiguales();
									usuarios[i].puntos -= letraperdida();
									juegoTerminado = 1;
								}
							}
							else{
								printf("Necesitas iniciar sesion con tu usuario y clave para poder jugar\n");
	                            system("pause");	
							}                     
							break;    
                    
                    case 'C':
                    		system("cls");
                            printf("Instrucciones:\n");
							printf("El scape room consta de dos modalidades,es decir, dos niveles de dificultad.\n");
							printf("La mecanica de juego es normalmente la misma en todos los Scape Room.\n");
							printf("Lo primero sera optar entre dos niveles,uno mas facil y corto;y otro mas dificil y largo.\n"); 
							printf("Habra que intentar superar una serie de pruebas para poder llegar al final del Scape Room con el maximo de "); 
							printf("puntos posibles .\n");
							printf(" Al principio de cada prueba se daran una serie de instrucciones básicas para poder entender que es lo que hay que hacer en cada nivel ");
							printf("para superar con exito las pruebas.\n");
							system("pause");     
			                break;
			}
    } while (opcion != 'S');  
	
	return 0; 
}


// CUERPO DE FUNCIONES

int operacionesmat(){
	int eleccion;
    int contador;
    int i;
    int puntosEliminados = 0;
    int respuestamat;
    system("cls");
	printf("Bienvenido a la primera prueba de este tenebroso viaje.\n");
	printf("Prueba 1: Operaciones matematicas\n");
	printf("Para poder superar esta primera prueba debeis acertar varias operaciones matematicas.\n");
	printf("Comienza el juego.\n");
	
	printf("25+5-3*2=__\n");
	do{
		scanf("%i",&respuestamat);
		fflush(stdin);
		if (respuestamat == 24)
			printf("La respuesta es correcta.\n");
		else {
			printf("La respuesta es incorrecta.\n");
			puntosEliminados += 10;
		}			
	} while (respuestamat != 24);
	printf("7*3-2+8=__\n");
	do{
		scanf("%i",&respuestamat);
		fflush(stdin);
		if (respuestamat == 27)
			printf("La respuesta es correcta.\n");
		else {
			printf("La respuesta es incorrecta.\n");
			puntosEliminados +=10;
		}			
	} while (respuestamat != 27);
	printf("1+5+10*5=__\n");
	do{
		scanf("%i",&respuestamat);
		fflush(stdin);
		if (respuestamat == 56)
			printf("La respuesta es correcta.\n");
		else {
			printf("La respuesta es incorrecta.\n");
			puntosEliminados +=10;
		}			
	} while (respuestamat != 56);
	printf("Fin de la prueba 1");
	return puntosEliminados;		
}
							
int enigmas (){
	int contador;
    int i;
    int puntosEliminados = 0;
    char opcion;
    int resueltoA = 0, resueltoB = 0, resueltoC = 0;
	char res[10];  
	
	system("cls");
	printf("Enhorabuena has llegado a tu segunda parada.\n");
	printf("Prueba 2: Enigmas\n");
	printf("Para poder superar esta segunda prueba debereis estrujaros el cerebro y acertar estas adivinanzas planteadas a continuacion:.\n");
	printf("Comienza el juego.\n");
    	
    do {
	    fflush(stdin);
	    printf("Elige la opcion deseada:\n");
	    if (resueltoA != 1)
		    printf("A -Enigma 1.\n");
		if (resueltoB != 1)
		    printf("B -Enigma 2.\n");
		if (resueltoC != 1)
		    printf("C -Enigma 3.\n");
	    scanf("%c", &opcion);
	    switch(opcion) {
	            case 'A':
	            	if(resueltoA != 1) {
	            		printf("Si me tienes, quieres compartirme. Si me compartes, no me tienes. ¿Que soy? \n\n");
						scanf("%s", res);
						if(strcmp(res, "secreto") == 0){
							printf("La respuesta es correcta\n");
							resueltoA = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");	    
							puntosEliminados +=10;     
						}							          
					}
					break;           
	                    
	            case 'B':
	            	if (resueltoB != 1){
	            		printf("Ponme de lado y soy todo. Cortame por la mitad y no soy nada. ¿Que soy? \n\n");
						scanf("%s", res);
						if(strcmp(res, "ocho") == 0){
							printf("La respuesta es correcta\n");
							resueltoB = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;	
						}								
					}
					break;
	                    
	            case 'C':
	            	if (resueltoC != 1) {
	            		printf("Este banco esta ocupado por un padre y por un hijo,el padre se llama Juan y el hijo ya te lo he dicho.\n");
						printf(" ¿Como se llama el hijo? \n\n");
						scanf("%s", res);
						if(strcmp(res, "esteban") == 0) {
							printf("La respuesta es correcta\n");
							resueltoC = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;	
						}									
					}
					break;	 
		}
            
    } while (resueltoA == 0 || resueltoB == 0 || resueltoC == 0);
        
        printf("Fin de la prueba");
       
        return puntosEliminados;	
}

int palabdes(){
	int contador;
    int i;
    int puntosEliminados = 0;
    char opcion;
    int mosca,cocina,rueda;
    int resueltoA = 0, resueltoB = 0, resueltoC = 0;
    char res[10];
	system("cls");
	printf("Enhorabuena has llegado a la tercera prueba.\n");
	printf("Prueba 3: Palabras desordenadas\n");
	printf("Para poder superar esta tercera prueba debereis estrujaros el cerebro y acertar estas adivinanzas planteadas.\n");
	printf("Comienza el juego.\n");
    	
    do {
	    fflush(stdin);
	    printf("Elige la opcion deseada:\n");
	    if (resueltoA != 1)
		    printf("A -Palabra 1.\n");
		if (resueltoB != 1)
		    printf("B -Palabra 2.\n");
		if (resueltoC != 1)
		    printf("C -Palabra 3.\n");
	    scanf("%c", &opcion);
	    switch(opcion) {
	            case 'A':
	            	if(resueltoA != 1) {
	            		printf("csmao \n\n");
						scanf("%s", res);
						if(strcmp(res, "mosca") == 0){
							printf("La respuesta es correcta\n");
							resueltoA = 1;
						}							
						else {
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;	 
						}							                  
					}
					break;           
	                    
	            case 'B':
	            	if (resueltoB != 1){
	            		printf("aduer \n\n");
						scanf("%s", res);
						if(strcmp(res, "rueda") == 0){
							printf("La respuesta es correcta\n");
							resueltoB = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;
						}									
					}
					break;
	                    
	            case 'C':
	            	if (resueltoC != 1) {
	            		printf("nicoca \n\n");
						scanf("%s", res);
						if(strcmp(res, "cocina") == 0) {
							printf("La respuesta es correcta\n");
							resueltoC = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;	
						}									
					}
					break;	 
		}            
    } while (resueltoA == 0 || resueltoB == 0 || resueltoC == 0);        
        printf("Has superado la prueba.\n");
	
return puntosEliminados;	
}

int dadosiguales(){
int d1,d2,c1,c2,i,j;
int puntosEliminados = 0;
system("cls");
	printf("Enhorabuena has llegado a la cuarta prueba.\n");
	printf("Prueba 4: Numeros aleatorios\n");
	printf("Para poder superar esta cuarta prueba debereis usar la logica.\n");
	printf("Comienza el juego.\n");
	
    printf("Introduce el primer numero:\n");
	fflush(stdin);
    scanf("%s",&c1);
    printf("Introduce segundo numero:\n");
	fflush(stdin);
	scanf("%c",&c2);
	srand((unsigned)time(NULL));
	rand();
	for(i=1;i<100;i++){
	d1=d2=0;
	for(j=1;j<=6;j++){
		d1=d1+rand()+1;
		d2=d2+rand()+1;
	}
	if(d1>d2)
	    c1++;
	else if(d1<d2)
	    c2++;    
	}	

	if(c1>=c2)
	   printf("La respuesta es correcta.\n");
	else{
		printf("La respuesta es incorrecta.\n");
	  	puntosEliminados +=10;
	}	  	
	system("pause");
return puntosEliminados;		
}

int letraperdida () {
	int contador;
    int i;
    int puntosEliminados = 0;
    char opcion;
    int resueltoA = 0, resueltoB = 0, resueltoC = 0;
    char res[10];
	system("cls");
	printf("Enhorabuena has llegado a la ultima prueba.\n");
	printf("Prueba 5: Encuentra la letra perdida\n");
	printf("Para poder superar esta ultima prueba debereis ser astutos.\n");
	printf("Comienza el juego.\n");
    	
    do {
	    fflush(stdin);
	    printf("Elige la opcion deseada:\n");
	    if (resueltoA != 1)
		    printf("A -Palabra 1.\n");
		if (resueltoB != 1)
		    printf("B -Palabra 2.\n");
		if (resueltoC != 1)
		    printf("C -Palabra 3.\n");
	    scanf("%c", &opcion);
	    switch(opcion) {
	            case 'A':
	            	if(resueltoA != 1) {
	            		printf("ar_hivo \n\n");
						scanf("%s", res);
						if(strcmp(res, "c") == 0){
							printf("La respuesta es correcta\n");
							resueltoA = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;
						}								                   
					}
					break;           
	                    
	            case 'B':
	            	if (resueltoB != 1){
	            		printf("s_rpi_nt_ \n\n");
						scanf("%s", res);
						if(strcmp(res, "e") == 0){
							printf("La respuesta es correcta\n");
							resueltoB = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;		
						}							
					}
					break;
	                    
	            case 'C':
	            	if (resueltoC != 1) {
	            		printf("m_sica\n\n");
						scanf("%s", res);
						if(strcmp(res, "u") == 0) {
							printf("La respuesta es correcta\n");
							resueltoC = 1;
						}							
						else{
							printf("La respuesta es incorrecta\n");
							puntosEliminados +=10;	
						}									
					}
					break;	 
		}
            
    } while (resueltoA == 0 || resueltoB == 0 || resueltoC == 0);
        
        printf("Has superado la prueba.\n");
	
return puntosEliminados;	

}


		


	
	

	
	

	

