
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>&arr){
    int n = arr.size();

    for(int i=0;i<n-1;i++){
        int minInx = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minInx]){
                minInx = j;
            }
        }
        swap(arr[minInx],arr[i]);
    }

}
void printArray(vector<int>arr){
    for(auto &o:arr){
        cout<< o <<" ";
    }
    cout<<endl;
}

int main(){
    vector<pair<int,int>> orders = {
        {1012,3},{1005,1},{1004,4},{1008,9},{1010,7}
    };

    vector<int>arr1;
    for(auto &o : orders){
        arr1.push_back(o.first);
    }

    auto start = high_resolution_clock::now();
    selectionSort(arr1);
    auto stop = high_resolution_clock::now();

    printArray(arr1);
    auto duration = duration_cast<nanoseconds>(stop-start);
    cout<<duration.count();

}
