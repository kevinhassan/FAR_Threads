#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void traitement(){
	printf("%s","L'entier est négatif");
}

int main(void){
	int x;
	int descr [2];
	pid_t pid = fork();
	pipe(descr);
	if(pid != 0){ //Processus pere
		signal(SIGUSR1,traitement);
		scanf("%d", &x);
		close(descr[0]);
		write(descr[1],x,sizeof(int));
	}else{
		close(descr[1]);
		read(descr[0],x,sizeof(int));
		if(x<0){
			kill(getppid(),SIGUSR1);
		}else{
			printf("%p","test");
		}
	}
	return 0;
}
