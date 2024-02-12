#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){

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
