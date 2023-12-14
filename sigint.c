#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handle_signal(int sig)// Handler
{
  printf("\n Signal Caught %d \n",sig);}
int main()
{
   signal(SIGINT,handle_signal);
   int i=0;
   while(i<30){
     printf("Hello World \n");
     sleep(1);
     i++;}
    return 0;
}

