#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
int n,i,f=1;
printf("Enter a number:");
scanf("%d",&n);
printf("Process ID of child process---executing factorial:%d\n\n",getpid());
if(n==0 || n==1){
printf("Factorial of %d is 1",n);
}
else if(n<0){
printf("Factorial doesnt exists for a negative number");
}
else{
		for(i=1;i<=n;i++){
f=f*i;
}	
printf("factorial of %d is %d",n,f);
}
}


