// Sesion 3
// Monitor
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <string.h>

#define ERRoR 1
#define EXito 0

int main(int argc, char** argv){

	int P,S,i,A,status,pid_hijo;
	char *ptrP;
	char *ptrS;
	int pid[50];
	//char *argumentos[2];

	if(argc == 1){
		P=1;
		S=10;
	}else if(argc==2){
		P=strtol(argv[1],&ptrP,10);
		S=10;
		if(*ptrP != 0){
			fprintf(stderr,"Error en los argumentos. Se Aba un número válido\n");
			return ERRoR;
		}else{
			if(P<1 || P>50){
				fprintf(stderr, "El rango devbería ser 1 ~ 50\n");
				return ERRoR;	
			}

		}


	}else if(argc==3){

		P=strtol(argv[1],&ptrP,10);
		S=strtol(argv[2],&ptrS,10);

		if(*ptrP != 0 && *ptrS != 0){
			fprintf(stderr,"/Monit: Error en los argumentos. Se Aba un número válido en los dos argumentos\n");
			return ERRoR;
		}else{
			if((P<1 || P>50) || (S<1 || S>150)){
				fprintf(stderr, "/Monit: El rango de los argumentos debería ser arg1 =>1 ~ 50 & arg2 => 1 ~ 150\n");	
				return ERRoR;
			} 
		}

	} // empieza el funcionamiento del programa, si todo fue bien


		for(i=0;i<P;i++){

			pid[i] = fork();
			if(pid[i] == -1){
				fprintf(stderr," Error\n");
				perror(" ");
				exit(1);
			}
			else if(pid[i] == 0){
				
				srand(getpid());
				A = rand() %15 +1;

				printf("/Monit: Soy el hijo %d con el PID : %d Espero un Rato(%d Segundos)\n",i+1,getpid(),A);
				sleep(A);
				//return (A);


				// int execve(const char *filename, char *const argv[], char *const envp[]);
				//argumentos[0] = (char*)malloc(4);
				//argumentos[1] = (char*)malloc(4);

				
				sprintf(argv[0],"%d",S);
				sprintf(argv[1],"%d",A);
				if(execv("ejecutor",argv) == -1){
					perror(" ");
					return 255;
				}
			
			}
			else{
			}
	}

	for(i=0; i<P;i++)
	{	
		pid_hijo = waitpid(-1, &status, 0);  
		if(pid_hijo !=-1)
		if(WIFEXITED(status))
		if(WEXITSTATUS(status))
		{
			printf("/Monit: Retorno del proceso es: %d con el PID: %d\n",WEXITSTATUS(status),pid_hijo);

		}else{perror(" ");}
	} 


}