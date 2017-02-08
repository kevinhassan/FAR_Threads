#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h> 
#define NB_THREADS 10000 
int somme=0;
void * Fils(void *t) {
	int i= (long)t;	
	int tmp = somme;
	tmp ++;
	somme = tmp;
	printf("Fils %d : somme = %d \n", i, somme); 
	printf("Pid : %d \n", getpid());
	pthread_exit(0);
}

int main() {
	long i;
	pthread_t thread[NB_THREADS]; 
	for (i=0;i<NB_THREADS;i++)
		pthread_create(&thread[i], NULL, Fils, (void *)i); 
	for (i=0;i<NB_THREADS;i++) 
		pthread_join(thread[i], NULL); 
	printf("Pere : somme = %d \n", somme); 
	//printf("Pid : %d \n", getpid());
	return 0;
}