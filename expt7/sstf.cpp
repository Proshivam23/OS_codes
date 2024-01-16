#include<bits/stdc++.h>
using namespace std;

int calseek(vector<int> &sequence, int head, int size){
    int total_seek = o;
    int current_head = head;
    vector<int> safesequence(size);

    while(!sequence.empty()){
        int min_index = -1;
        int min_seek = MAX_INT;

        for(int i=0; i<size; i++){
            int seek = abs(current_head - sequence[i]);
            if(seek<min_index){
                min_index = i;
                min_seek = seek;
            }
        }
        safesequence.push_back(sequence[min_index]);
        total_seek += min_seek;
        sequence.erase(sequence.begin + min_index);
    }

    return total_seek;
}

int main(){
    int size,head;
    cout<<"Enter the size of the sequence: ";
    cin>>size;

    vector<int> sequence(size);

    cout<<"Enter the values for the sequence: "<<endl;
    for(int i=0; i<size; i++){
        cin>>sequence[i];
    }

    cout<<"Enter the current head: ";
    cin>>head;

    int total_seek = calseek(sequence, head, size);

    return 0;
}