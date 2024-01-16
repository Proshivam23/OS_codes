#include<bits/stdc++.h>
using namespace std;

void FCFS(int a[], int head, int size){
    int seek =0, distance;
    int curr;
    for(int i=0; i<size;i++){
        curr = a[i];
        distance = abs(curr - head);

        seek+=distance;

        head = curr;
    }
    cout<<"Total Seek operations = "<<seek;
    cout<<"seek sequence"<<endl;
    cout<<"head---->";
    for(int i=0; i<size; i++){
        cout<<"---->"<<a[i];
    }
}

int main(){
    int size, head;
    cout<<"Enter the size of the req array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the values for the req array: "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Enter the head position: ";
    cin>>head;

    FCFS(arr, head, size);

    return 0;
}