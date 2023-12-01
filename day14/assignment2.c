//The child process send two numbers to the parent process via pipe. The parent process calculate the sum and return via another pipe. The child process
//print the result and exit. The parent process wait for completion of the child and then exit.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>



int main(){
    int ret , fd1[2],fd2[2] ,s,num1, num2 , result;
    
    ret = pipe(fd1);
    if(ret < 0){
        perror("pipe() failed \n");
        _exit(1);
    }

        ret = pipe(fd2);
    if(ret < 0){
        perror("pipe() failed \n");
        _exit(1);
    }

    ret = fork();
    if(ret == 0){
    close(fd1[0]);
    close(fd2[1]);
    printf("enter the number1 : \n");
    scanf("%d",&num1);
    printf("enter the number2 : \n");
    scanf("%d",&num2);

    write(fd1[1],&num1, sizeof(num1));
    write(fd1[1],&num2, sizeof(num2));
    printf("number send succesfully .\n");
    close(fd1[1]);

    read(fd2[0],&result,sizeof(result));
    printf("result is :%d\n", result);
    
    }
    else{
    close(fd1[1]);
    close(fd2[0]);
    int A,B ,sum;
    read(fd1[0],&num1,sizeof(num1));
    read(fd1[0],&num2,sizeof(num2));
    
    printf("\ndata received succesfully on parent\n");

    sum = num1 + num2;
    write(fd2[1],&sum, sizeof(sum));
    printf("\ndata send from parent succesfully \n");
    close(fd2[1]);
    waitpid(-1, &s, 0);
    }
    
}
