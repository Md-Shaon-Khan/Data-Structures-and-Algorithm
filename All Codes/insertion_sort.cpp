#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>&arr){
    int n = arr.size();
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void printArray(vector<int>arr){
    for(auto &o:arr){
        cout<< o <<" ";
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
    insertionSort(arr1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);
    printArray(arr1);
    cout<<duration.count();

}