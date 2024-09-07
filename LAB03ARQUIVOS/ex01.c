#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
		int pid = fork();

		if(pid < 0){
			printf("\n\nErro fork!\n\n");
			exit(1);
		}
		
		if(pid == 0){
			printf("\nMeu id é %d, e eu sou processo filho! PAI: %d\n",getpid(), getppid());
			for(int i = 0; i < 5; i++){
				printf("\nSou processo filho e estou trabalhando!!\n");
				sleep(1);
			}
		}
		else{
			printf("\nMeu id é %d, e eu sou o processo pai! Meu filho é %d\n", getpid(), pid);
			wait(NULL);
		}
		
		return 0;
}
