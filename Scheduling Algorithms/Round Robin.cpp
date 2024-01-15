#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct os
{
    int at;
    int id;
};
bool compare(os a,os b)
{
    if(a.at==b.at)a.id<b.id;
    else return a.at<b.at;

}


int main()
{

  int i,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],btt[10],ct[10];

  printf("Enter The Number Of Total Process:\t ");
  cin>>n;

  printf("Enter Arrival Time Of Processes:\n");
  for(i=0;i<n;i++)
  {
    printf("P[%d] :",i+1);
    cin>>at[i];
  }
  printf("Enter Burst Time Of Processes:\n");
  for(i=0;i<n;i++)
  {
    printf("P[%d] :",i+1);
    cin>>bt[i];
    btt[i]=bt[i];
  }

  printf("Enter Time Quantum:\t");
  cin>>time_quantum;

  bool ses[n+2];

  int complete=0,last=-1;

  float ava_wait=0,ava_turn=0;

  queue<int> ready_queue;
  for(time=0;complete<n;)
  {
      vector<os>que;
      for(int i=0;i<n;i++)
      {
          if(time>=at[i] and ses[i]==false)
          {
              que.push_back({at[i],i});
              ses[i]=true;
          }
      }
      sort(que.begin(),que.end(),compare);

      for(int i=0;i<que.size();i++) /// que[i].id
        ready_queue.push(que[i].id);

      if(last!=-1)ready_queue.push(last);

      if(ready_queue.empty()){time++;continue;}

      int pro=ready_queue.front();
      ready_queue.pop();
      if(time_quantum<bt[pro])
      {
          time+=time_quantum;
          bt[pro]-=time_quantum;
          last=pro;
      }
      else
      {
          time+=bt[pro];
          bt[pro]=0;
          ct[pro]=time;
          last=-1;
          complete++;
      }
  }
  printf("\n\nProcess\t|Arrival TIme\t|Burst Time\t|Comple Time\t|Turnaround Time\t|Waiting Time\n\n");
  for(int i=0;i<n;i++)
  {
      turnaround_time=ct[i]-at[i];
      wait_time=turnaround_time-btt[i];/// here bt[i]=rt[i]
      ava_turn+=turnaround_time;
      ava_wait+=wait_time;
      printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",i+1, at[i], btt[i],ct[i], turnaround_time, wait_time);
  }
  float throughput=n/(time*1.0);
  printf("\nTroughtput:%.2f",throughput);
  printf("\nAverage Waiting Time= %.3f\n",ava_wait/(n*1.0));
  printf("Avg Turnaround Time = %.3f",ava_turn/(n*1.0));

  return 0;
}
