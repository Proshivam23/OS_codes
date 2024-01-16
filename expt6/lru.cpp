#include<bits/stdc++.h>
using namespace std;

void access(vector<int> &pages, vector<int> &order, int page, int frames, int &fault){
    auto it = find(pages.begin(), pages.end(), page);

    if(it != pages.end()){
        pages.erase(it);
    }
    else{
        fault++
    }
    pages.push_back(page);
    if(pages.size()<= frames){
        order.push_back(page);
    }
    if(pages.size()> frames){
        auto it = find(pages.begin(), pages.end(), page[0]);
        *it = page;
        pages.erase(pages.begin());
    }
    // printing stuff
}

int main(){
    vector<int> pages;
    vector<int> order;

    int size, frames, fault;

    cout<<"Enter the number of fra,mes required: ";
    cin>>frame;

    cout<<"Enter the size of the page sequence: ";
    cin>>size;

    vector<int> sequence(size);

    cout<<"Enter the values: "<<endl;
    for(int i=0; i<size; i++){
        cin>>sequence[i];
    }

    for(int i: sequence){
        access(pages, order, i, frames, fault);
    }
}