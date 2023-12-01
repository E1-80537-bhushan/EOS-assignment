#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int ret ,fd , err , s;
    ret = fork();
    if(ret == 0){
        fd = open("in.txt",O_RDONLY , 0664);
        if(fd < 0){
            perror("\nopen() is failed \n");
            _exit(1);
        }
            close(0);
            dup(fd);
            close(fd);

            err = execlp("wc","wc",NULL);
            if(err < 0) {
                perror("exec() failed");
                _exit(1);
            }
        }
        else 
            waitpid(ret , &s ,0);
        printf("program completed\n");
        return 0;
    }
