///implementation of FCFS Scheduling
#include<iostream>
using namespace std;
int main(){
    int AT[] = {0,1,5,6};
    int n = sizeof AT / sizeof AT[0];
    int  BT[] = {2,2,3,4};

    int WT[n],TAT[n],total_WT=0,total_TAT=0;
    int CT[n];///CT means Completion Time

    CT[0]=AT[0]+BT[0];
    for(int i=1;i<n;i++){
        if(CT[i-1]>AT[i])CT[i]=CT[i-1]+BT[i];
        else CT[i]=AT[i]+BT[i];
    }
    for(int i=0;i<n;i++)TAT[i]=CT[i]-AT[i];
    for(int i=0;i<n;i++)WT[i]=TAT[i]-BT[i];


    cout<<"Arrival time  "<<" Burst time  "<<" Completion time "<<" Waiting time  "<<" Turn around time"<<endl;
    for (int i=0;i<n;i++){
        total_WT = total_WT + WT[i];
        total_TAT = total_TAT + TAT[i];
        cout<<"   "<<AT[i]<<"\t\t  "<<BT[i]<<"\t\t    "<<CT[i]<<"\t  "<<"\t    "<<WT[i]<<"\t\t  "<<TAT[i]<<endl;
    }
    cout<<"Average waiting time = "<<(float)total_WT/(float)n<<endl;;
    cout<<"Average turn around time = "<<(float)total_TAT/(float)n<<endl;
    return 0;
}
