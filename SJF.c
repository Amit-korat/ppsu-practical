#include<stdio.h>
 int main()
{
    int bt[20],ar[20],ct[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,gc=0; float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&ar[i]);
        p[i]=i+1;
    }
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;
    printf("\nProcess\t    Arrival Time   Burst Time  Completion Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        if(ar[i]<=gc)
        {
            gc=gc+bt[i];
            ct[i]=gc;
        }
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t%d",p[i],ar[i],bt[i],ct[i],wt[i],tat[i]);
    }
    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}