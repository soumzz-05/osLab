#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    int pid = fork();
    if (pid > 0)  printf("Parent process ID : %d %d\n", getpid() ,getppid());
    else if (pid == 0) printf("Child process ID: %d %d\n", getpid() ,getppid());
    else printf("Failed to create child process");
    
    return 0;
}
