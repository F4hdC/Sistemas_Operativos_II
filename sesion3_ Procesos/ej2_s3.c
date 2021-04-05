// Sesion 3 
// Ej2
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main(int argc, char **argv){

	int pid[7];
	int i,espera;
	int suma_retorno = 0;
	int status;

	system("clear");

	for(i=0;i<7;i++){

		pid[i] = fork();
		if(pid[i] == -1){
			fprintf(stderr," Error\n");
			perror(" ");
			exit(1);
		}
		else if(pid[i] == 0){
			
			srand(getpid());
			espera = i + rand() %5 +1;
			printf("Soy el hijo %d con el ID : %d\tEspero un Rato(%d Segundos)\n",i+1,getpid(),espera);
			sleep(espera);
			return (espera*10);
		}
		else{
		}
	}

	for(i=0; i<7;i++)
	{
		if(waitpid(pid[i], &status, 0)!=-1)
		if(WIFEXITED(status))
		if(WEXITSTATUS(status))
		{
			suma_retorno += WEXITSTATUS(status);
			printf("Retorno del proceso %d es %d\n",(i+1),WEXITSTATUS(status));
			printf("Suma de los retornos de %d procesos acumulada: %d\n",(i+1),suma_retorno);

		}else{perror(" ");}
	}

	printf("Suma de los retornos acumulada: %d\n",suma_retorno);
	return 0;

	


}