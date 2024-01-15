#include<stdio.h>

int main()
{
    int i, j, n, p[20], pr[20], bt[20], wt[20], tat[20], total=0, pos, temp;
    float awt, atat;

    printf("Enter Total Number of Process: ");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority:\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);
        p[i]= i+1;
    }

    for(i=0;i<n;i++)
    {
        pos= i;
        for(j= i+1; j<n; j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;

    for(i=1; i<n; i++)
    {
        wt[i]= 0;
        for(j=0; j<i; j++)
            wt[i]= wt[i] + bt[j];
            total= total + wt[i];
    }

    awt= (total*1.0)/n;
    total= 0;

    printf("\nProcess\t     Priority\t Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0; i<n; i++)
    {
        tat[i]= bt[i]+wt[i];
        total= total + tat[i];

        printf("\nP[%d]\t\t %d\t\t %d\t\t %d\t\t %d", p[i], pr[i], bt[i], wt[i],tat[i]);
    }

    atat= (total*1.0)/n;

    printf("\n\nAverage Waiting Time=%f", awt);
    printf("\nAverage Turnaround Time=%f\n", atat);
	return 0;
}
