///implementation of FCFS Scheduling
#include<iostream>
using namespace std;
int main(){
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int  burst_time[] = {9, 18, 6};

    int wating_time[n],turn_around_time[n],total_wating_time=0,total_turn_around_time=0;

    wating_time[0]=0;
    for(int i=1;i<n;i++)
        wating_time[i]=burst_time[i-1]+wating_time[i-1];

    for(int i=0;i<n;i++)
        turn_around_time[i]=burst_time[i]+wating_time[i];

    cout<<"Processes  "<<" Burst time  "<<" Waiting time  "<<" Turn around time"<<endl;
    for (int i=0;i<n;i++){
        total_wating_time = total_wating_time + wating_time[i];
        total_turn_around_time = total_turn_around_time + turn_around_time[i];
        cout<<"   "<<i+1<<"\t\t"<<burst_time[i]<<"\t    "<<wating_time[i]<<"\t\t  "<<turn_around_time[i]<<endl;
    }
    cout<<"Average waiting time = "<<(float)total_wating_time/(float)n<<endl;;
    cout<<"Average turn around time = "<<(float)total_turn_around_time/(float)n<<endl;
    return 0;
}
