//The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
//The child process print the result and exit. The parent process wait for completion of the child and then exit.
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY 0x00001234


typedef struct msg
{
    long type;
    int sum , A , B;
}msg_t;

int main() 
{
    int ret , s , mqid;
    // create msg queue
    mqid = msgget(MQ_KEY , IPC_CREAT|0600);
    if(mqid < 0){
        perror("msgget() failed ");
        _exit(1);
    }
    ret = fork();
    if(ret == 0)
        {
        // child process -receiver 
        msg_t m1;
        m1.type = 99;

        printf("enter the two no A : \n");
        scanf("%d",&m1.A);
        printf("enter the two no B : \n");
        scanf("%d",&m1.B);

        msgsnd(mqid, &m1, sizeof(msg_t), 0);
        msgsnd(mqid, &m1, sizeof(m1.B), 0);

        printf("succesfully send the data\n");
        msgrcv(mqid, &m1, sizeof(msg_t), 33, 0);
        printf("succesfully received sum \n");
        printf("\nsum is %d\n",m1.sum);
        
    }
    else
    {
        //parent process --- sender
        msg_t m1;

        printf("\nparent : waiting for two values: \n");
        msgrcv(mqid, &m1, sizeof(msg_t), 99, 0);
        printf("parent: received - %d %d\n", m1.A,m1.B);
        // msgrcv(mqid, &m1, sizeof(m1.B), 100, 0);

        int sum = m1.A + m1.B;

        m1.type = 33;
        m1.A = sum;

        msgsnd(mqid, &m1,sizeof(msg_t) - sizeof(long), 0);
    
        waitpid(-1,&s,0);
        // destroy the message queue
        msgctl(mqid , IPC_RMID, NULL);
    
    }
    return 0;
}
