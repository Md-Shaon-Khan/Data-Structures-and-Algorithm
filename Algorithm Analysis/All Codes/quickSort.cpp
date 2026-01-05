#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(int arr[],int start,int end){
    int pivot = arr[end];
    int index = start - 1;

    for(int i=start;i<end;i++){
        if(arr[i] <= pivot){
            index++;
            swap(arr[index],arr[i]);
        }
    }
    swap(arr[index+1],arr[end]);

    return index+1;
}

void quickSort(int arr[],int start,int end){
    if(start<end){
        int pivotIndex = partition(arr,start,end);
        quickSort(arr,start,pivotIndex-1);
        quickSort(arr,pivotIndex+1,end);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr1[] = {60, 58, 55, 52, 49, 45, 42, 38, 35, 33, 30, 28, 25, 21, 18, 15, 12, 8, 5, 1};
    
    int n = 20;

    auto start = high_resolution_clock::now();
    quickSort(arr1,0,n-1);
    display(arr1,n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);
    cout<<duration.count();

    return 0;
}