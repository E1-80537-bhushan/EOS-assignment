#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int signal_num;

    // Get process ID from user
    printf("Enter the process ID: ");
    scanf("%d", &pid);

    // Get signal number from user
    printf("Enter the signal number: ");
    scanf("%d", &signal_num);

    // Send signal to the process using kill syscall
    if (kill(pid, signal_num) == 0) {
        printf("Signal %d sent to process %d successfully.\n", signal_num, pid);
    } else {
        perror("Error sending signal");
    }

    return 0;
}
