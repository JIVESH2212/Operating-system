#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefd[2];
   int returnstatus;
   char writemessages[2][20]={"Hi", "Hello"};
   char readmessage[20];
   returnstatus = pipe(pipefd);
   
   if (returnstatus == -1) 
   {
      printf("Unable to create pipe\n");
      return 1;
   }
   
   printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
   write(pipefd[1], writemessages[0], sizeof(writemessages[0]));
   read(pipefd[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);
   
   printf("Writing to pipe - Message 2 is %s\n", writemessages[1]);
   write(pipefd[1], writemessages[1], sizeof(writemessages[1]));
   read(pipefd[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 2 is %s\n", readmessage);
   
   return 0;
}