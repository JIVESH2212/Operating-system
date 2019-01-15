#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
int main
{
	int fd[2],rs;
	rs=pipe(fd);
	if(rs==-1)
	{
		Perror("pipe not created:");
	}
	if(!fork())
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		excelp("ls","ls",NULL);
	}	
	
	else
	{
		close(0);
		dup(fd[0]);
		close(fd[1]);
		excelp("grep","grep","-l", NULL);
	}
	return 0;
}

