//From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
//processes should run concurrently for 5 seconds and cleaned up properly upon termination.



#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int i, pidb, sb, pidc, sc, pidd, sd;
    //parent a
    printf("Parent_A: pid=%d, ppid=%d\n", getpid(),getppid());
    pidb = fork();
    if(pidb == 0)
    {
        //child b
        pidc = fork();
        if(pidc == 0)
        {
            //child c
            pidd = fork();
            if(pidd == 0)
            {
                //child d
                for(i=1; i<=5;i++)
                {
                    printf("Child_D: pid= %d, ppid=%d\n", getpid(),getppid());
                    sleep(1);
                }
                    _exit(0);  
            }
            for(i=1;i<=5;i++)
            {
                printf("Child_C: pid=%d, ppid=%d\n",getpid(),getppid());
                sleep(1);
            }
            waitpid(pidd, &sd, 0);
            printf("Child_D exit status: %d\n", WEXITSTATUS(sd));
            _exit(0);
        }
        for(i=1;i<=5;i++)
        {
            printf("Child_B : pid=%d, ppid=%d\n", getpid(),getppid());
            sleep(1);
        }
        waitpid(pidc, &sc, 0);
        printf("Child_C exit status: %d\n", WEXITSTATUS(sc));
        _exit(0);
    }

    waitpid(pidb, &sb, 0);
    printf("Child_B exit status: %d\n", WEXITSTATUS(sb));

    return 0;
}

// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>

// // parent A -> child B -> child C
// int main() {
    
// int pidb , pidc , pidd ,pide ,sb ,sc , sd, se, i;
// printf("parent A : pid = %d , ppid = %d\n ",getpid(),getppid());
// pidb = fork();
// if(pidb == 0){
//     pidc = fork();
//     if(pidc == 0){
//         pidd = fork();
//         if(pidd == 0){
//             for(i = 1 ; i<=5 ;i++)
//             {
//                 printf("\nchild pid :[%d] , parent pid[%d] \n",getpid(),getppid());
//                 sleep(1);

//             }
//             _exit(1);
//         }
//         //for(i =1 ; i<= 2 ; i++){
//             printf("\nchilC pid :[%d] , parent pid[%d] \n",getpid(),getppid());
//                 sleep(1);
//         }
//         waitpid(pidd , &sd ,0);
//         printf("childD exit status : %d\n",WEXITSTATUS(sd));
//         _exit(0);
//     }
//     //for(i = 1 ; i<=3 ; i++)
//     {//
//         printf("\n chilB pid :[%d] , parent pid[%d] \n",getpid(),getppid());
//         sleep(1);
//    // }
//      waitpid(pidd , &sd ,0);
//         printf("childC exit status : %d\n",WEXITSTATUS(sc));
//         _exit(0);
// }

//     return 0;
// }


//__________________________

// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>


// int main() {
//     int i, pidb, sb, pidc, sc ,pidd, sd;

    
//     pidb = fork();
//     if(pidb == 0) { 
        
//         pidc = fork();
//         if(pidc == 0) {
//                 pidd = fork();
//                 if(pidd == 0){
//                 for(i=1; i<=5; i++) {
//                     printf("D. sunbeam karad: %d\n", i);
//                     sleep(1);
//                 }
//                 _exit(0);
//                 }
            
//             for(i=1; i<=5; i++) {
//                 printf("C. sunbeam desd: %d\n", i);
//                 sleep(1);
//             }
//             _exit(0);
//         }
        
        
//         for(i=1; i<=5; i++) {
//             printf("B. sunbeam pune: %d\n", i);
//             sleep(1);
//         }
//         waitpid(pidc, &sc, 0);
//         _exit(0);
//     }

    
//     for(i=1; i<=5; i++) {
//         printf("A. sunbeam: %d\n", i);
//         sleep(1);
//     }
//     waitpid(pidb, &sb, 0);

//     return 0;
// }