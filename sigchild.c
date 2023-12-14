#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
void handle_signal(int sig)// Handler
{
  printf("\n Inside Handler: child is terminated  %d \n",sig);
}
int main()
{
   signal(SIGCHLD,handle_signal);// Registration process
   int i=fork(), w;
 	if(i==0)
 	{
    	printf("Child process");
 	}
 	else
 	{
    	printf("Inside parent process \n");
    	wait(&w);
    	printf("End of parent process \n");
 	}
	return 0;
}

