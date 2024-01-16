#include<bits/stdc++.h>
using namespace std;

void access(vector<int> &pages, vector<int> &order, int page, int frames, int &fault){
    int fault_flag = 0;
    auto it = find(pages.begin(), pages.end(), page);

    if(it == pages.end()){
        fault_flag = 1;
        fault++;
        if(pages.size()>= frame){
            auto it = find(order.begin(), order.end(), pages[0]);
            *it = page;
            pages.erase(pages.begin());
        }
        if(pages.size()<frames)
            order.push_back(page);
        pages.push_back(page);
    }
    if(fault_flag == 1)
        cout<<"**********PAGE FAULT OCCURED**********"<<endl;
    cout<<"Current memory: ";
    for (int i = 0; i < frame; i++) {
        if (i < order.size()) {
            cout << setw(2) << order[i] << " "; // Format the output
        } else {
            cout << "   "; // Empty space to maintain the same width
        }
    }
    cout<<endl;
}


int main(){
    vector<int> pages;
    vector<int> order;

    int size, frames, fault = 0 ;
    cout<<"ENter number of frames: ";
    cin>>frames;

    cout<<"Enter size of page sequence: ";
    cin>>size;
    vector<int> sequence(size);

    cout<<"Enter values: "<<endl;
    for(int i=0; i<size; i++){
        cin>>sequence[i];
    }

    for(int i : sequence){
        access(pages, order, i, frames, fault);
    }

}