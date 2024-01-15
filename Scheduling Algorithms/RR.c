#include<stdio.h>

int main(){

  int i,j,n,time,remain,flag=0,time_quantum;

  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];

  printf("Enter The Number Of Total Process:\t ");
  scanf("%d",&n);

  remain=n;
  printf("Enter Arrival Time Of Processes:\n");
  for(i=0;i<n;i++)
  {
    printf("P[%d] :",i+1);
    scanf("%d",&at[i]);
  }
  printf("Enter Burst Time Of Processes:\n");
  for(i=0;i<n;i++)
  {
    printf("P[%d] :",i+1);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }

  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);

  printf("\n\nProcess\t|Arrival TIme\t|Burst Time\t|Turnaround Time\t|Waiting Time\n\n");

  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=time_quantum && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=time_quantum;
      time+=time_quantum;
    }

    if(rt[i]==0 && flag==1)
    {
      remain--;
      wait_time+=time-at[i]-bt[i];
      turnaround_time+=time-at[i];
      printf("P[%d]\t|\t%d\t|\t%d|\t%d\t|\t%d\n",i+1, at[i], bt[i], turnaround_time, wait_time);
      flag=0;
    }

    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }

  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
