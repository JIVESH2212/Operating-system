#include<stdio.h>
#include<unistd.h>
int main()
{
int ret;
ret=fork();
int a=5,b=3;
if(ret>0)
{
printf(" \n I am Parent process ");
printf("\n My Process ID is %d",getpid());
printf(" Addition by parent process  is %d",a+b); 
}
else if(ret==0)
{
printf(" \n I am Child process ");
printf("\n My Process ID is %d",getpid());
printf("\n My Parent Process ID is %d",getppid());
printf(" Multiplication by child process  is %d",a*b); 
}
else
	printf(" Fork creation Unsuccesfull ");

return(0);
}

