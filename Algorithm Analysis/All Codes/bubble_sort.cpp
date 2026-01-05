#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>&arr){
    int n = arr.size();

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArray(vector<int>arr){
    for(auto &o:arr){
        cout<<o<<" ";
    }
    cout<<endl;
}

int main(){
    vector<pair<int,int>>arr = {
       {101,2},{100,9},{102,8},{105,1},{109,5}
    };

    vector<int>arr1;

    for(auto &o:arr){
        arr1.push_back(o.first);
    }

    auto start = high_resolution_clock::now();
    bubbleSort(arr1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);
    printArray(arr1);
    cout<<duration.count();

    return 0;
}