#include<stdio.h>

struct Process{
    int id;
    int AT;
    int BT;
    int TAT;
    int WT;
    int CT;
    int isCT;
}

calTime(struct Process p[],int n){
    int TTAT = 0, TWT = 0;
    int currentTime = 0, completed = 0;

    while(completed < n){
        int shortestJob = -1;
        int minBustTime = -1;

        for(int i = 0; i < n; i++){
            if(p[i].AT <= completed && !p[i].isCT){
                if(minBustTime == -1 || p[i].BT < minBustTime){
                    minBustTime = p[i].BT;
                    shortestJob = i;
                }
            }
        }

        if(shortestJob != -1){
            currentTime += p[shortestJob].BT;
            p[shortestJob].CT = currentTime;
            p[shortestJob].TAT = p[shortestJob].CT -p[shortestJob].AT;
            p[shortestJob].WT = p[shortestJob].TAT - p[shortestJob].BT;
            p[shortestJob].isCT =1;

            TTAT += p[shortestJob].TAT;
            TWT += p[shortestJob].WT;
            completed++;

        }else{
            currentTime++;
        }
    }

    printf("\nProcess AT BT CT TAT WT \n");
    for(int i = 0 ; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
    }

    printf("\n ToTAL TAT::%d",TTAT/n);
    printf("\n Total WT::%d",TWT/n);
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
        p[i].isCT = 0;
    }

    calTime(p,n);
    return 0;
}