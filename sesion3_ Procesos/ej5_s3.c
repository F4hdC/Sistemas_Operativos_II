// Sesion 3 
// Ej5
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define ERroR 1
#define Exito 0 

int crear_hijos(int nivel_maximo,int nivel_inicial,int tiempo_espera);

int main(int argc, char **argv){

    int N,T,i,j;
        
    if(argc != 3){
        fprintf(stderr,"ERroR, Se esperaban dos argumentos más\n");
        return ERroR;
    }

    N = atoi(argv[1]);
    T = atoi(argv[2]);

    if((N<1 || N>5) ||(T<1 || T>10)){
        fprintf(stderr,"ERroR,El argumento 1 debe ser argv1 ~ 5 & argv2 debe ser 1 ~ 10\n");
        return ERroR;
    }
    // Aqui empieze el programa si todo fue bien;

    crear_hijos(N,1,T);
    return Exito;

}

int crear_hijos(int nivel_maximo,int nivel_inicial,int tiempo_espera){
    int i,hijos=0;
    int status,suma=0;
    
    if(nivel_inicial==nivel_maximo){
        printf("Proceso %d, Nivel %d, Hijo %d, Suma S\n",getpid(),nivel_inicial,hijos);
        sleep(tiempo_espera);
        return ERroR;
    }
    
    for(i=1;i<=2;i++){
        hijos = fork();
        if(hijos==-1){
            fprintf(stderr,"Error");
            return ERroR;
        }else if(hijos == 0){
            nivel_inicial++;
            crear_hijos(nivel_maximo,nivel_inicial,tiempo_espera);

        }

    }
    waitpid(-1,&status,0);
    if(WIFEXITED(status))
	suma=suma+WEXITSTATUS(status);

    if (nivel_inicial>0)
	{
		printf("Proceso %d, Nivel %d, Hijo %d, Suma %d.\n",getpid(),nivel_inicial,hijos,suma);
		sleep(tiempo_espera);
		return (suma);
	}



}