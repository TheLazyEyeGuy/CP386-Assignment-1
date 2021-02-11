#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
// Driver code 
int main() 
{ 
    int child1, child2, child3; 
  
    // variable pid stores the value from the fork command 
    child1 = fork(); 
  
    // If fork() returns zero then it 
    // means it is child process. 
    if (child1 == 0) { 
  
        // This is the first child
		// getpid() gives the process of the child
        printf("child1 id = %d", getpid()); 
    } 
  
    else {
		// This creates the second child
        child2 = fork(); 
        if (child2 == 0) { 
			//this is the second child
            printf("child2 id = %d", getpid()); 
        } 
        else { 
            child3 = fork(); 
            if (child3 == 0) { 
                // This is third child
                printf("child3 id = %d", getpid()); 
            } 
  
            // If the fork does not return 0, it is the parent
            else { 
				//this is the parent of all children
                printf("parent pid = %d\n", getpid()); 
            } 
        } 
    } 
  
    return 0; 
}
