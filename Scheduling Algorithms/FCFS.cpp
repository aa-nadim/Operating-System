#include<bits/stdc++.h>
using namespace std;
struct os
{
    int at;
    int id;
};
bool compare(os a,os b)
{
    return a.at<b.at;
}


int main()
{
    int n, at[20], bt[20], ct[20], wt[20],tat[20],btt[20], i, j;
    float avwt=0, avtat=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        cin>>bt[i];
        btt[i]=bt[i];
    }
    printf("\nEnter Process Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&at[i]);
    }
    int complete=0;
    for(int time=0;complete<n;)
    {
        vector <os> que;
        for(int i=0;i<n;i++)
        {
            if(time>=at[i] and bt[i]!=0)
               que.push_back({at[i],i});
        }
        sort(que.begin(),que.end(),compare);
        //if(complete>=n)break;
        if(que.empty()){time++;continue;}
        int process_id=que.front().id;
        /// (2,1) (1,2) (3,3)
        // sort
        /// (1,2) (2,1) (3,3)

        time+=bt[process_id];// 2
        ct[process_id]=time;
        complete++;
        bt[process_id]=0;
    }



    printf("\nProcess\t\tArrival Time\tBurst Time\tcomp Time\tTurnaround Time\tWaiting Time Time");

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-btt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\n P[%d]\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t%d",i+1,at[i],btt[i],ct[i],tat[i],wt[i]);
    }

    avwt/=(n*1.0);
    avtat/=(n*1.0);

    printf("\n\nAverage Waiting Time:%.2f",avwt);
    printf("\nAverage Turnaround Time:%.2f",avtat);
    printf("\n");
    return 0;
}
