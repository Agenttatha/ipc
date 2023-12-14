#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
void *withdraw();
void *deposite();
int amount = 1; 
sem_t s;       
int main()
{
    sem_init(&s, 0, 1); 
    pthread_t thread1, thread2;
    int damount, wamount;
    printf("Enter the amount for Deposite");
    scanf("%d", &damount);
    printf("Enter the wthdraw amount");
    scanf("%d", &wamount);
    pthread_create(&thread1, NULL, withdraw, (void *)wamount);
    pthread_create(&thread2, NULL, deposite, (void *)damount);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared is %d\n", amount); 
}
void *withdraw()
{
    int x;
    sem_wait(&s); 
    x = amount;  
    printf("Thread1 reads the value as %d\n", x);
    x = x + 1000; 
    printf("Local updation by Thread1: %d\n", x);
    sleep(1);   
    amount = x; 
    printf("Value of shared variable updated by Thread1 is: %d\n", amount);
    sem_post(&s);
}
void *deposite()
{
    int y;
    sem_wait(&s);
    y = amount; 
    printf("Thread2 reads the value as %d\n", y);
    y = y - 500; 
    printf("Local updation by Thread2: %d\n", y);
    sleep(1);   
    amount = y; 
    printf("Value of shared variable updated by Thread2 is: %d\n", amount);
    sem_post(&s);
}


