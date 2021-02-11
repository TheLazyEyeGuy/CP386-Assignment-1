#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/wait.h>
  
// Driver code 
int main()
{
    int i;
    //loop for 3 child processes.
    for (i = 0; i < 3; i++) {
        if (fork() == 0) {
            //getpid gives the process of the child
            printf("child%d id = %d and parent id = %d\n", i + 1, getpid(), getppid());
            return (1);
        }
        wait(NULL);
    }

    //if fork doesn't return 0, it's the parent
    if (fork() != 0) {
        //parent of all children
        printf("parent id = %d\n", getpid());
    }
    return (0);

}
