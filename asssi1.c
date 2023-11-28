#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all child processes
//to complete and clean all of them. Hint: use loop to fork() multiple child processes.
int fuc(int max){
    for(int i= 0; i<=max ; i++)
    {
        printf("getpid : [%d] , max : %d\n",getpid(),i);
        sleep(1);
    }
    
    }
int main()
{   
    int i,max =5 ,status ,ret ,pid[5];

    for(int i=0 ; i<5 ; i++){
        pid[i] = fork();
        if(pid[i] == 0){
            fuc(5);
            //sleep(5);
             _exit(1);
            }
        
    }
    fuc(5);
    for(i = 0; i<5 ; i++)
    {
        ret = waitpid(-1 ,&status , 0);
            printf("child [%d] exit status : %d\n",ret , WEXITSTATUS(status));
    }
    
    // int i, pid1, pid2, pid3, s1, s2, s3;

    // pid1 = fork();
    // if (pid1 == 0)
    // {
    //     // 1st child
    //     for (i = 1; i <= 3; i++)
    //     {
    //         printf("dac : %d\n", i);
    //         sleep(1);
    //     }
    //     _exit(0);
    // }

    // pid2 = fork();
    // if(pid2 == 0)
    // {
    //     //second child
    //     for(i=1;i<=3;i++)
    //     {
    //         printf("dmc: %d\n",i);
    //         sleep(1);
    //     }
    //     _exit(0);
    // }

    // pid3 =fork();
    // if(pid3 == 0){
    //     //3rd child
    //     for(i=1;i<=3;i++){
    //         printf("desd : %d\n",i);
    //         sleep(1);
    //     }
    //     _exit(1);
    // }

    // for(i=10;i<=5 ;i++){
    //     printf("sunbeam : %d\n",i);
    //     sleep(1);

    // }

    // waitpid(pid1 ,&s1, 0);
    // waitpid(pid2 ,&s2, 0);
    // waitpid(pid3 ,&s3, 0);

    return 0;
}