#include<stdio.h>

struct Process{
    int id;
    int AT;
    int BT;
    int TAT;
    int WT;
}

calTime(struct Process p[],int n){
    int TWT = 0, TTAT = 0;
    int CT[n];

    CT[0] = p[0].AT + p[0].BT;
    p[0].WT = 0;
    p[0].TAT = p[0].BT;

    for(int i = 1; i < n; i++){
        // if there is process not to CT 
        // 1 2 4 5 
        //  Now the 1 and 2 will run but there is stell the time for 4 to run 
        
        if(p[i].AT > CT[i-1]){
            CT[i] = p[i].AT + p[i].BT;
        }
        else{
            
            CT[i] = CT[i -1] + p[i].BT;
        }

        p[i].TAT = CT[i] - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;

        TWT += p[i].WT;
        TTAT += p[i].TAT;
    }

    printf("\nProcess AT BT CT TAT WT \n");
    for(int i = 0 ; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT,p[i].BT,CT[i],p[i].TAT,p[i].WT);
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
    }

    // sorting the p[] by AT

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].AT > p[j].AT){
                struct Process temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    calTime(p,n);

    return 1;
}