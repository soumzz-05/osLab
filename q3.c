#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
int status;
pid_t fork_return;
pid_t f1 = fork();

if(f1 == 0){
	//child1
	printf("\nI'm the child 1!\n");
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
}
else{
	pid_t f2 = fork();
	if(f2==0){
		//child 2
		printf("\nI'm the child 2!\n");
		int min = 1;
	    for(int i=1;i<argc;i++)
	    {
		        min = i; 
		for(int j=i;j<argc;j++)
		{
		    if(strcmp(argv[min], argv[j]) > 0)
		    {
		    min = j;
		    	
		    }
		}
		char t[100];
		        strcpy(t, argv[min]);
		        t[100] = 0;
		        strcpy(argv[min], argv[i]);
		        strcpy(argv[i], t);
	    }
	    for(int i=1;i<argc;i++)
{
	printf("%s\n",argv[i]);
}
	}
	else{
		//parent
		wait(&status);
printf("\nI'm the parent!\n");
for(int i=1;i<argc;i++)
{
	printf("%s\n",argv[i]);
}
	}
}
}
