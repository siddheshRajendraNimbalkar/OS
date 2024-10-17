#include <stdio.h>

int search(int F[],int frame,int page){
    for(int i=0;i<frame;i++){
        if(F[i] == page){
            return i;
        }
    }
    return -1;
}

void fifo(int ref[],int n,int frame) {
    int F[frame];
    int index = 0,fould = 0,hit = 0;
    for(int i=0;i<frame;i++) {
        F[i] = -1;
    }
    for(int i=0;i<n;i++) {
        int ser = search(F,frame,ref[i]);

        if(ser != -1){
            hit++;
        }else{
            fould++;
            F[index] = ref[i];
            index++;
            if(index == frame) {
                index = 0;
            }
        }
    }

    printf("\nPage Hits: %d\nPage Faults: %d\n",hit,fould);

}

int main() {

    int ref[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n = sizeof(ref) / sizeof(ref[0]);
    int frame = 3;
    fifo(ref,n,frame);
    return 0;
}