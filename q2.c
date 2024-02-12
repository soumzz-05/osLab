#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){

int status;
pid_t fork_return;
fork_return = fork();

if(fork_return==0){
printf("\n I'm the child!\n");
    for(int i=2;i<argc;i++)
    {
        for(int j=2;j<argc;j++)
        {
            if(strcmp(argv[j-1], argv[j]) > 0)
            {
            	char t[100];
                strcpy(t, argv[j-1]);
                t[100] = 0;
                strcpy(argv[j-1], argv[j]);
                strcpy(argv[j], t);
            }
        }
    }
    
    for(int i=1;i<argc;i++)
{
	printf("%s\n",argv[i]);
}
exit(0);
}
else{
wait(&status);
printf("\n I'm the parent!\n");
for(int i=1;i<argc;i++)
{
	printf("%s\n",argv[i]);
}
}



}
