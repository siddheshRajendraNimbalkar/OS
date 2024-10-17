#include<stdio.h>

struct Process{
    int id;
    int pro;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int isCT;
    int remaining_time;
}

calTime(struct Process p[],int n){
    int q = 1;
    int currentTime = 0, completed = 0;
    int TTAT = 0, TWT = 0;

    while(completed < n){
        int SJ = -1;
        int minPro = -1;

        for(int i=0;i<n;i++){
            if(p[i].AT <= currentTime && !p[i].isCT){
                if(minPro == -1 || p[i].pro < minPro){
                    minPro = p[i].pro;
                    SJ = i;
                }
            }
        }

        if(SJ != -1){
            if(p[SJ].remaining_time <= q){
                currentTime += p[SJ].remaining_time;
                p[SJ].CT = currentTime;
                p[SJ].TAT = p[SJ].CT - p[SJ].AT;
                p[SJ].WT = p[SJ].TAT - p[SJ].BT;
                p[SJ].isCT = 1;

                completed++;

                TTAT += p[SJ].TAT;
                TWT += p[SJ].WT;
            }else{
                p[SJ].remaining_time -= q;
                currentTime += q;
            }
        }else{
            currentTime++;
        }
    }

    printf("\nPro Process AT BT CT TAT WT \n");
    for(int i = 0 ; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pro,p[i].id,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
    }

    printf("\nAverage Turnaround Time: %.2f", (float)TTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", (float)TWT / n);
}

int main(){

    int n;
    printf("Eneter The Number Of Process");
    scanf("%d",&n);
    
    struct Process p[n];
    for(int i = 0; i < n; i++){
        p[i].id = i+1;
        printf("\n Enter The AT and BT For p[%d]::",i+1);
        scanf("%d%d",&p[i].AT,&p[i].BT);
        p[i].remaining_time = p[i].BT;
        printf("Enter The Priority For p[%d]::",i+1);
        scanf("%d",&p[i].pro);
        p[i].isCT = 0;
    }

    calTime(p,n);

    return 0;
}