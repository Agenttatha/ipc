#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
int n,i;
printf("Enter a number:");
scanf("%d",&n);
printf("Process ID of parent process -- executing prime number program - %d\n\n",getpid());
int flag=0;
for (i=2;i<=n/2;i++){
if (n%i==0){
flag++;
break;
}
}
if(flag==0){
printf("%d is prime number\n\n",n);
}
else{
printf("%d is not a prime number\n\n",n);
}
}

