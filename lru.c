#include<stdio.h>

int search(int F[],int frame,int page){

    for(int i=0;i<frame;i++){
        if(F[i] == page){
            return i;
        }
    }
    return -1;
}

void lru(int page[],int frame,int n){
    int F[frame];
    for(int i=0;i<frame;i++){
        F[i] = -1;
    }

    int hit = 0,fold=0,Findex;
    for(int i=0;i<n;i++){
        if(search(F,frame,page[i]) != -1){
            hit++;
        }else{
            fold++;
            F[Findex] = page[i];
            Findex++;
            if(Findex == frame+1){
                Findex = 0;
            }
        }
    }
    printf("Hit: %d, Fold: %d\n",hit,fold);
}

void main(){

    int page[] = {3, 4, 5, 4, 3, 4, 7, 2, 4, 5, 6, 7, 2, 4, 6};

    int frame;
    printf("Enter the number of frames: ");
    scanf("%d",&frame);
    int n = sizeof(page)/sizeof(page[0]);

    lru(page, frame, n);
    
}