// Sesion 3
// Ejecutor
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>


int main(int argc, char** argv){

	int S,A,T;

	if(argc<3){
	fprintf(stderr, "/Ejec: Intento de ejecución sin usar el monitor. No se puede continuar.\n");	
	return 254;	
	}


	S = atoi(argv[0]);
	A = atoi(argv[1]);

	if(A<=0 || S<=0){
		fprintf(stderr, "/Ejec: Intento de ejecución sin usar el monitor. No se puede continuar.A: %d, S: %d\n",A,S);
		return 254;
	}

	T=A+S;
	printf("/Ejec: Soy el PID: %d y me voy a dormir un %d segundos\n",getpid(),T);
	sleep(T);
	return T;
}