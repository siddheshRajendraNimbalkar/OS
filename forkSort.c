#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void bubbleSort(int a[],int n){

    for(int i = 0; i < n-1; i++){
        for(int j = 1;j<n-i;j++){
            if(a[j] < a[j-1]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}

void insertionSort(int a[],int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Fork Failed\n");
        return 1;
    }else if(pid == 0){
        printf("I am Child Process and my id is::%d\n",getpid());
        printf("I am Child Process and my parent id is::%d\n",getppid());
        bubbleSort(a, n);
    }if(pid > 0){
        wait(NULL);
        printf("I am Parent Process and my id is::%d\n",getpid());
        insertionSort(a, n);
    }
}