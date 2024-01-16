#include<bits/stdc++.h>
#define N 30
using namespace std;


bool isSafe(int n, int m, int allocated[][N], int need[][N], int available[], int safeSeq[]){
    bool fin[N];
    for(int i=0;i<n;i++){
        fin[i] = false;
        safeSeq[i] = 0;
    }
    int work[N];
    for(int i=0;i<m;i++)
        work[i] = available[i];

    int count = 0;

    while(count<n){
        bool found = false;
        for(int i=0;i<n;i++){
            if(!fin[i]){
                int j;
                for(int j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        break;
                    }
                }
                if(j==m){
                    fot(int k=0;k<m;k++)
                        work[k] += allocate[i][k];
                    safeSeq[count++] = i;
                    fin[i] = true;
                    found = true;
                }
            }
        }
        if(!found){
            cout<<"No safe sequence: "<<endl;
            return false;
        }
    }
    cout<<"In safe state"<<endl;
    return true;
}



void printmat(int x, int y, int mat[][N]){

}

void printDetails(int n, int m, int allocated[][N], int maximum[][N], int need[][N], int available[]){
    
}

int main(){

    int need[N][N], safeseq[N];

    int n, m, allocated[N][N], available[N], max[N][N];
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter number of resources: ";
    cin>>m;

    cout<<"How many instances of each resources are available: "<<endl;
    for(int i=0;i<m;i++){
        cout<<"R"<<i;
        cin>>available[i];
    }

    cout<<"Enter the maximum matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"P"<<i<<": ";
            cin>>maximum[i][j];
        }
    }

    cout<<"Enter allocated matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"P"<<i<<": ";
            cin>>allocated[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }

    printDetails(n, m, allocated, maximum, need, available);

    if(isSafe(n, m, allocated, need, available, safeSeq)){
        cout<<"Safe sequence is: ";
    }

    return 0;
}