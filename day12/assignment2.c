#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void sigint_handler(int signo) {
    printf("\nCaught SIGINT (Ctrl+C). Continuing the shell.\n");
}

int main() {
   
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }

   
    while (1) {
        printf("Your shell prompt: \n");
        sleep(1);  
    }

    return 0;
}
