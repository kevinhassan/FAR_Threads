#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h> 
#define NB_PROCESSUS 10000	 

int pid, i, somme ;
int main()
{ 
	somme = 0 ;
	for (i=0 ; i<NB_PROCESSUS ; i++) { 
		pid=fork();
		if (pid == 0) { 
		  somme++ ;
		  printf("processus fils %d : somme = %d \n", i, somme) ;
		  printf("Pid : %d \n", getpid());
		  exit(0) ; 
		}
	}
	while ( wait(0) != -1) { } ;
	printf("processus père : somme = %d \n", somme) ; 
	printf("Pid : %d \n", getpid());
	return 0 ;
}