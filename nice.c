#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main(){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Fork Failed\n");
        return 1;
    }else if(pid == 0){
        printf("I am Child Process and my id is::%d\n",getpid());
        printf("I am Child Process and my parent id is::%d and nice id is::%d\n",getppid(),nice(-19));
        sleep(5)
    }else{
        printf("I am Parent Process and my id is::%d\n",getpid());
        printf("I am parent nice id is::%d",nice(-19));
    }
    return 0;
}