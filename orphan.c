#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("ERROR OCCURE");
        return 1;
    }else if(pid == 0){
        printf("I am Child Process and my id is::%d\n",getpid());
        printf("I am Child Process and my parent id is::%d\n",getppid());
        for(int i = 0; i < 5; i++){
            sleep(2);
        }
    }else{
        printf("I am Parent Process and my id is::%d\n",getpid());
    }
    return 0;
}