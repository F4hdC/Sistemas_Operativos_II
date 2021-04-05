// Sesion 3
// Ej3
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>


int main(int argc, char** argv){

	int i;
	int T,status;
	char *ptr;

	if(argc>1){

		T = strtol(argv[1],&ptr,10);

		if(*ptr == 0){
			if(T>=3 && T <=10){
				int hijos[T];
				for(i=1;i<=T;i++){

					hijos[i]=fork();
					if(hijos[i]== 0){
							printf("Soy el hijo número %d y mi PID es %d\n",i,getpid());				
							sleep(1);
							return i;

					}else if(hijos[i] == -1){
						fprintf(stderr, "Error al crear el hijo %d\n",i);
					}else{
						waitpid(pid[i],&status,0);
						if(WIFEXITED(status))
							if(WEXITSTATUS(status))
								printf("El hijo número %d con PID=%d ha terminado con estado %d\n",i,hijos[i],WEXITSTATUS(status));
					}


				}


			}else{
				fprintf(stderr, "El argumento deberia ser entre 3 ~ 30\n");
			}

		}else{
			fprintf(stderr, "Error de argumentos, Se esperaba un número válido\n");
		}
	}else{
				fprintf(stderr, "Se esperaba por lo menos un argumento\n");
			}

}