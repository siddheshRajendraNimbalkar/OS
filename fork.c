#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>


int main(){

    pid_t pid = fork();
    if(pid < 0){
        printf("Fork Failed\n");
        return 1;
    }else if(pid == 0){
        printf("I am Child Process and my id is::%d\n",getpid());
        printf("I am Child Process and my parent id is::%d\n",getppid());
    }else{
        printf("I am Parent Process and my id is::%d\n",getpid());

    }
    return 0;
}