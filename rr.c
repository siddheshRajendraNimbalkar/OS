// Online C compiler to run C program online
#include <stdio.h>

struct Process{
    int id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int remaining_time;
}

calTime(struct Process p[],int n,int q){
    int currentTime = 0, TTAT = 0, TWT = 0,complite=0;

    printf("\nGantt Chat:\n");

    while(complite < n){
        int done = 0;
        for(int i =0;i<n;i++){
            if(p[i].AT <= currentTime && p[i].remaining_time >= 0){
                done = 1;
                if(p[i].remaining_time > q){
                    printf("P%d ",p[i].id);
                    currentTime += q;
                    p[i].remaining_time -= q;
                }else{
                    printf("P%d ",p[i].id);
                    currentTime += p[i].remaining_time;
                    p[i].CT = currentTime;
                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;
                    complite++;

                    TWT += p[i].WT;
                    TTAT += p[i].TAT;

                    p[i].remaining_time = 0;
                }
            }
        }

        if(done == 0){
            currentTime++;
        }
    }
    
    printf("\n");

    printf("\nProcess\tArrival Time\tBurst Time\tComplate Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n", p[i].id, p[i].AT, p[i].BT, p[i].CT,p[i].TAT, p[i].WT);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)TTAT / n);
    printf("Average Waiting Time: %.2f\n", (float)TWT / n);
}

int main() {
    
    int n,q;
    printf("Enter total number of process::");
    scanf("%d",&n);
    struct Process p[n];
    
    for(int i = 0; i < n; i++){
        p[i].id = i+1;
        printf("Enter the process AT and BT P[%d]::",i+1);
        scanf("%d%d",&p[i].AT,&p[i].BT);
        p[i].remaining_time = p[i].BT;
    }


    printf("Enter the time (quantum)::");
    scanf("%d",&q);
    
    calTime(p,n,q);
    return 0;
}
