//Find max number of child processes that can be created on Linux using C program? Hint: use fork() in inﬁnite loop (wisely).
#include<stdio.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    int ret , cnt  =0 , status;
    while(1){
        ret = fork();
        if(ret < 0){
            perror("fork() faild");
            break;

        }
        if(ret == 0){
            // child process
            sleep(10);
            _exit(0);

        }
        else {
            //parent process
            cnt++;
        }
    }
    printf("number of process created : %d\n",cnt);
    //cleanup pcb of  all child process
    while(waitpid(-1 , &status , 0)>0)
        ;
    return 0;
}
