#include<bits/stdc++.h>
using namespace std;

class process{
    int pid;
    int priority;
    int arr_time;
    int burst_time;
    int wait_time;
    int ta_time;
    int completion_time;
}


int main(){
    int num;
    cout<<"Enter number processes: ";
    cin>>num;

    process pro[num];

    cout<<"Enter arrival, burst, priority of the process: "<<endl;
    for(int i=0;i<num;i++){
        cout<<"P"<<i<<": ";
        cin>>pro[i].arr_time>>pro[i].burst_time>>pro[i].priority;
        pro[i].pid = i;
    }

    
}