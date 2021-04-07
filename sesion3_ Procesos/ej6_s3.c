// Sesion 3 
// Ej6
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define ERroR 1
#define Exito 0 

int main(int argc, char **argv){

    int T,L,i,cont,status;
    char *ptr;
    int hijos;
    int *orden;
    char F[20];
    int randL;

    if (argc < 2){
        fprintf(stderr,"Falta de los argumentos\n");
        return ERroR;
    }

    T = strtol(argv[1],&ptr,10);
    if( *ptr != 0){
        fprintf(stderr,"Argumentos no válidos\n");
        return ERroR;
    }
    L = strtol(argv[2],&ptr,10);
    if( *ptr != 0){
        fprintf(stderr,"Argumento dos no válido\n");
        return ERroR;
    }

    if((T<3 || T>25) || (L<50)){
        fprintf(stderr,"[Rango no válido]\n");
        return ERroR;
    }

    // Aquí empieza el programa si todo fue bien 

    orden =(int*)malloc(sizeof(int)*T);

    cont = T-1;
    for(i=1;i<=T;i++){

        hijos=fork();

        if(hijos == -1){
            perror(" ");
            return ERroR;
        }else if(hijos == 0){

            srand(getpid());
            printf("/Hijo: Soy el hijo número %d y mi PID es %d\n",i,getpid());
            sleep(i);
            randL = rand() %L +1;
            return randL;
        }else{
            orden[i-1] = hijos; // Guardo el orden inverso, el primer elemento es el ultimo en en acabar
        }

    }

    for(i=0;i<T;i++){
        printf("-------------\n/Padre: Esperando que acabe el hijo número %d con PID=%d.\n-------------\n",cont+1,orden[cont]);
        waitpid(orden[cont],&status,0);

        if(WIFEXITED(status))
        if(WEXITSTATUS(status)){
            strcpy(F,"NORMAL");
        }else if(WIFSTOPPED(status)){
            strcpy(F,"INTERRUMPIDO");

        }else{
            strcpy(F,"ERROR");
        }

        printf("/Padre: Hijo con PID= %d ha terminado de forma %s, y ha devuelto el valor %d\n",orden[cont],F,WEXITSTATUS(status));	
        cont--;
        
    }
    free(orden);

}