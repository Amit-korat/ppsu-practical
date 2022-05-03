#include<stdio.h>
#include<conio.h>
int main ()

{
    int tq = 2;
    int n;
    int c = 0;
    float sumtat = 0,sumwt = 0;

    printf("Enter number of process you want to enter : ");
    scanf("%d",&n);
    int bt[n],rt[n],wt[n],tat[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter burst time of process %d : ",i);
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }
    int flag;
    while(1)
    {
        flag=1;
        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 )
            {
                flag=0;
                if (rt[i] > tq)
                {
                    c = c + tq;
                    rt[i] = rt[i]-tq;
                }
                else
                {
                    c = c + rt[i];
                    wt[i] = c - bt[i];
                    rt[i] = 0;

                }
            }
        }
            if (flag==1)
            break;

    }
    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i]+bt[i];
    }
    for(int i = 0; i < n; i++)
    {
        sumtat = sumtat+tat[i];
        sumwt = sumwt+wt[i];
    }
    for(int i = 0; i < n; i++)
    {
        printf("\nwaiting time of process %d : %d",i,wt[i]);
        printf("\nturn around time of process %d : %d",i,tat[i]);
    }
    printf("\nAverage waiting time of processes : %f",(sumwt/n));
    printf("\nAverage turn around time of processes %f",(sumtat/n));

}
