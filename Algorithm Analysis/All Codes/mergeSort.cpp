#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void merge(int arr[],int start,int mid,int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int left[len1];
    int right[len2];

    for(int i=0;i<len1;i++){
        left[i] = arr[start+i];
    }
    for(int j=0;j<len2;j++){
        right[j] = arr[mid+1+j];
    }
    int i = 0, j = 0, k = start;

    while(i<len1 && j<len2){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }

    while(i<len1){
        arr[k++] = left[i++];
    }
    while(j<len2){
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[],int start,int end){
    if(start >= end){
        return;
    }

    int mid = start + (end-start) / 2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
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
    mergeSort(arr1,0,n-1);
    display(arr1,n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop-start);
    cout<<duration.count();

}