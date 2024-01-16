#include<iostream>
using namespace std;
class fcfs{
    public:
    int pid;
    int wait_time;
    int burst_time;
    int arr_time;
    int ta_time;
    int completion_time;

    int setdata(){
        cout<<"Enter burst time of process "<<pid<<": ";
        cin>>burst_time;

        cout<<"Enter arrival time of process "<<pid<<": ";
        cin>>arr_time;
    }
};

int sort(int n, fcfs p[]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].arr_time>p[j+1].arr_time){
                int temp;
                temp = p[j+1].arr_time;
                p[j+1].arr_time = p[j].arr_time;
                p[j].arr_time = temp;

                temp = p[j+1].burst_time;
                p[j+1].burst_time = p[j].burst_time;
                p[j].burst_time = temp;

                temp = p[j+1].pid;
                p[j+1].pid = p[j].pid;
                p[j].pid = temp;
            }
        }
    }
}

void cal_tat(int n, fcfs p[]){
    int completion = p[0].arr_time;
    for(int i=0; i<n; i++){
        completion = completion + p[i].burst_time;
        p[i].completion_time = completion;
        p[i].ta_time = completion - p[i].arr_time;
    }
}

void cal_wt(int n, fcfs p[]){
    for(int i=0; i<n; i++){
        p[i].wait_time = p[i].ta_time - p[i].burst_time;
    }
}
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    fcfs process[n];
    for(int i=0 ;i<n ;i++){
        process[i].pid = i;
        process[i].setdata();
    }

    sort(n, process);
    cal_tat(n, process);
    cal_wt(n, process);

    cout<<"Gantt Chart"<<endl;
    cout<<process[0].arr_time<<"     ";
    for(int i=0; i<n;i++){
        cout<<"|P "<<i<<"|   "<<process[i].completion_time;
        cout<<"     ";
    }
    return 0;
}