// Sesion 3 
// Ej1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/resource.h>

void main(int argc, char **argv){

	char buf[100];
	int which = PRIO_PROCESS;
	id_t pid = getpid();
	int i;

	system("clear"); 
	printf("Datos del proceso:\n");
	printf("ID Proceso..............: %d\n",getpid());
  	printf("ID Padre................: %d\n",getppid());
  	printf("ID Usuario..............: %d\n",getuid());
  	printf("ID Usuario Efectivo.....: %d\n",geteuid());
  	printf("ID Grupo Usuarios.......: %d\n",getgid());
  	printf("ID Grupo Usr. Efectivo..: %d\n",getegid());
  	printf("ID Sesion...............: %d\n",getsid(0));
  	printf("ID Grupo Procesos.......: %d\n",getpgid(0));
  	printf("Prioridad...............: %d\n",getpriority(which,pid));
  	printf("Directorio de Trabajo...: %s\n",getcwd(buf,100));

  	printf("Argumentos:\n");
  		printf("Nombre Ejecutable: %s\n",argv[0]);
  	if(argc>0)
  	for(i=1;i<argc;i++){
  		printf("Argumento %d .....: %s\n",i,argv[i]);
  	}


}